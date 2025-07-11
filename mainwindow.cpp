#include "mainwindow.h"
#include "game_data.h"
#include <QTabWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>
#include <QTextBrowser>
#include <QLabel>
#include <QScrollArea>
#include <QCheckBox>
#include <QProgressBar>
#include <QTimer>
#include <QRegularExpression>
#include <QToolTip>
#include <QDebug>
#include <QTreeWidget>
#include <QSplitter>
#include <QTreeWidgetItem>
#include <QBrush>
#include <QHeaderView>

// Helper function implementation
GameRecipe selectBestRecipe(const QList<GameRecipe>& recipes)
{
    if (recipes.isEmpty()) {
        return GameRecipe();
    }
    
    if (recipes.size() == 1) {
        return recipes.first();
    }
    
    // Список нежелательных ингредиентов (биоматериалы и тяжелые в производстве)
    QStringList undesirableIngredients = {
        "Desc_Wood_C",          // Древесина
        "Desc_Biomass_C",       // Биомасса
        "Desc_Leaves_C",        // Листья
        "Desc_HogParts_C",      // Части кабана
        "Desc_SpitterParts_C",  // Части плевка
        "Desc_NuclearPasta_C",  // Ядерная паста (слишком сложная)
        "Desc_UraniumCell_C"    // Урановые топливные элементы
    };
    
    // Предпочитаемые здания (проще в автоматизации)
    QMap<QString, int> buildingPriority = {
        {"Конструктор", 100},
        {"Сборщик", 90},
        {"Производитель", 80},
        {"Очиститель", 70},
        {"Литейная", 60},
        {"Плавильня", 50},
        {"Ускоритель частиц", 30},
        {"Квантовый кодер", 20},
        {"Конвертер", 10}
    };
    
    GameRecipe bestRecipe = recipes.first();
    double bestScore = -1000.0;
    
    for (const auto& recipe : recipes) {
        double score = 0.0;
        
        // Штраф за альтернативные рецепты (предпочитаем стандартные)
        if (recipe.name.contains("альт", Qt::CaseInsensitive) || 
            recipe.className.contains("Alternate", Qt::CaseInsensitive)) {
            score -= 50.0;
        }
        
        // Сильный штраф за нежелательные ингредиенты
        for (const auto& ingredient : recipe.ingredients) {
            if (undesirableIngredients.contains(ingredient.itemClass)) {
                score -= 100.0; // Почти исключаем такие рецепты
            }
        }
        
        // Бонус за предпочитаемые здания
        if (buildingPriority.contains(recipe.building)) {
            score += buildingPriority[recipe.building];
        }
        
        // Штраф за сложность рецепта (количество ингредиентов)
        score -= recipe.ingredients.size() * 5.0;
        
        // Бонус за эффективность производства
        double totalOutput = 0.0;
        for (const auto& product : recipe.products) {
            totalOutput += product.amount * (60.0 / recipe.time);
        }
        
        double totalInput = 0.0;
        for (const auto& ingredient : recipe.ingredients) {
            totalInput += ingredient.amount * (60.0 / recipe.time);
        }
        
        double efficiency = (totalInput > 0) ? (totalOutput / totalInput) : 0.0;
        score += efficiency * 20.0;
        
        // Предпочитаем более быстрые рецепты
        score += (60.0 / recipe.time) * 2.0;
        
        if (score > bestScore) {
            bestScore = score;
            bestRecipe = recipe;
        }
    }
    
    return bestRecipe;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), m_loadingProgressBar(nullptr), m_loadingLabel(nullptr), 
      m_loadingTimer(nullptr), m_loadingWidget(nullptr), m_recipesLoaded(false), 
      m_currentRecipeIndex(0)
{
    GameData::instance(); // Инициализация данных игры
    setupUi();
    setupConnections();
    populateComboBoxes();
    applyStyles();
}

MainWindow::~MainWindow()
{
}

void MainWindow::setupUi()
{
    m_tabWidget = new QTabWidget();

    // Lift Tab
    m_liftTab = new QWidget();
    QVBoxLayout *liftLayout = new QVBoxLayout(m_liftTab);
    liftLayout->setSpacing(20);
    liftLayout->setContentsMargins(25, 25, 25, 25);
    
    QHBoxLayout *liftInputLayout = new QHBoxLayout();
    liftInputLayout->setSpacing(15);

    QLabel *liftLabel = new QLabel("Выберите фазу:");
    liftLabel->setStyleSheet("font-weight: bold; font-size: 14px; color: #e0e0e0;");
    m_liftPhaseCombo = new QComboBox();
    m_liftPhaseCombo->setMinimumWidth(250);
    m_liftCalculateButton = new QPushButton("Рассчитать");
    m_liftCalculateButton->setMinimumSize(120, 35);
    m_liftCalculateButton->setStyleSheet(
        "QPushButton {"
        "    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #238636, stop:1 #196127);"
        "    border: 2px solid rgba(35, 134, 54, 0.8);"
        "    border-radius: 8px;"
        "    color: white;"
        "    font-weight: 600;"
        "    font-size: 14px;"
        "    padding: 2px;"
        "    box-shadow: 0 2px 8px rgba(35, 134, 54, 0.3);"
        "}"
        "QPushButton:hover {"
        "    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #2ea043, stop:1 #238636);"
        "    border-color: #2ea043;"
        "    box-shadow: 0 4px 12px rgba(46, 160, 67, 0.4);"
        "    transform: translateY(-1px);"
        "}"
        "QPushButton:pressed {"
        "    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #196127, stop:1 #0d1117);"
        "    border-color: #196127;"
        "    box-shadow: 0 1px 4px rgba(35, 134, 54, 0.3);"
        "    transform: translateY(1px);"
        "}"
    );
    
    m_liftResultOutput = new QTextBrowser();
    m_liftResultOutput->setMinimumHeight(400);
    m_liftResultOutput->setStyleSheet(
        "QTextBrowser {"
        "    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgba(22, 27, 34, 0.95), stop:1 rgba(13, 17, 23, 0.95));"
        "    border: 2px solid rgba(48, 54, 61, 0.6);"
        "    border-radius: 12px;"
        "    padding: 20px;"
        "    font-family: 'JetBrains Mono', 'Fira Code', 'Consolas', 'Monaco', monospace;"
        "    font-size: 13px;"
        "    line-height: 1.6;"
        "    color: #f0f6fc;"
        "    selection-background-color: rgba(88, 166, 255, 0.3);"
        "}"
        "QTextBrowser:focus {"
        "    border-color: rgba(88, 166, 255, 0.7);"
        "    box-shadow: 0 0 0 3px rgba(88, 166, 255, 0.1);"
        "}"
    );

    liftInputLayout->addWidget(liftLabel);
    liftInputLayout->addWidget(m_liftPhaseCombo, 1);
    liftInputLayout->addWidget(m_liftCalculateButton);
    liftLayout->addLayout(liftInputLayout);
    
    // Custom production inputs for lift
    QLabel *customInputsLabel = new QLabel("⚙️ Настройка производства (предметов в минуту):");
    customInputsLabel->setStyleSheet("color: #58a6ff; font-weight: 600; font-size: 14px; margin-top: 10px;");
    customInputsLabel->setToolTip(
        "Здесь вы можете настроить желаемую скорость производства для каждого предмета.\n"
        "Введите количество предметов в минуту, которое вы хотите производить.\n"
        "Это повлияет на расчеты количества машин и сырых ресурсов."
    );
    liftLayout->addWidget(customInputsLabel);
    
    m_liftInputsScrollArea = new QScrollArea();
    m_liftInputsScrollArea->setWidgetResizable(true);
    m_liftInputsScrollArea->setMinimumHeight(100);
    m_liftInputsScrollArea->setMaximumHeight(300); // Увеличиваем до 300px
    m_liftInputsScrollArea->setStyleSheet(
        "QScrollArea {"
        "    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgba(33, 38, 45, 0.9), stop:1 rgba(22, 27, 34, 0.9));"
        "    border: 2px solid rgba(48, 54, 61, 0.6);"
        "    border-radius: 8px;"
        "    padding: 8px;"
        "}"
        "QScrollBar:vertical {"
        "    background: rgba(33, 38, 45, 0.8);"
        "    width: 12px;"
        "    border-radius: 6px;"
        "}"
        "QScrollBar::handle:vertical {"
        "    background: rgba(88, 166, 255, 0.6);"
        "    border-radius: 6px;"
        "    min-height: 20px;"
        "}"
        "QScrollBar::handle:vertical:hover {"
        "    background: rgba(88, 166, 255, 0.8);"
        "}"
    );
    
    m_liftCustomInputsWidget = new QWidget();
    m_liftInputsLayout = new QVBoxLayout(m_liftCustomInputsWidget);
    m_liftInputsLayout->setSpacing(8);
    m_liftInputsLayout->setContentsMargins(10, 10, 10, 10);
    
    m_liftInputsScrollArea->setWidget(m_liftCustomInputsWidget);
    liftLayout->addWidget(m_liftInputsScrollArea);
    
    m_treeWidgetResults = new QTreeWidget();
    m_treeWidgetResults->setColumnCount(3);
    m_treeWidgetResults->setHeaderLabels({"Компонент", "Кол-во/мин", "Здания"});
    m_treeWidgetResults->header()->setSectionResizeMode(QHeaderView::ResizeToContents);
    m_treeWidgetResults->setStyleSheet(
        "QTreeWidget {background: #313244; color: #cdd6f4; border: 1px solid #45475a; border-radius: 8px;}"
        "QTreeWidget::item {padding: 4px 2px;}"
        "QTreeWidget::item:selected {background: #45475a; color: #89b4fa;}"
    );

    QSplitter *liftSplitter = new QSplitter(Qt::Horizontal);
    liftSplitter->addWidget(m_treeWidgetResults);
    liftSplitter->addWidget(m_liftResultOutput);
    liftSplitter->setStretchFactor(0, 1);
    liftSplitter->setStretchFactor(1, 1);
    liftLayout->addWidget(liftSplitter);
    
    // Hub Tab
    m_hubTab = new QWidget();
    QVBoxLayout *hubLayout = new QVBoxLayout(m_hubTab);
    hubLayout->setSpacing(20);
    hubLayout->setContentsMargins(25, 25, 25, 25);
    
    QHBoxLayout *hubInputLayout = new QHBoxLayout();
    hubInputLayout->setSpacing(15);

    QLabel *hubLabel = new QLabel("Выберите улучшение:");
    hubLabel->setStyleSheet("font-weight: bold; font-size: 14px; color: #e0e0e0;");
    m_hubTierCombo = new QComboBox();
    m_hubTierCombo->setMinimumWidth(300);
    m_hubCalculateButton = new QPushButton("Рассчитать");
    m_hubCalculateButton->setMinimumSize(120, 35);
    m_hubCalculateButton->setStyleSheet(m_liftCalculateButton->styleSheet());
    
    m_hubResultOutput = new QTextBrowser();
    m_hubResultOutput->setMinimumHeight(400);
    m_hubResultOutput->setStyleSheet(m_liftResultOutput->styleSheet());

    hubInputLayout->addWidget(hubLabel);
    hubInputLayout->addWidget(m_hubTierCombo, 1);
    hubInputLayout->addWidget(m_hubCalculateButton);
    hubLayout->addLayout(hubInputLayout);
    
    // Custom production inputs for hub
    QLabel *hubCustomInputsLabel = new QLabel("⚙️ Настройка производства (предметов в минуту):");
    hubCustomInputsLabel->setStyleSheet("color: #58a6ff; font-weight: 600; font-size: 14px; margin-top: 10px;");
    hubCustomInputsLabel->setToolTip(
        "Здесь вы можете настроить желаемую скорость производства для каждого предмета.\n"
        "Введите количество предметов в минуту, которое вы хотите производить.\n"
        "Это повлияет на расчеты количества машин и сырых ресурсов."
    );
    hubLayout->addWidget(hubCustomInputsLabel);
    
    m_hubInputsScrollArea = new QScrollArea();
    m_hubInputsScrollArea->setWidgetResizable(true);
    m_hubInputsScrollArea->setMinimumHeight(100);
    m_hubInputsScrollArea->setMaximumHeight(300);
    m_hubInputsScrollArea->setStyleSheet(
        "QScrollArea {"
        "    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgba(33, 38, 45, 0.9), stop:1 rgba(22, 27, 34, 0.9));"
        "    border: 2px solid rgba(48, 54, 61, 0.6);"
        "    border-radius: 8px;"
        "    padding: 8px;"
        "}"
        "QScrollBar:vertical {"
        "    background: rgba(33, 38, 45, 0.8);"
        "    width: 12px;"
        "    border-radius: 6px;"
        "}"
        "QScrollBar::handle:vertical {"
        "    background: rgba(88, 166, 255, 0.6);"
        "    border-radius: 6px;"
        "    min-height: 20px;"
        "}"
        "QScrollBar::handle:vertical:hover {"
        "    background: rgba(88, 166, 255, 0.8);"
        "}"
    );
    
    m_hubCustomInputsWidget = new QWidget();
    m_hubInputsLayout = new QVBoxLayout(m_hubCustomInputsWidget);
    m_hubInputsLayout->setSpacing(8);
    m_hubInputsLayout->setContentsMargins(10, 10, 10, 10);
    
    m_hubInputsScrollArea->setWidget(m_hubCustomInputsWidget);
    hubLayout->addWidget(m_hubInputsScrollArea);
    
    hubLayout->addWidget(m_hubResultOutput);

    // === HUB TAB: после создания m_hubResultOutput и перед hubLayout->addWidget(m_hubResultOutput) ===
    m_treeWidgetHubResults = new QTreeWidget();
    m_treeWidgetHubResults->setColumnCount(3);
    m_treeWidgetHubResults->setHeaderLabels({"Компонент", "Кол-во/мин", "Здания"});
    m_treeWidgetHubResults->header()->setSectionResizeMode(QHeaderView::ResizeToContents);
    m_treeWidgetHubResults->setStyleSheet(m_treeWidgetResults->styleSheet());

    QSplitter *hubSplitter = new QSplitter(Qt::Horizontal);
    hubSplitter->addWidget(m_treeWidgetHubResults);
    hubSplitter->addWidget(m_hubResultOutput);
    hubSplitter->setStretchFactor(0,1);
    hubSplitter->setStretchFactor(1,1);

    hubLayout->addWidget(hubSplitter);
    // удалить прежнее hubLayout->addWidget(m_hubResultOutput);

    // Custom Tab
    m_customTab = new QWidget();
    QVBoxLayout *customLayout = new QVBoxLayout(m_customTab);
    customLayout->setSpacing(20);
    customLayout->setContentsMargins(25, 25, 25, 25);
    
    QHBoxLayout *customInputLayout = new QHBoxLayout();
    customInputLayout->setSpacing(15);

    QLabel *customItemLabel = new QLabel("Предмет:");
    customItemLabel->setStyleSheet("font-weight: bold; font-size: 14px; color: #e0e0e0;");
    m_customItemCombo = new QComboBox();
    m_customItemCombo->setMinimumWidth(200);
    
    QLabel *customAmountLabel = new QLabel("Количество/мин:");
    customAmountLabel->setStyleSheet("font-weight: bold; font-size: 14px; color: #e0e0e0;");
    m_customAmountInput = new QLineEdit();
    m_customAmountInput->setPlaceholderText("Введите количество в минуту");
    m_customAmountInput->setMinimumWidth(180);
    m_customAmountInput->setStyleSheet(
        "QLineEdit {"
        "    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgba(33, 38, 45, 0.9), stop:1 rgba(22, 27, 34, 0.9));"
        "    border: 2px solid rgba(48, 54, 61, 0.8);"
        "    border-radius: 8px;"
        "    padding: 10px 16px;"
        "    font-size: 13px;"
        "    font-weight: 500;"
        "    color: #f0f6fc;"
        "}"
        "QLineEdit:focus {"
        "    border-color: #58a6ff;"
        "    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgba(56, 139, 253, 0.15), stop:1 rgba(33, 38, 45, 0.9));"
        "    box-shadow: 0 0 0 3px rgba(88, 166, 255, 0.2);"
        "}"
        "QLineEdit:hover {"
        "    border-color: rgba(88, 166, 255, 0.6);"
        "    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgba(56, 139, 253, 0.1), stop:1 rgba(33, 38, 45, 0.9));"
        "}"
    );
    
    m_calculateCustomButton = new QPushButton("Рассчитать");
    m_calculateCustomButton->setMinimumSize(120, 35);
    m_calculateCustomButton->setStyleSheet(m_liftCalculateButton->styleSheet());

    m_customResultOutput = new QTextBrowser();
    m_customResultOutput->setMinimumHeight(400);
    m_customResultOutput->setStyleSheet(m_liftResultOutput->styleSheet());

    customInputLayout->addWidget(customItemLabel);
    customInputLayout->addWidget(m_customItemCombo, 1);
    customInputLayout->addWidget(customAmountLabel);
    customInputLayout->addWidget(m_customAmountInput);
    customInputLayout->addWidget(m_calculateCustomButton);
    customLayout->addLayout(customInputLayout);
    customLayout->addWidget(m_customResultOutput);

    // === CUSTOM TAB: после создания m_customResultOutput и перед customLayout->addWidget(m_customResultOutput) ===
    m_treeWidgetCustomResults = new QTreeWidget();
    m_treeWidgetCustomResults->setColumnCount(3);
    m_treeWidgetCustomResults->setHeaderLabels({"Компонент", "Кол-во/мин", "Здания"});
    m_treeWidgetCustomResults->header()->setSectionResizeMode(QHeaderView::ResizeToContents);
    m_treeWidgetCustomResults->setStyleSheet(m_treeWidgetResults->styleSheet());

    QSplitter *customSplitter = new QSplitter(Qt::Horizontal);
    customSplitter->addWidget(m_treeWidgetCustomResults);
    customSplitter->addWidget(m_customResultOutput);
    customSplitter->setStretchFactor(0,1);
    customSplitter->setStretchFactor(1,1);

    customLayout->addWidget(customSplitter);
    // удалить прежнее customLayout->addWidget(m_customResultOutput);

    // Alternate Recipes Tab
    setupAlternateRecipesTab();

    // Style ComboBoxes
    QString comboStyle = 
        "QComboBox {"
        "    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgba(33, 38, 45, 0.9), stop:1 rgba(22, 27, 34, 0.9));"
        "    border: 2px solid rgba(48, 54, 61, 0.8);"
        "    border-radius: 8px;"
        "    padding: 10px 16px;"
        "    font-size: 13px;"
        "    font-weight: 500;"
        "    color: #f0f6fc;"
        "    min-height: 22px;"
        "}"
        "QComboBox:hover {"
        "    border-color: #58a6ff;"
        "    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgba(56, 139, 253, 0.1), stop:1 rgba(33, 38, 45, 0.9));"
        "    box-shadow: 0 0 0 3px rgba(88, 166, 255, 0.1);"
        "}"
        "QComboBox:focus {"
        "    border-color: #58a6ff;"
        "    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgba(56, 139, 253, 0.15), stop:1 rgba(33, 38, 45, 0.9));"
        "    box-shadow: 0 0 0 3px rgba(88, 166, 255, 0.2);"
        "}"
        "QComboBox::drop-down {"
        "    border: none;"
        "    width: 32px;"
        "    background: transparent;"
        "}"
        "QComboBox::down-arrow {"
        "    image: none;"
        "    border-left: 6px solid transparent;"
        "    border-right: 6px solid transparent;"
        "    border-top: 8px solid #f0f6fc;"
        "    margin-right: 16px;"
        "}"
        "QComboBox::down-arrow:hover {"
        "    border-top-color: #58a6ff;"
        "}"
        "QComboBox QAbstractItemView {"
        "    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgba(33, 38, 45, 0.95), stop:1 rgba(22, 27, 34, 0.95));"
        "    border: 2px solid rgba(88, 166, 255, 0.5);"
        "    border-radius: 8px;"
        "    selection-background-color: rgba(88, 166, 255, 0.3);"
        "    color: #f0f6fc;"
        "    font-size: 13px;"
        "    padding: 4px;"
        "}"
        "QComboBox QAbstractItemView::item {"
        "    padding: 8px 12px;"
        "    border-radius: 4px;"
        "    margin: 2px;"
        "}"
        "QComboBox QAbstractItemView::item:hover {"
        "    background: rgba(88, 166, 255, 0.2);"
        "}"
        "QComboBox QAbstractItemView::item:selected {"
        "    background: rgba(88, 166, 255, 0.4);"
        "}";
    
    m_liftPhaseCombo->setStyleSheet(comboStyle);
    m_hubTierCombo->setStyleSheet(comboStyle);
    m_customItemCombo->setStyleSheet(comboStyle);

    // Add tabs with icons
    m_tabWidget->addTab(m_liftTab, "🚀 Космический Лифт");
    m_tabWidget->addTab(m_hubTab, "🏭 Улучшения ХАБа");
    m_tabWidget->addTab(m_customTab, "⚙️ Произвольный расчет");
    m_tabWidget->addTab(m_alternateTab, "🔧 Альтернативные рецепты");

    // Style tab widget
    m_tabWidget->setStyleSheet(
        "QTabWidget::pane {"
        "    border: 1px solid rgba(48, 54, 61, 0.8);"
        "    border-radius: 12px;"
        "    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgba(33, 38, 45, 0.95), stop:1 rgba(22, 27, 34, 0.95));"
        "    margin-top: 8px;"
        "}"
        "QTabBar::tab {"
        "    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgba(48, 54, 61, 0.8), stop:1 rgba(33, 38, 45, 0.8));"
        "    border: 1px solid rgba(48, 54, 61, 0.6);"
        "    border-bottom: none;"
        "    border-top-left-radius: 8px;"
        "    border-top-right-radius: 8px;"
        "    padding: 14px 24px;"
        "    margin-right: 3px;"
        "    font-size: 14px;"
        "    font-weight: 600;"
        "    color: rgba(240, 246, 252, 0.7);"
        "    min-width: 120px;"
        "}"
        "QTabBar::tab:selected {"
        "    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #58a6ff, stop:1 #388bfd);"
        "    color: white;"
        "    border-color: #58a6ff;"
        "    box-shadow: 0 2px 8px rgba(88, 166, 255, 0.3);"
        "}"
        "QTabBar::tab:hover:!selected {"
        "    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgba(88, 166, 255, 0.2), stop:1 rgba(56, 139, 253, 0.2));"
        "    color: rgba(240, 246, 252, 0.9);"
        "    border-color: rgba(88, 166, 255, 0.5);"
        "}"
    );

    setCentralWidget(m_tabWidget);
    setWindowTitle("Satisfactory Калькулятор - Полное издание");
    setWindowIcon(QIcon(":/icon.png")); // If you have an icon
    resize(1000, 700);
    setMinimumSize(800, 600);
}

void MainWindow::setupConnections()
{
    connect(m_liftCalculateButton, &QPushButton::clicked, this, &MainWindow::calculateLift);
    connect(m_hubCalculateButton, &QPushButton::clicked, this, &MainWindow::calculateHub);
    connect(m_calculateCustomButton, &QPushButton::clicked, this, &MainWindow::calculateCustom);
    
    // Alternate recipes tab connections
    connect(m_resetAlternatesButton, &QPushButton::clicked, this, &MainWindow::resetAlternateRecipes);
    connect(m_applyAlternatesButton, &QPushButton::clicked, this, &MainWindow::applyAlternateRecipes);
    
    // Search and filter connections for alternate recipes
    connect(m_searchInput, &QLineEdit::textChanged, this, &MainWindow::filterRecipes);
    connect(m_categoryFilter, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::filterRecipes);
    
    // Tab change connection
    connect(m_tabWidget, &QTabWidget::currentChanged, this, &MainWindow::onTabChanged);
    
    // Phase and tier change connections
    connect(m_liftPhaseCombo, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::onLiftPhaseChanged);
    connect(m_hubTierCombo, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::onHubTierChanged);
}

void MainWindow::populateComboBoxes()
{
    // Космический Лифт
    const auto& liftPhases = GameData::instance().getElevatorPhaseRequirements();
    QStringList phaseNames = {
        "Фаза 1 - Распределительная платформа",
        "Фаза 2 - Строительный док", 
        "Фаза 3 - Основной корпус",
        "Фаза 4 - Двигательная установка",
        "Фаза 5 - Сборка"
    };
    
    for (auto it = liftPhases.constBegin(); it != liftPhases.constEnd(); ++it) {
        int phase = it.key();
        if (phase <= phaseNames.size()) {
            m_liftPhaseCombo->addItem(phaseNames[phase - 1], phase);
        }
    }

    // Улучшения ХАБа - создаю осмысленные названия для всех milestone'ов
    const auto& hubTiers = GameData::instance().getHubUpgradeRequirements();
    QMap<int, QString> hubNames = {
        // Tier 0 - Onboarding
        {1, "ХАБ Улучшение 1 - Первые шаги"},
        {2, "ХАБ Улучшение 2 - Медные изделия"},
        {3, "ХАБ Улучшение 3 - Основы автоматизации"},
        {4, "ХАБ Улучшение 4 - Конвейеры"},
        {5, "ХАБ Улучшение 5 - Добыча"},
        {6, "ХАБ Улучшение 6 - Космический Лифт"},
        
        // Tier 1
        {11, "Уровень 1 - Строительство базы"},
        {12, "Уровень 1 - Логистика"},
        {13, "Уровень 1 - Полевые исследования"},
        
        // Tier 2
        {21, "Уровень 2 - Сборка деталей"},
        {22, "Уровень 2 - Расчистка препятствий"},
        {23, "Уровень 2 - Батуты"},
        {24, "Уровень 2 - Программа AWESOME"},
        {25, "Уровень 2 - Логистика Mk.2"},
        
        // Tier 3
        {31, "Уровень 3 - Угольная энергетика"},
        {32, "Уровень 3 - Наземный транспорт"},
        {33, "Уровень 3 - Производство стали"},
        {34, "Уровень 3 - Улучшенная защита"},
        
        // Tier 4  
        {41, "Уровень 4 - FICSIT Чертежи"},
        {42, "Уровень 4 - Логистика Mk.3"},
        {43, "Уровень 4 - Продвинутая сталь"},
        {44, "Уровень 4 - Энергетическая инфраструктура"},
        {45, "Уровень 4 - Гипертрубы"},
        
        // Tier 5
        {51, "Уровень 5 - Реактивный ранец"},
        {52, "Уровень 5 - Переработка нефти"},
        {53, "Уровень 5 - Логистика Mk.4"},
        {54, "Уровень 5 - Упаковка жидкостей"},
        {55, "Уровень 5 - Нефтяная энергетика"},
        
        // Tier 6
        {61, "Уровень 6 - Промышленное производство"},
        {62, "Уровень 6 - Железнодорожный транспорт"},
        {63, "Уровень 6 - Железнодорожная сигнализация"},
        {64, "Уровень 6 - Трубопроводы Mk.2"},
        {65, "Уровень 6 - FICSIT Чертежи Mk.2"},
        
        // Tier 7
        {71, "Уровень 7 - Переработка бокситов"},
        {72, "Уровень 7 - Ховерпак"},
        {73, "Уровень 7 - Логистика Mk.5"},
        {74, "Уровень 7 - Костюм химзащиты"},
        {75, "Уровень 7 - Системы управления"},
        
        // Tier 8
        {81, "Уровень 8 - Авиационная техника"},
        {82, "Уровень 8 - Ядерная энергетика"},
        {83, "Уровень 8 - Продвинутый алюминий"},
        {84, "Уровень 8 - Передовое производство"},
        {85, "Уровень 8 - Обогащение частиц"},
        
        // Tier 9
        {91, "Уровень 9 - Преобразование материи"},
        {92, "Уровень 9 - Квантовое кодирование"},
        {93, "Уровень 9 - FICSIT Чертежи Mk.3"},
        {94, "Уровень 9 - Регуляция пространственной энергии"},
        {95, "Уровень 9 - Пиковая эффективность"}
    };
    
    for (auto it = hubTiers.constBegin(); it != hubTiers.constEnd(); ++it) {
        int tier = it.key();
        QString name = hubNames.value(tier, QString("Улучшение %1").arg(tier));
        m_hubTierCombo->addItem(name, tier);
    }

    // Произвольный расчет
    const auto& items = GameData::instance().getItems();
    for (auto it = items.constBegin(); it != items.constEnd(); ++it) {
        // Добавляем только предметы, у которых есть рецепт
        if (GameData::instance().hasRecipeForItem(it.key())) {
            m_customItemCombo->addItem(it.value().name, it.key());
        }
    }
    m_customItemCombo->model()->sort(0);
    
    // Setup initial lift custom inputs
    if (m_liftPhaseCombo->count() > 0) {
        setupLiftCustomInputs(m_liftPhaseCombo->itemData(0).toInt());
    }
    
    // Setup initial hub custom inputs
    if (m_hubTierCombo->count() > 0) {
        setupHubCustomInputs(m_hubTierCombo->itemData(0).toInt());
    }
}

void MainWindow::applyStyles()
{
    QString globalStyle = 
        "QMainWindow {"
        "    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #1a1a1a, stop:1 #0d1117);"
        "    color: #f0f6fc;"
        "}"
        "QWidget {"
        "    background-color: transparent;"
        "    color: #f0f6fc;"
        "    font-family: 'Segoe UI', 'Inter', 'System UI', sans-serif;"
        "    font-size: 13px;"
        "    font-weight: 400;"
        "}";
    
    this->setStyleSheet(globalStyle);

    // Улучшенная палитра для тултипов
    QPalette toolTipPalette;
    toolTipPalette.setColor(QPalette::ToolTipBase, QColor(33, 38, 45));
    toolTipPalette.setColor(QPalette::ToolTipText, QColor(240, 246, 252));
    QToolTip::setPalette(toolTipPalette);
}

void MainWindow::setupAlternateRecipesTab()
{
    m_alternateTab = new QWidget();
    QVBoxLayout *mainLayout = new QVBoxLayout(m_alternateTab);
    mainLayout->setSpacing(20);
    mainLayout->setContentsMargins(25, 25, 25, 25);
    
    // Header
    QLabel *headerLabel = new QLabel(
        "<h2 style='color: #4CAF50; margin: 0;'>🔧 Управление альтернативными рецептами</h2>"
        "<p style='color: #b0b0b0; margin: 5px 0 15px 0;'>Выберите альтернативные рецепты для использования в расчетах. "
        "Включенные рецепты будут использоваться вместо стандартных.</p>"
    );
    headerLabel->setWordWrap(true);
    mainLayout->addWidget(headerLabel);
    
    // Поиск и фильтрация
    QHBoxLayout *searchLayout = new QHBoxLayout();
    
    QLabel *searchLabel = new QLabel("🔍 Поиск:");
    searchLabel->setStyleSheet("color: #e0e0e0; font-weight: bold;");
    
    m_searchInput = new QLineEdit();
    m_searchInput->setPlaceholderText("Введите название рецепта или предмета...");
    m_searchInput->setStyleSheet(
        "QLineEdit {"
        "    background-color: #3a3a3a;"
        "    border: 2px solid #555;"
        "    border-radius: 6px;"
        "    padding: 8px 12px;"
        "    font-size: 13px;"
        "    color: #f0f0f0;"
        "}"
        "QLineEdit:focus {"
        "    border-color: #4CAF50;"
        "    background-color: #404040;"
        "}"
    );
    
    QLabel *categoryLabel = new QLabel("📂 Категория:");
    categoryLabel->setStyleSheet("color: #e0e0e0; font-weight: bold;");
    
    m_categoryFilter = new QComboBox();
    m_categoryFilter->addItem("Все категории", "");
    m_categoryFilter->addItem("⚙️ Слитки и основы", "ingots");
    m_categoryFilter->addItem("🔧 Базовые детали", "basic_parts");
    m_categoryFilter->addItem("🔌 Электроника", "electronics");
    m_categoryFilter->addItem("🏭 Промышленность", "industrial");
    m_categoryFilter->addItem("🧪 Жидкости", "fluids");
    m_categoryFilter->addItem("☢️ Ядерные", "nuclear");
    m_categoryFilter->addItem("🚀 Продвинутые", "advanced");
    m_categoryFilter->setStyleSheet(
        "QComboBox {"
        "    background-color: #3a3a3a;"
        "    border: 2px solid #555;"
        "    border-radius: 6px;"
        "    padding: 8px 12px;"
        "    font-size: 13px;"
        "    color: #f0f0f0;"
        "    min-height: 20px;"
        "}"
        "QComboBox:hover {"
        "    border-color: #4CAF50;"
        "    background-color: #404040;"
        "}"
        "QComboBox::drop-down {"
        "    border: none;"
        "    width: 30px;"
        "}"
        "QComboBox::down-arrow {"
        "    image: none;"
        "    border-left: 5px solid transparent;"
        "    border-right: 5px solid transparent;"
        "    border-top: 6px solid #f0f0f0;"
        "    margin-right: 12px;"
        "}"
        "QComboBox QAbstractItemView {"
        "    background-color: #3a3a3a;"
        "    border: 1px solid #555;"
        "    selection-background-color: #4CAF50;"
        "    color: #f0f0f0;"
        "    font-size: 13px;"
        "}"
    );
    
    searchLayout->addWidget(searchLabel);
    searchLayout->addWidget(m_searchInput, 2);
    searchLayout->addWidget(categoryLabel);
    searchLayout->addWidget(m_categoryFilter, 1);
    mainLayout->addLayout(searchLayout);
    
    // Control buttons
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    
    m_resetAlternatesButton = new QPushButton("🔄 Сбросить все");
    m_resetAlternatesButton->setMinimumSize(120, 35);
    m_resetAlternatesButton->setStyleSheet(
        "QPushButton {"
        "    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #f44336, stop:1 #d32f2f);"
        "    border: none;"
        "    border-radius: 6px;"
        "    color: white;"
        "    font-weight: bold;"
        "    font-size: 14px;"
        "}"
        "QPushButton:hover {"
        "    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #e53935, stop:1 #c62828);"
        "}"
        "QPushButton:pressed {"
        "    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #d32f2f, stop:1 #b71c1c);"
        "}"
    );
    
    m_applyAlternatesButton = new QPushButton("✅ Применить изменения");
    m_applyAlternatesButton->setMinimumSize(150, 35);
    m_applyAlternatesButton->setStyleSheet(
        "QPushButton {"
        "    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #4CAF50, stop:1 #45a049);"
        "    border: none;"
        "    border-radius: 6px;"
        "    color: white;"
        "    font-weight: bold;"
        "    font-size: 14px;"
        "}"
        "QPushButton:hover {"
        "    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #5CBF60, stop:1 #4CAF50);"
        "}"
        "QPushButton:pressed {"
        "    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #45a049, stop:1 #3d8b40);"
        "}"
    );
    
    buttonLayout->addWidget(m_resetAlternatesButton);
    buttonLayout->addStretch();
    buttonLayout->addWidget(m_applyAlternatesButton);
    mainLayout->addLayout(buttonLayout);
    
    // Scroll area for recipes
    m_alternateScrollArea = new QScrollArea();
    m_alternateScrollArea->setWidgetResizable(true);
    m_alternateScrollArea->setMinimumHeight(400);
    m_alternateScrollArea->setStyleSheet(
        "QScrollArea {"
        "    background-color: #2a2a2a;"
        "    border: 1px solid #555;"
        "    border-radius: 8px;"
        "}"
        "QScrollBar:vertical {"
        "    background: #3a3a3a;"
        "    width: 12px;"
        "    border-radius: 6px;"
        "}"
        "QScrollBar::handle:vertical {"
        "    background: #555;"
        "    border-radius: 6px;"
        "    min-height: 20px;"
        "}"
        "QScrollBar::handle:vertical:hover {"
        "    background: #666;"
        "}"
    );
    
    m_alternateContentWidget = new QWidget();
    m_alternateLayout = new QVBoxLayout(m_alternateContentWidget);
    m_alternateLayout->setSpacing(15);
    m_alternateLayout->setContentsMargins(15, 15, 15, 15);
    
    m_alternateScrollArea->setWidget(m_alternateContentWidget);
    mainLayout->addWidget(m_alternateScrollArea);
    
    // Создаем виджет загрузки
    m_loadingWidget = new QWidget();
    QVBoxLayout* loadingLayout = new QVBoxLayout(m_loadingWidget);
    loadingLayout->setAlignment(Qt::AlignCenter);
    loadingLayout->setSpacing(20);
    
    m_loadingLabel = new QLabel("🔄 Загружаются альтернативные рецепты...");
    m_loadingLabel->setAlignment(Qt::AlignCenter);
    m_loadingLabel->setStyleSheet(
        "QLabel {"
        "    color: #e0e0e0;"
        "    font-size: 16px;"
        "    font-weight: bold;"
        "}"
    );
    
    m_loadingProgressBar = new QProgressBar();
    m_loadingProgressBar->setMinimum(0);
    m_loadingProgressBar->setMaximum(113); // Всего 113 рецептов
    m_loadingProgressBar->setValue(0);
    m_loadingProgressBar->setStyleSheet(
        "QProgressBar {"
        "    border: 2px solid #555;"
        "    border-radius: 8px;"
        "    text-align: center;"
        "    color: white;"
        "    font-weight: bold;"
        "    background-color: #3a3a3a;"
        "    min-height: 20px;"
        "}"
        "QProgressBar::chunk {"
        "    background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #4CAF50, stop:1 #45a049);"
        "    border-radius: 6px;"
        "    margin: 2px;"
        "}"
    );
    
    loadingLayout->addWidget(m_loadingLabel);
    loadingLayout->addWidget(m_loadingProgressBar);
    
    // Скрываем виджет загрузки изначально 
    m_loadingWidget->hide();
    m_alternateLayout->addWidget(m_loadingWidget);
    
    // Создаем таймер для ленивой загрузки
    m_loadingTimer = new QTimer(this);
    connect(m_loadingTimer, &QTimer::timeout, this, &MainWindow::loadNextRecipeBatch);
    
    // НЕ загружаем рецепты сразу - они будут загружены при открытии вкладки
}

void MainWindow::populateAlternateRecipes()
{
    const auto& gameData = GameData::instance();
    
    // Собираем все альтернативные рецепты, группируя по предметам
    QMap<QString, QList<GameRecipe>> alternatesByItem;
    
    // Получаем все предметы и их рецепты
    const auto& items = gameData.getItems();
    for (auto itemIt = items.constBegin(); itemIt != items.constEnd(); ++itemIt) {
        QString itemClass = itemIt.key();
        if (gameData.hasRecipeForItem(itemClass)) {
            auto recipes = gameData.getRecipesForItem(itemClass);
            
            // Ищем альтернативные рецепты
            QList<GameRecipe> alternates;
            for (const auto& recipe : recipes) {
                if (recipe.name.contains("альт", Qt::CaseInsensitive) || 
                    recipe.className.contains("Alternate", Qt::CaseInsensitive)) {
                    alternates.append(recipe);
                }
            }
            
            if (!alternates.isEmpty()) {
                alternatesByItem[itemClass] = alternates;
            }
        }
    }
    
    // Создаем UI для каждого предмета с альтернативами
    for (auto it = alternatesByItem.constBegin(); it != alternatesByItem.constEnd(); ++it) {
        QString itemClass = it.key();
        const auto& alternates = it.value();
        
        // Контейнер для группы рецептов
        QWidget *groupWidget = new QWidget();
        QVBoxLayout *groupLayout = new QVBoxLayout(groupWidget);
        groupLayout->setSpacing(10);
        groupLayout->setContentsMargins(15, 15, 15, 15);
        
        groupWidget->setStyleSheet(
            "QWidget {"
            "    background-color: #353535;"
            "    border: 1px solid #555;"
            "    border-radius: 8px;"
            "}"
        );
        
        // Заголовок предмета
        QString itemName = gameData.getItemName(itemClass);
        QLabel *itemLabel = new QLabel(QString(
            "<h3 style='color: #4CAF50; margin: 0;'>%1</h3>"
            "<p style='color: #888; margin: 5px 0 10px 0; font-size: 11px;'>%2</p>"
        ).arg(itemName).arg(itemClass));
        itemLabel->setWordWrap(true);
        groupLayout->addWidget(itemLabel);
        
        // Альтернативные рецепты для этого предмета
        for (const auto& recipe : alternates) {
            QCheckBox *checkBox = new QCheckBox();
            checkBox->setObjectName(recipe.className); // Сохраняем ID рецепта
            checkBox->setProperty("itemClass", itemClass); // Сохраняем класс предмета
            
            // Формируем описание рецепта
            QString ingredientsList;
            for (const auto& ingredient : recipe.ingredients) {
                if (!ingredientsList.isEmpty()) ingredientsList += ", ";
                ingredientsList += QString("%1 ×%2").arg(gameData.getItemName(ingredient.itemClass)).arg(ingredient.amount);
            }
            
            QString productsList;
            for (const auto& product : recipe.products) {
                if (!productsList.isEmpty()) productsList += ", ";
                productsList += QString("%1 ×%2").arg(gameData.getItemName(product.itemClass)).arg(product.amount);
            }
            
                         QString checkboxText = QString(
                 "%1\n"
                 "🏭 %2 | ⏱️ %.1f сек\n"
                 "📥 %3\n"
                 "📤 %4"
             ).arg(recipe.name)
              .arg(recipe.building)
              .arg(recipe.time)
              .arg(ingredientsList)
              .arg(productsList);
            
            checkBox->setText(checkboxText);
            checkBox->setStyleSheet(
                "QCheckBox {"
                "    color: #f0f0f0;"
                "    font-size: 13px;"
                "    spacing: 8px;"
                "}"
                "QCheckBox::indicator {"
                "    width: 18px;"
                "    height: 18px;"
                "    border: 2px solid #666;"
                "    border-radius: 4px;"
                "    background-color: #3a3a3a;"
                "}"
                "QCheckBox::indicator:checked {"
                "    background-color: #4CAF50;"
                "    border-color: #4CAF50;"
                "    image: url(data:image/svg+xml;base64,PHN2ZyB3aWR0aD0iMTIiIGhlaWdodD0iMTIiIHZpZXdCb3g9IjAgMCAxMiAxMiIgZmlsbD0ibm9uZSIgeG1sbnM9Imh0dHA6Ly93d3cudzMub3JnLzIwMDAvc3ZnIj4KPHBhdGggZD0iTTEwIDNMNC41IDguNUwyIDYiIHN0cm9rZT0iI2ZmZiIgc3Ryb2tlLXdpZHRoPSIyIiBzdHJva2UtbGluZWNhcD0icm91bmQiIHN0cm9rZS1saW5lam9pbj0icm91bmQiLz4KPC9zdmc+);"
                "}"
                "QCheckBox::indicator:hover {"
                "    border-color: #4CAF50;"
                "    background-color: #404040;"
                "}"
            );
            
            groupLayout->addWidget(checkBox);
        }
        
        m_alternateLayout->addWidget(groupWidget);
    }
    
    // Добавляем spacer в конец
    m_alternateLayout->addStretch();
}

void MainWindow::resetAlternateRecipes()
{
    // Очищаем выбранные альтернативные рецепты
    m_selectedAlternateRecipes.clear();
    
    // Снимаем все галочки
    QList<QCheckBox*> checkboxes = m_alternateContentWidget->findChildren<QCheckBox*>();
    for (QCheckBox* checkbox : checkboxes) {
        checkbox->setChecked(false);
    }
    
    // Очищаем кэш для пересчета
    clearCalculationCache();
}

void MainWindow::applyAlternateRecipes()
{
    // Собираем выбранные альтернативные рецепты
    m_selectedAlternateRecipes.clear();
    
    QList<QCheckBox*> checkboxes = m_alternateContentWidget->findChildren<QCheckBox*>();
    for (QCheckBox* checkbox : checkboxes) {
        if (checkbox->isChecked()) {
            QString itemClass = checkbox->property("itemClass").toString();
            QString recipeClassName = checkbox->objectName();
            
            // Для одного предмета может быть выбран только один альтернативный рецепт
            m_selectedAlternateRecipes[itemClass] = recipeClassName;
        }
    }
    
    // Очищаем кэш для пересчета с новыми рецептами
    clearCalculationCache();
    
    // Показываем сообщение об успешном применении
    QString message = QString("Применено %1 альтернативных рецептов").arg(m_selectedAlternateRecipes.size());
    // Можно добавить statusBar()->showMessage(message, 3000); если есть статус-бар
}

GameRecipe MainWindow::getBestRecipeForItem(const QString& itemClass) const
{
    const auto& gameData = GameData::instance();
    
    if (!gameData.hasRecipeForItem(itemClass)) {
        return GameRecipe(); // Пустой рецепт для сырых ресурсов
    }
    
    auto recipes = gameData.getRecipesForItem(itemClass);
    if (recipes.isEmpty()) {
        return GameRecipe();
    }
    
    // Проверяем, есть ли выбранный альтернативный рецепт для этого предмета
    if (m_selectedAlternateRecipes.contains(itemClass)) {
        QString selectedRecipeClassName = m_selectedAlternateRecipes[itemClass];
        
        // Ищем рецепт по className
        for (const auto& recipe : recipes) {
            if (recipe.className == selectedRecipeClassName) {
                return recipe;
            }
        }
    }
    
    // Если альтернативный не выбран, используем стандартный алгоритм
    return selectBestRecipe(recipes);
}

void MainWindow::setupLiftCustomInputs(int phase)
{
    // Очищаем предыдущие поля ввода
    QLayoutItem* item;
    while ((item = m_liftInputsLayout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }
    m_liftProductionInputs.clear();
    
    const auto& requirements = GameData::instance().getElevatorPhaseRequirements().value(phase);
    if (requirements.isEmpty()) return;
    
    // Создаем поля ввода для каждого требуемого предмета
    for (const auto& req : requirements) {
        QWidget *inputWidget = new QWidget();
        QHBoxLayout *inputLayout = new QHBoxLayout(inputWidget);
        inputLayout->setContentsMargins(0, 0, 0, 0);
        inputLayout->setSpacing(10);
        
        // Название предмета
        QLabel *itemLabel = new QLabel(GameData::instance().getItemName(req.itemClass));
        itemLabel->setMinimumWidth(180);
        itemLabel->setStyleSheet("color: #58a6ff; font-weight: 600; font-size: 13px;");
        
        // Требуемое количество
        QLabel *requiredLabel = new QLabel(QString("Нужно: %1 шт.").arg(req.amount));
        requiredLabel->setMinimumWidth(90);
        requiredLabel->setStyleSheet("color: #ffd700; font-weight: 500; font-size: 12px;");
        
        // Стрелка
        QLabel *arrowLabel = new QLabel("→");
        arrowLabel->setStyleSheet("color: #2ea043; font-weight: bold; font-size: 14px;");
        
        // Поле ввода для производства в минуту
        QLineEdit *rateInput = new QLineEdit();
        rateInput->setPlaceholderText("в мин.");
        rateInput->setMinimumWidth(70);
        rateInput->setMaximumWidth(90);
        rateInput->setText(QString::number(qMax(1.0, req.amount / 60.0), 'f', 2));
        rateInput->setStyleSheet(
            "QLineEdit {"
            "    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgba(33, 38, 45, 0.9), stop:1 rgba(22, 27, 34, 0.9));"
            "    border: 2px solid rgba(48, 54, 61, 0.8);"
            "    border-radius: 6px;"
            "    padding: 6px 10px;"
            "    font-size: 12px;"
            "    font-weight: 500;"
            "    color: #f0f6fc;"
            "}"
            "QLineEdit:focus {"
            "    border-color: #58a6ff;"
            "    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgba(56, 139, 253, 0.15), stop:1 rgba(33, 38, 45, 0.9));"
            "    box-shadow: 0 0 0 2px rgba(88, 166, 255, 0.2);"
            "}"
            "QLineEdit:hover {"
            "    border-color: rgba(88, 166, 255, 0.6);"
            "    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgba(56, 139, 253, 0.1), stop:1 rgba(33, 38, 45, 0.9));"
            "}"
        );
        
        QLabel *unitLabel = new QLabel("/мин");
        unitLabel->setStyleSheet("color: rgba(240, 246, 252, 0.7); font-size: 12px;");
        
        inputLayout->addWidget(itemLabel);
        inputLayout->addWidget(requiredLabel);
        inputLayout->addWidget(arrowLabel);
        inputLayout->addWidget(rateInput);
        inputLayout->addWidget(unitLabel);
        inputLayout->addStretch();
        
        // Стиль для контейнера
        inputWidget->setStyleSheet(
            "QWidget {"
            "    background: linear-gradient(135deg, rgba(88, 166, 255, 0.05), rgba(22, 27, 34, 0.3));"
            "    border: 1px solid rgba(88, 166, 255, 0.2);"
            "    border-radius: 8px;"
            "    padding: 10px 12px;"
            "    margin: 4px 0;"
            "}"
            "QWidget:hover {"
            "    background: linear-gradient(135deg, rgba(88, 166, 255, 0.1), rgba(22, 27, 34, 0.4));"
            "    border-color: rgba(88, 166, 255, 0.4);"
            "}"
        );
        
        m_liftInputsLayout->addWidget(inputWidget);
        m_liftProductionInputs[req.itemClass] = rateInput;
    }
    
    // Добавляем spacer
    m_liftInputsLayout->addStretch();
    
    // Автоматически подстраиваем высоту scroll area под количество элементов
    int itemCount = requirements.size();
    int itemHeight = 50; // Примерная высота одного элемента
    int totalHeight = itemCount * itemHeight + 40; // +40 для отступов
    
    // Ограничиваем минимальную и максимальную высоту
    totalHeight = qMax(100, qMin(totalHeight, 350));
    m_liftInputsScrollArea->setFixedHeight(totalHeight);
}

void MainWindow::onLiftPhaseChanged()
{
    int phase = m_liftPhaseCombo->currentData().toInt();
    setupLiftCustomInputs(phase);
}

void MainWindow::calculateLift()
{
    // Очищаем кэш перед новым расчетом
    clearCalculationCache();
    
    m_tempCalculationSteps.clear();
    int phase = m_liftPhaseCombo->currentData().toInt();
    const auto& requirements = GameData::instance().getElevatorPhaseRequirements().value(phase);

    QMap<QString, double> totalRaw;
    QString resultText = QString(
        "<div style='"
        "background: linear-gradient(135deg, #238636, #196127, #0d1117); "
        "padding: 20px; "
        "border-radius: 12px; "
        "margin-bottom: 24px; "
        "box-shadow: 0 4px 16px rgba(35, 134, 54, 0.3); "
        "border: 2px solid rgba(35, 134, 54, 0.5);"
        "'>"
        "<h2 style='margin: 0; color: white; text-align: center; font-size: 22px; font-weight: 700; text-shadow: 0 2px 4px rgba(0,0,0,0.3);'>"
        "🚀 Космический Лифт - Фаза %1"
        "</h2>"
        "</div>"
        "<div style='"
        "background: linear-gradient(135deg, rgba(35, 134, 54, 0.1), rgba(22, 27, 34, 0.8)); "
        "padding: 18px; "
        "border-radius: 12px; "
        "border: 2px solid rgba(35, 134, 54, 0.3); "
        "margin-bottom: 20px; "
        "box-shadow: 0 2px 12px rgba(0, 0, 0, 0.1);"
        "'>"
        "<h3 style='color: #2ea043; margin-top: 0; font-size: 18px; font-weight: 600; margin-bottom: 16px;'>📋 Цели фазы:</h3>"
    ).arg(phase);

    // Обновляем левое дерево
    m_treeWidgetResults->clear();
    for (const auto &req : requirements) {
        double productionRate = qMax(1.0, req.amount / 60.0);
        QTreeWidgetItem *root = new QTreeWidgetItem(m_treeWidgetResults);
        root->setText(0, GameData::instance().getItemName(req.itemClass));
        root->setText(1, QString::number(productionRate, 'f', 2));
        root->setText(2, "Цель");
        buildTree(req.itemClass, productionRate, root, 0);
        root->setExpanded(true);
    }

    // Для космического лифта считаем как производство единичных предметов
    for (const auto& req : requirements) {
        resultText += QString("<p style='margin: 5px 0; font-size: 14px;'>• <span style='color: #87CEEB;'>%1</span>: <span style='color: #FFD700; font-weight: bold;'>%2 шт.</span></p>")
                      .arg(GameData::instance().getItemName(req.itemClass))
                      .arg(req.amount);
        
        // Получаем пользовательскую скорость производства или используем значение по умолчанию
        double productionRate = qMax(1.0, req.amount / 60.0); // значение по умолчанию
        
        if (m_liftProductionInputs.contains(req.itemClass)) {
            QLineEdit* input = m_liftProductionInputs[req.itemClass];
            bool ok;
            double customRate = input->text().toDouble(&ok);
            if (ok && customRate > 0) {
                productionRate = customRate;
            }
        }
        
        m_tempCalculationSteps.append(QString(
            "<div style='margin: 12px 0; padding: 12px; background: linear-gradient(90deg, rgba(76,175,80,0.2), rgba(76,175,80,0.05)); border-left: 4px solid #4CAF50; border-radius: 6px;'>"
            "<span style='color: #4CAF50; font-weight: bold; font-size: 16px;'>🎯 ЦЕЛЬ:</span> "
            "<span style='color: #87CEEB; font-weight: bold;'>%1</span> - "
            "<span style='color: #FFD700; font-weight: bold;'>%2 шт.</span> "
            "<span style='color: #4CAF50;'>(%3/мин производство)</span>"
            "</div>"
        ).arg(GameData::instance().getItemName(req.itemClass)).arg(req.amount).arg(QString::number(productionRate, 'f', 2)));
        
        calculateRequirements(req.itemClass, productionRate, totalRaw);
        m_tempCalculationSteps.append("<div style='border-bottom: 2px solid #444; margin: 20px 0; opacity: 0.6;'></div>");
    }
    
    resultText += "</div>";
    resultText += "<div style='"
    "background: linear-gradient(135deg, rgba(255, 152, 0, 0.1), rgba(22, 27, 34, 0.9)); "
    "padding: 20px; "
    "border-radius: 12px; "
    "border: 2px solid rgba(255, 152, 0, 0.3); "
    "margin-bottom: 20px; "
    "box-shadow: 0 2px 12px rgba(0, 0, 0, 0.15);"
    "'>";
    resultText += "<h3 style='color: #ff9500; margin-top: 0; font-size: 18px; font-weight: 600; margin-bottom: 16px;'>🔧 Детальный расчет производства:</h3>";
    resultText += "<div style='font-family: \"JetBrains Mono\", \"Fira Code\", monospace; line-height: 1.7; font-size: 13px;'>";
    resultText += m_tempCalculationSteps.join("");
    resultText += "</div>";
    resultText += "</div>";
    
    QString summaryHtml = "<div style='background: linear-gradient(135deg, rgba(255, 123, 114, 0.1), rgba(22, 27, 34, 0.9)); padding: 20px; border-radius: 12px; border: 2px solid rgba(255, 123, 114, 0.3); box-shadow: 0 2px 12px rgba(0, 0, 0, 0.15);'>";
    summaryHtml += "<h3 style='color: #ff7b72; margin-top: 0; font-size: 18px; font-weight: 600; margin-bottom: 16px;'>⛏️ Итого сырых ресурсов (в минуту):</h3>";
    summaryHtml += "<p style='color: rgba(240, 246, 252, 0.7); margin: 5px 0 15px 0; font-size: 12px;'>Потребление ресурсов в минуту для поддержания заданной скорости производства</p>";
    for (auto it = totalRaw.constBegin(); it != totalRaw.constEnd(); ++it) {
        summaryHtml += QString(
            "<div style='margin: 8px 0; padding: 12px 16px; background: linear-gradient(90deg, rgba(255, 123, 114, 0.05), rgba(22, 27, 34, 0.3)); border-left: 4px solid #ff7b72; border-radius: 8px;'>"
            "<span style='color: #58a6ff; font-weight: 600; font-size: 14px; margin-right: 8px;'>🔸</span>"
            "<span style='color: #f0f6fc; font-weight: 500;'>%1</span>"
            "<span style='color: rgba(240, 246, 252, 0.6); margin: 0 8px;'>:</span>"
            "<span style='color: #ffd700; font-weight: bold; font-size: 15px;'>%2/мин</span>"
            "</div>")
            .arg(GameData::instance().getItemName(it.key()))
            .arg(QString::number(it.value(), 'f', 2));
    }
    summaryHtml += "</div>";

    m_liftResultOutput->setHtml(summaryHtml);
    // Skip displaying detailed steps
    return; // end function early
}

void MainWindow::calculateHub()
{
    // Очищаем кэш перед новым расчетом
    clearCalculationCache();
    
    m_tempCalculationSteps.clear();
    int tier = m_hubTierCombo->currentData().toInt();
    const auto& requirements = GameData::instance().getHubUpgradeRequirements().value(tier);

    QString tierName = m_hubTierCombo->currentText();
    QMap<QString, double> totalRaw;
    
    QString resultText = QString(
        "<div style='background: linear-gradient(135deg, #FF9800, #F57C00); padding: 15px; border-radius: 8px; margin-bottom: 20px;'>"
        "<h2 style='margin: 0; color: white; text-align: center;'>🏭 %1</h2>"
        "</div>"
        "<div style='background: #2a2a2a; padding: 15px; border-radius: 8px; border-left: 4px solid #FF9800; margin-bottom: 15px;'>"
        "<h3 style='color: #FF9800; margin-top: 0;'>📋 Требования для улучшения:</h3>"
    ).arg(tierName);
    
    for (const auto& req : requirements) {
        resultText += QString("<p style='margin: 5px 0; font-size: 14px;'>• <span style='color: #87CEEB;'>%1</span>: <span style='color: #FFD700; font-weight: bold;'>%2 шт.</span></p>")
                      .arg(GameData::instance().getItemName(req.itemClass))
                      .arg(req.amount);
        
        // Получаем пользовательскую скорость производства или используем значение по умолчанию
        double productionRate = qMax(1.0, req.amount / 60.0); // значение по умолчанию
        
        if (m_hubProductionInputs.contains(req.itemClass)) {
            QLineEdit* input = m_hubProductionInputs[req.itemClass];
            bool ok;
            double customRate = input->text().toDouble(&ok);
            if (ok && customRate > 0) {
                productionRate = customRate;
            }
        }
        
        // Добавляем цель в расчеты
        m_tempCalculationSteps.append(QString(
            "<div style='margin-bottom: 16px; padding: 16px; background: rgba(88, 166, 255, 0.1); border: 2px solid rgba(88, 166, 255, 0.2); border-radius: 12px;'>"
            "<h3 style='color: #58a6ff; margin: 0; font-size: 16px; font-weight: 600;'>🎯 Цель: %1</h3>"
            "<p style='color: rgba(240, 246, 252, 0.8); margin: 6px 0 0 0; font-size: 13px;'>Производство <b style='color: #ffd700;'>%2/мин</b>"
            " | <span title='Требуется для лифта'>Фаза: %3 шт.</span>"
            " | <span title='Общее время производства'>⏱️ %4 мин (%5 ч)</span></p>"
            "</div>"
        ).arg(GameData::instance().getItemName(req.itemClass))
         .arg(QString::number(productionRate, 'f', 2))
         .arg(req.amount)
         .arg(QString::number(req.amount / productionRate, 'f', 1))
         .arg(QString::number((req.amount / productionRate) / 60.0, 'f', 2)));
        
        // Рассчитываем для этого требования
        QMap<QString, double> itemRaw;
        calculateRequirements(req.itemClass, productionRate, itemRaw);
        
        // Накапливаем потребление ресурсов в минуту
        for (auto it = itemRaw.constBegin(); it != itemRaw.constEnd(); ++it) {
            totalRaw[it.key()] += it.value();
        }
        
        m_tempCalculationSteps.append("<div style='border-bottom: 2px solid #444; margin: 20px 0; opacity: 0.6;'></div>");
    }
    
    resultText += "</div>";
    
    resultText += "<div style='"
    "background: linear-gradient(135deg, rgba(255, 152, 0, 0.1), rgba(22, 27, 34, 0.9)); "
    "padding: 20px; "
    "border-radius: 12px; "
    "border: 2px solid rgba(255, 152, 0, 0.3); "
    "margin-bottom: 20px; "
    "box-shadow: 0 2px 12px rgba(0, 0, 0, 0.15);"
    "'>";
    resultText += "<h3 style='color: #ff9500; margin-top: 0; font-size: 18px; font-weight: 600; margin-bottom: 16px;'>🔧 Детальный расчет производства:</h3>";
    resultText += "<div style='font-family: \"JetBrains Mono\", \"Fira Code\", monospace; line-height: 1.7; font-size: 13px;'>";
    resultText += m_tempCalculationSteps.join("");
    resultText += "</div>";
    resultText += "</div>";
    
    // Формируем только сводку ресурсов
    QString summaryHtml = "<div style='background: linear-gradient(135deg, rgba(255, 123, 114, 0.1), rgba(22, 27, 34, 0.9)); padding: 20px; border-radius: 12px; border: 2px solid rgba(255, 123, 114, 0.3); box-shadow: 0 2px 12px rgba(0, 0, 0, 0.15);'>";
    summaryHtml += "<h3 style='color: #ff7b72; margin-top: 0; font-size: 18px; font-weight: 600; margin-bottom: 16px;'>⛏️ Итого сырых ресурсов:</h3>";
    summaryHtml += "<p style='color: rgba(240, 246, 252, 0.7); margin: 5px 0 15px 0; font-size: 12px;'>Общее количество для производства всех требований улучшения</p>";
    for (auto it = totalRaw.constBegin(); it != totalRaw.constEnd(); ++it) {
        summaryHtml += QString("<div style='margin: 8px 0; padding: 12px 16px; background: linear-gradient(90deg, rgba(255, 123, 114, 0.05), rgba(22, 27, 34, 0.3)); border-left: 4px solid #ff7b72; border-radius: 8px;'><span style='color: #58a6ff; font-weight: 600; font-size: 14px; margin-right: 8px;'>🔸</span><span style='color: #f0f6fc; font-weight: 500;'>%1</span><span style='color: rgba(240, 246, 252, 0.6); margin: 0 8px;'>:</span><span style='color: #ffd700; font-weight: bold; font-size: 15px;'>%2 шт.</span></div>")
                .arg(GameData::instance().getItemName(it.key()))
                .arg(QString::number(it.value(), 'f', 0));
    }
    summaryHtml += "</div>";

    m_hubResultOutput->setHtml(summaryHtml);

    // --- В calculateHub(), прямо перед строкой 'QString summaryHtml =' добавляю ---
    m_treeWidgetHubResults->clear();
    for (const auto &req : requirements) {
        double productionRate = qMax(1.0, req.amount / 60.0);
        QTreeWidgetItem *rootHub = new QTreeWidgetItem(m_treeWidgetHubResults);
        rootHub->setText(0, GameData::instance().getItemName(req.itemClass));
        rootHub->setText(1, QString::number(productionRate,'f',2));
        rootHub->setText(2, "Цель");
        buildTree(req.itemClass, productionRate, rootHub, 0);
        rootHub->setExpanded(true);
    }
}

void MainWindow::calculateCustom()
{
    // Очищаем кэш перед новым расчетом
    clearCalculationCache();
    
    m_tempCalculationSteps.clear();
    QString itemClass = m_customItemCombo->currentData().toString();
    QString itemName = m_customItemCombo->currentText();
    double amount = m_customAmountInput->text().toDouble();

    if (amount <= 0) {
        QString errorText = 
            "<div style='background: linear-gradient(135deg, #f44336, #d32f2f); padding: 15px; border-radius: 8px; text-align: center;'>"
            "<h3 style='margin: 0; color: white;'>❌ Ошибка ввода</h3>"
            "<p style='margin: 10px 0 0 0; color: white;'>Пожалуйста, введите корректное количество в минуту (больше 0)</p>"
            "</div>";
        m_customResultOutput->setHtml(errorText);
        return;
    }

    QMap<QString, double> totalRaw;
    
    QString resultText = QString(
        "<div style='background: linear-gradient(135deg, #9C27B0, #7B1FA2); padding: 15px; border-radius: 8px; margin-bottom: 20px;'>"
        "<h2 style='margin: 0; color: white; text-align: center;'>⚙️ Произвольный расчет</h2>"
        "</div>"
        "<div style='background: #2a2a2a; padding: 15px; border-radius: 8px; border-left: 4px solid #9C27B0; margin-bottom: 15px;'>"
        "<h3 style='color: #9C27B0; margin-top: 0;'>🎯 Цель производства:</h3>"
        "<p style='margin: 5px 0; font-size: 16px;'>• <span style='color: #87CEEB;'>%1</span>: <span style='color: #FFD700; font-weight: bold;'>%2/мин</span></p>"
        "</div>"
    ).arg(itemName).arg(amount);

    m_tempCalculationSteps.append(QString(
        "<div style='margin: 12px 0; padding: 12px; background: linear-gradient(90deg, rgba(156,39,176,0.2), rgba(156,39,176,0.05)); border-left: 4px solid #9C27B0; border-radius: 6px;'>"
        "<span style='color: #9C27B0; font-weight: bold; font-size: 16px;'>🎯 ЦЕЛЬ:</span> "
        "<span style='color: #87CEEB; font-weight: bold;'>%1</span> - "
        "<span style='color: #FFD700; font-weight: bold;'>%2/мин</span>"
        "</div>"
    ).arg(itemName).arg(amount));
    m_tempCalculationSteps.append("<div style='border-bottom: 2px solid #444; margin: 20px 0; opacity: 0.6;'></div>");

    calculateRequirements(itemClass, amount, totalRaw);

    resultText += "<div style='background: #2a2a2a; padding: 15px; border-radius: 8px; border-left: 4px solid #FF9800;'>";
    resultText += "<h3 style='color: #FF9800; margin-top: 0;'>🔧 Детальный расчет производства:</h3>";
    resultText += "<div style='font-family: \"Segoe UI\", Arial, sans-serif; line-height: 1.4;'>";
    resultText += m_tempCalculationSteps.join("");
    resultText += "</div>";
    resultText += "</div>";
    
    resultText += "<div style='background: #2a2a2a; padding: 15px; border-radius: 8px; border-left: 4px solid #E91E63; margin-top: 15px;'>";
    resultText += "<h3 style='color: #E91E63; margin-top: 0;'>⛏️ Итого сырых ресурсов (в минуту):</h3>";
    for (auto it = totalRaw.constBegin(); it != totalRaw.constEnd(); ++it) {
        resultText += QString("<p style='margin: 5px 0; font-size: 14px;'>• <span style='color: #87CEEB;'>%1</span>: <span style='color: #FFD700; font-weight: bold;'>%2/мин</span></p>")
                      .arg(GameData::instance().getItemName(it.key()))
                      .arg(QString::number(it.value(), 'f', 2));
    }
    resultText += "</div>";

    // Формируем только сводку ресурсов
    QString summaryHtmlC = "<div style='background: linear-gradient(135deg, rgba(255, 123, 114, 0.1), rgba(22, 27, 34, 0.9)); padding: 20px; border-radius: 12px; border: 2px solid rgba(255, 123, 114, 0.3); box-shadow: 0 2px 12px rgba(0, 0, 0, 0.15);'>";
    summaryHtmlC += "<h3 style='color: #ff7b72; margin-top: 0; font-size: 18px; font-weight: 600; margin-bottom: 16px;'>⛏️ Итого сырых ресурсов (в минуту):</h3>";
    for (auto it = totalRaw.constBegin(); it != totalRaw.constEnd(); ++it) {
        summaryHtmlC += QString("<div style='margin: 8px 0; padding: 12px 16px; background: linear-gradient(90deg, rgba(255, 123, 114, 0.05), rgba(22, 27, 34, 0.3)); border-left: 4px solid #ff7b72; border-radius: 8px;'><span style='color: #58a6ff; font-weight: 600; font-size: 14px; margin-right: 8px;'>🔸</span><span style='color: #f0f6fc; font-weight: 500;'>%1</span><span style='color: rgba(240, 246, 252, 0.6); margin: 0 8px;'>:</span><span style='color: #ffd700; font-weight: bold; font-size: 15px;'>%2/мин</span></div>")
                .arg(GameData::instance().getItemName(it.key()))
                .arg(QString::number(it.value(), 'f', 2));
    }
    summaryHtmlC += "</div>";

    m_customResultOutput->setHtml(summaryHtmlC);

    // --- В calculateCustom(), перед 'QString summaryHtmlC =' добавляю ---
    m_treeWidgetCustomResults->clear();
    QTreeWidgetItem *rootC = new QTreeWidgetItem(m_treeWidgetCustomResults);
    rootC->setText(0, itemName);
    rootC->setText(1, QString::number(amount,'f',2));
    rootC->setText(2, "Цель");
    buildTree(itemClass, amount, rootC, 0);
    rootC->setExpanded(true);
}

void MainWindow::calculateRequirements(const QString& itemClass, double amountPerMinute, QMap<QString, double>& total, int depth)
{
    const auto& gdata = GameData::instance();

    // Защита от слишком глубокой рекурсии (предотвращение краша)
    if (depth > 20) {
        qDebug() << "WARNING: Recursion depth limit reached for item:" << itemClass;
        total[itemClass] += amountPerMinute;
        return;
    }

    // Кэш для предотвращения повторных вычислений
    auto& calculationCache = getCalculationCache();
    QString cacheKey = QString("%1_%2").arg(itemClass).arg(amountPerMinute);
    
    if (calculationCache.contains(cacheKey)) {
        const auto& cached = calculationCache[cacheKey];
        for (auto it = cached.constBegin(); it != cached.constEnd(); ++it) {
            total[it.key()] += it.value();
        }
        return;
    }

    // Прекращаем рекурсию для сырых ресурсов
    if (!gdata.hasRecipeForItem(itemClass)) {
        total[itemClass] += amountPerMinute;
        calculationCache[cacheKey][itemClass] = amountPerMinute;
        return;
    }

    // Выбираем лучший рецепт
    GameRecipe recipe = getBestRecipeForItem(itemClass);
    if (recipe.className.isEmpty()) {
        total[itemClass] += amountPerMinute;
        return;
    }

    double itemsPerCraft = 0;
    for(const auto& product : recipe.products) {
        if (product.itemClass == itemClass) {
            itemsPerCraft = product.amount;
            break;
        }
    }

    if (itemsPerCraft == 0) {
        total[itemClass] += amountPerMinute;
        return;
    }

    double craftsPerMinute = amountPerMinute / itemsPerCraft;
    double machinesNeeded = craftsPerMinute * (recipe.time / 60.0);

    // Добавляем информацию о текущем расчете только если depth < 10 (для производительности)
    if (depth < 10) {
        // Красивые цвета для разных уровней глубины
        QStringList levelColors = {
            "#58a6ff", "#ff7b72", "#a5f3fc", "#fbbf24", "#34d399",
            "#f472b6", "#c084fc", "#fb923c", "#60a5fa", "#4ade80"
        };
        
        QString levelColor = levelColors[depth % levelColors.size()];
        QString bgColor = QString("rgba(%1, %2, %3, 0.1)")
                         .arg((depth * 30 + 88) % 255)
                         .arg((depth * 45 + 166) % 255) 
                         .arg((depth * 20 + 255) % 255);
        
        // Создаем красивые префиксы для дерева
        QString treePrefix;
        if (depth == 0) {
            treePrefix = "<span style='color: #58a6ff; font-size: 16px;'>🎯 </span>";
        } else {
            QString connector;
            for (int i = 0; i < depth; ++i) {
                connector += "<span style='color: rgba(140, 140, 140, 0.4); font-family: monospace;'>│&nbsp;&nbsp;</span>";
            }
            connector += "<span style='color: %1; font-family: monospace; font-weight: bold;'>├─</span> ";
            treePrefix = connector;
        }
        
        // Иконки для зданий
        QString buildingIcon = getBuildingIcon(recipe.building);
        
        // --- НОВЫЙ БЛОК: Формируем список ингредиентов ---
        QString ingredientsHtml;
        if (!recipe.ingredients.isEmpty()) {
            ingredientsHtml += "<details style='margin-top: 12px; padding-top: 10px; border-top: 1px solid rgba(88, 166, 255, 0.2);'>";
            ingredientsHtml += "<summary style='font-size: 12px; color: #a5b0bd; cursor: pointer;'>Показать/скрыть ингредиенты</summary>";
            
            for (const auto& ingredient : recipe.ingredients) {
                QString ingredientIcon = getBuildingIcon(gdata.getItem(ingredient.itemClass).description); 
                
                ingredientsHtml += QString(
                    "<div style='margin-left: %1px; font-size: 13px; color: #c9d1d9; padding: 4px 0;'>"
                    "<span style='font-family: monospace; color: rgba(140, 140, 140, 0.7);'>└→ </span>"
                    "<span style='color: #58a6ff;'>%2 %3</span>: "
                    "<b style='color: #ffd700;'>%4/мин</b>"
                    "</div>"
                ).arg(depth * 15)
                 .arg(ingredientIcon)
                 .arg(gdata.getItemName(ingredient.itemClass))
                 .arg(QString::number(ingredient.amount * craftsPerMinute, 'f', 2));
            }
            ingredientsHtml += "</details>";
        }

        QString currentItemInfo = QString(
            "<div style='"
            "margin: 8px 0; "
            "padding: 16px; "
            "background: linear-gradient(135deg, %1, rgba(22, 27, 34, 0.5)); "
            "border-left: 4px solid %2; "
            "border-radius: 12px; "
            "box-shadow: 0 4px 12px rgba(0, 0, 0, 0.3);"
            "'>"
            // Header
            "<div>"
            "%3" // Tree prefix
            "<span style='color: #f0f6fc; font-weight: 600; font-size: 15px;'>%4</span> "
            "<span style='color: rgba(240, 246, 252, 0.7); font-size: 13px;'>(%5/мин)</span> "
            "<span style='color: rgba(140, 140, 140, 0.8); margin: 0 8px;'>→</span> "
            "<span style='color: #34d399; font-weight: bold; font-size: 14px;'>%6 x </span>"
            "<span style='color: #a5d6a7; font-weight: 500;'>%7 %8</span>"
            "</div>"
            // Alternate recipe badge
            "%9" 
            // Ingredients list
            "%10"
            "</div>"
        ).arg(bgColor)
         .arg(levelColor)
         .arg(treePrefix)
         .arg(gdata.getItemName(itemClass))
         .arg(QString::number(amountPerMinute, 'f', 2))
         .arg(QString::number(machinesNeeded, 'f', 2))
         .arg(buildingIcon)
         .arg(recipe.building)
         .arg(recipe.name.contains("альт", Qt::CaseInsensitive) || recipe.className.contains("Alternate") ? 
              QString("<div style='margin-top: 8px;'>"
                     "<span style='color: #ff7b72; font-weight: 600; background: rgba(255, 123, 114, 0.15); "
                     "padding: 4px 8px; border-radius: 6px; font-size: 12px;'>"
                     "ALT: %1</span>"
                     "</div>").arg(recipe.name) : "")
         .arg(ingredientsHtml); 
        
        m_tempCalculationSteps.append(currentItemInfo);
    }

    // Временное хранилище для кэша
    QMap<QString, double> tempCache;

    for (const auto& ingredient : recipe.ingredients) {
        double requiredIngredientAmount = ingredient.amount * craftsPerMinute;
        
        // Сохраняем состояние для отката при рекурсии
        QMap<QString, double> beforeRecursion = total;
        
        calculateRequirements(ingredient.itemClass, requiredIngredientAmount, total, depth + 1);
        
        // Добавляем в кэш
        for (auto it = total.constBegin(); it != total.constEnd(); ++it) {
            if (!beforeRecursion.contains(it.key()) || beforeRecursion[it.key()] != it.value()) {
                tempCache[it.key()] += it.value() - beforeRecursion.value(it.key(), 0.0);
            }
        }
    }

    // Кэшируем результат
    calculationCache[cacheKey] = tempCache;
}

void MainWindow::clearCalculationCache()
{
    // Очищаем статический кэш для свежих расчетов
    getCalculationCache().clear();
}

QMap<QString, QMap<QString, double>>& MainWindow::getCalculationCache()
{
    static QMap<QString, QMap<QString, double>> calculationCache;
    return calculationCache;
}

// ===== НОВЫЕ МЕТОДЫ ДЛЯ ЛЕНИВОЙ ЗАГРУЗКИ =====

void MainWindow::onTabChanged(int index)
{
    // Проверяем, является ли открытая вкладка вкладкой альтернативных рецептов
    if (m_tabWidget->widget(index) == m_alternateTab && !m_recipesLoaded) {
        startLazyLoadAlternateRecipes();
    }
}

void MainWindow::startLazyLoadAlternateRecipes()
{
    if (m_recipesLoaded) {
        return; // Уже загружены
    }
    
    // Показываем виджет загрузки
    m_loadingWidget->show();
    m_loadingProgressBar->setValue(0);
    m_loadingLabel->setText("🔄 Подготовка альтернативных рецептов...");
    
    // Собираем все альтернативные рецепты, группируя по предметам
    const auto& gameData = GameData::instance();
    QMap<QString, QList<GameRecipe>> alternatesByItem;
    
    // Получаем все предметы и их рецепты
    const auto& items = gameData.getItems();
    for (auto itemIt = items.constBegin(); itemIt != items.constEnd(); ++itemIt) {
        QString itemClass = itemIt.key();
        if (!gameData.hasRecipeForItem(itemClass)) continue;

        auto recipes = gameData.getRecipesForItem(itemClass);
        if (recipes.size() <= 1) continue; // нет альтернатив

        QList<GameRecipe> alternates;
        for (int i = 1; i < recipes.size(); ++i) {
            alternates.append(recipes[i]); // все, кроме первого, считаем альтернативами
        }
        if (!alternates.isEmpty()) {
            alternatesByItem[itemClass] = alternates;
        }
    }
    
    // Преобразуем в список для итерации
    m_allAlternateRecipes.clear();
    for (auto it = alternatesByItem.constBegin(); it != alternatesByItem.constEnd(); ++it) {
        m_allAlternateRecipes.append(qMakePair(it.key(), it.value()));
    }
    
    // Обновляем максимум прогресс-бара
    m_loadingProgressBar->setMaximum(m_allAlternateRecipes.size());
    
    // Сбрасываем индекс
    m_currentRecipeIndex = 0;
    
    // Запускаем таймер для пошаговой загрузки
    m_loadingTimer->start(50); // 50 мс между группами
}

void MainWindow::loadNextRecipeBatch()
{
    if (m_currentRecipeIndex >= m_allAlternateRecipes.size()) {
        // Загрузка завершена
        m_loadingTimer->stop();
        m_loadingWidget->hide();
        m_recipesLoaded = true;
        
        // Добавляем spacer в конец
        m_alternateLayout->addStretch();
        return;
    }
    
    // Загружаем батч из 2-3 рецептов за раз для плавности
    int batchSize = qMin(3, m_allAlternateRecipes.size() - m_currentRecipeIndex);
    
    for (int i = 0; i < batchSize && m_currentRecipeIndex < m_allAlternateRecipes.size(); ++i) {
        const auto& recipePair = m_allAlternateRecipes[m_currentRecipeIndex];
        QString itemClass = recipePair.first;
        const auto& alternates = recipePair.second;
        
        // Создаем красивую карточку для группы рецептов
        QWidget *groupWidget = new QWidget();
        QVBoxLayout *groupLayout = new QVBoxLayout(groupWidget);
        groupLayout->setSpacing(12);
        groupLayout->setContentsMargins(20, 20, 20, 20);
        
        groupWidget->setStyleSheet(
            "QWidget {"
            "    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #404040, stop:1 #353535);"
            "    border: 2px solid #555;"
            "    border-radius: 12px;"
            "}"
            "QWidget:hover {"
            "    border-color: #4CAF50;"
            "}"
        );
        
        // Заголовок предмета с красивым форматированием
        const auto& gameData = GameData::instance();
        QString itemName = gameData.getItemName(itemClass);
        QLabel *itemLabel = new QLabel(QString(
            "<div style='background: rgba(76,175,80,0.1); padding: 10px; border-radius: 8px; margin-bottom: 10px;'>"
            "<h3 style='color: #4CAF50; margin: 0; font-size: 16px;'>🎯 %1</h3>"
            "<p style='color: #aaa; margin: 3px 0 0 0; font-size: 11px;'>%2</p>"
            "</div>"
        ).arg(itemName).arg(itemClass));
        itemLabel->setWordWrap(true);
        groupLayout->addWidget(itemLabel);
        
        // Альтернативные рецепты для этого предмета
        for (const auto& recipe : alternates) {
            QCheckBox *checkBox = new QCheckBox();
            checkBox->setObjectName(recipe.className); // Сохраняем ID рецепта
            checkBox->setProperty("itemClass", itemClass); // Сохраняем класс предмета
            checkBox->setProperty("recipeName", recipe.name); // Для поиска
            checkBox->setProperty("category", getRecipeCategory(recipe.name)); // Для фильтрации
            
            // Формируем описание рецепта
            QString ingredientsList;
            for (const auto& ingredient : recipe.ingredients) {
                if (!ingredientsList.isEmpty()) ingredientsList += " • ";
                ingredientsList += QString("<span style='color: #FFB74D;'>%1</span> <span style='color: #FFF59D;'>×%2</span>")
                                   .arg(gameData.getItemName(ingredient.itemClass))
                                   .arg(ingredient.amount);
            }
            
            QString productsList;
            for (const auto& product : recipe.products) {
                if (!productsList.isEmpty()) productsList += " • ";
                productsList += QString("<span style='color: #A5D6A7;'>%1</span> <span style='color: #C8E6C9;'>×%2</span>")
                                .arg(gameData.getItemName(product.itemClass))
                                .arg(product.amount);
            }
            
            QString buildingIcon = getBuildingIcon(recipe.building);
            
            QString checkboxText = QString(
                "%1 %2\n"
                "%3 %4 | ⏱️ %.1f сек\n"
                "📥 Вход: %5\n"
                "📤 Выход: %6"
            ).arg(buildingIcon)
             .arg(recipe.name)
             .arg(buildingIcon)
             .arg(recipe.building)
             .arg(recipe.time)
             .arg(ingredientsList.replace(QRegularExpression("<[^>]*>"), "")) // Убираем HTML теги
             .arg(productsList.replace(QRegularExpression("<[^>]*>"), "")); // Убираем HTML теги
            
            checkBox->setText(checkboxText);
            checkBox->setStyleSheet(
                "QCheckBox {"
                "    color: #f0f0f0;"
                "    font-size: 12px;"
                "    spacing: 10px;"
                "    padding: 8px;"
                "    border-radius: 6px;"
                "}"
                "QCheckBox:hover {"
                "    background-color: rgba(76,175,80,0.1);"
                "}"
                "QCheckBox::indicator {"
                "    width: 20px;"
                "    height: 20px;"
                "    border: 2px solid #666;"
                "    border-radius: 6px;"
                "    background-color: #3a3a3a;"
                "}"
                "QCheckBox::indicator:checked {"
                "    background-color: #4CAF50;"
                "    border-color: #4CAF50;"
                "    image: url(data:image/svg+xml;base64,PHN2ZyB3aWR0aD0iMTQiIGhlaWdodD0iMTQiIHZpZXdCb3g9IjAgMCAxNCAxNCIgZmlsbD0ibm9uZSIgeG1sbnM9Imh0dHA6Ly93d3cudzMub3JnLzIwMDAvc3ZnIj4KPHBhdGggZD0iTTExIDRMNS41IDkuNUwzIDciIHN0cm9rZT0iI2ZmZiIgc3Ryb2tlLXdpZHRoPSIyIiBzdHJva2UtbGluZWNhcD0icm91bmQiIHN0cm9rZS1saW5lam9pbj0icm91bmQiLz4KPC9zdmc+);"
                "}"
                "QCheckBox::indicator:hover {"
                "    border-color: #4CAF50;"
                "    background-color: #404040;"
                "}"
            );
            
            groupLayout->addWidget(checkBox);
        }
        
        m_alternateLayout->addWidget(groupWidget);
        m_currentRecipeIndex++;
    }
    
    // Обновляем прогресс
    m_loadingProgressBar->setValue(m_currentRecipeIndex);
    m_loadingLabel->setText(QString("⏳ Загружено %1 из %2 групп рецептов...")
                           .arg(m_currentRecipeIndex)
                           .arg(m_allAlternateRecipes.size()));
}

QString MainWindow::getBuildingIcon(const QString& building) const
{
    static QMap<QString, QString> buildingIcons = {
        {"Конструктор", "🔨"},
        {"Сборщик", "🔧"},
        {"Производитель", "🏭"},
        {"Литейная", "🔥"},
        {"Очиститель", "💧"},
        {"Плавильня", "⚒️"},
        {"Ускоритель частиц", "⚛️"},
        {"Квантовый кодер", "🔮"},
        {"Конвертер", "🔄"},
        {"Водозабор", "🌊"},
        {"Нефтеперерабатывающий завод", "🛢️"}
    };
    
    return buildingIcons.value(building, "🏗️");
}

QString MainWindow::getRecipeCategory(const QString& recipeName) const
{
    // Категоризация рецептов на основе названий
    if (recipeName.contains("слиток", Qt::CaseInsensitive) || 
        recipeName.contains("сплав", Qt::CaseInsensitive) ||
        recipeName.contains("базовый", Qt::CaseInsensitive)) {
        return "ingots";
    }
    
    if (recipeName.contains("винт", Qt::CaseInsensitive) || 
        recipeName.contains("проволока", Qt::CaseInsensitive) ||
        recipeName.contains("кабель", Qt::CaseInsensitive) ||
        recipeName.contains("бетон", Qt::CaseInsensitive) ||
        recipeName.contains("кремнезем", Qt::CaseInsensitive) ||
        recipeName.contains("труба", Qt::CaseInsensitive) ||
        recipeName.contains("лист", Qt::CaseInsensitive)) {
        return "basic_parts";
    }
    
    if (recipeName.contains("микросхема", Qt::CaseInsensitive) || 
        recipeName.contains("компьютер", Qt::CaseInsensitive) ||
        recipeName.contains("соединитель", Qt::CaseInsensitive) ||
        recipeName.contains("генератор", Qt::CaseInsensitive) ||
        recipeName.contains("кристалл", Qt::CaseInsensitive) ||
        recipeName.contains("кварц", Qt::CaseInsensitive)) {
        return "electronics";
    }
    
    if (recipeName.contains("мотор", Qt::CaseInsensitive) || 
        recipeName.contains("каркас", Qt::CaseInsensitive) ||
        recipeName.contains("ротор", Qt::CaseInsensitive) ||
        recipeName.contains("статор", Qt::CaseInsensitive) ||
        recipeName.contains("балка", Qt::CaseInsensitive) ||
        recipeName.contains("радиатор", Qt::CaseInsensitive) ||
        recipeName.contains("система", Qt::CaseInsensitive)) {
        return "industrial";
    }
    
    if (recipeName.contains("пластик", Qt::CaseInsensitive) || 
        recipeName.contains("резина", Qt::CaseInsensitive) ||
        recipeName.contains("топливо", Qt::CaseInsensitive) ||
        recipeName.contains("масло", Qt::CaseInsensitive) ||
        recipeName.contains("кислота", Qt::CaseInsensitive) ||
        recipeName.contains("газ", Qt::CaseInsensitive) ||
        recipeName.contains("смола", Qt::CaseInsensitive) ||
        recipeName.contains("остаток", Qt::CaseInsensitive)) {
        return "fluids";
    }
    
    if (recipeName.contains("уран", Qt::CaseInsensitive) || 
        recipeName.contains("плутони", Qt::CaseInsensitive) ||
        recipeName.contains("ядер", Qt::CaseInsensitive) ||
        recipeName.contains("топливн", Qt::CaseInsensitive) ||
        recipeName.contains("стержн", Qt::CaseInsensitive) ||
        recipeName.contains("элемент", Qt::CaseInsensitive) ||
        recipeName.contains("паста", Qt::CaseInsensitive)) {
        return "nuclear";
    }
    
    if (recipeName.contains("квант", Qt::CaseInsensitive) || 
        recipeName.contains("темн", Qt::CaseInsensitive) ||
        recipeName.contains("материя", Qt::CaseInsensitive) ||
        recipeName.contains("алмаз", Qt::CaseInsensitive) ||
        recipeName.contains("фотон", Qt::CaseInsensitive) ||
        recipeName.contains("суперпозиц", Qt::CaseInsensitive) ||
        recipeName.contains("гиперсф", Qt::CaseInsensitive) ||
        recipeName.contains("время", Qt::CaseInsensitive) ||
        recipeName.contains("пространст", Qt::CaseInsensitive)) {
        return "advanced";
    }
    
    return ""; // По умолчанию без категории
}

void MainWindow::filterRecipes()
{
    if (!m_recipesLoaded) {
        return; // Рецепты еще не загружены
    }
    
    QString searchText = m_searchInput->text().toLower();
    QString selectedCategory = m_categoryFilter->currentData().toString();
    
    // Получаем все виджеты групп рецептов
    QList<QWidget*> groupWidgets = m_alternateContentWidget->findChildren<QWidget*>(QString(), Qt::FindDirectChildrenOnly);
    
    for (QWidget* groupWidget : groupWidgets) {
        if (groupWidget == m_loadingWidget) continue; // Пропускаем виджет загрузки
        
        bool groupVisible = false;
        
        // Проверяем все чекбоксы в группе
        QList<QCheckBox*> checkboxes = groupWidget->findChildren<QCheckBox*>();
        for (QCheckBox* checkbox : checkboxes) {
            QString recipeName = checkbox->property("recipeName").toString().toLower();
            QString category = checkbox->property("category").toString();
            
            bool matches = true;
            
            // Фильтр по поиску
            if (!searchText.isEmpty()) {
                if (!recipeName.contains(searchText)) {
                    matches = false;
                }
            }
            
            // Фильтр по категории
            if (!selectedCategory.isEmpty()) {
                if (category != selectedCategory) {
                    matches = false;
                }
            }
            
            checkbox->setVisible(matches);
            if (matches) {
                groupVisible = true;
            }
        }
        
        // Показываем/скрываем группу в зависимости от видимости хотя бы одного чекбокса
        groupWidget->setVisible(groupVisible);
    }
}

void MainWindow::setupHubCustomInputs(int tier)
{
    // Очищаем предыдущие поля ввода
    QLayoutItem* item;
    while ((item = m_hubInputsLayout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }
    m_hubProductionInputs.clear();
    
    const auto& requirements = GameData::instance().getHubUpgradeRequirements().value(tier);
    if (requirements.isEmpty()) return;
    
    // Создаем поля ввода для каждого требуемого предмета
    for (const auto& req : requirements) {
        QWidget *inputWidget = new QWidget();
        QHBoxLayout *inputLayout = new QHBoxLayout(inputWidget);
        inputLayout->setContentsMargins(0, 0, 0, 0);
        inputLayout->setSpacing(10);
        
        // Название предмета
        QLabel *itemLabel = new QLabel(GameData::instance().getItemName(req.itemClass));
        itemLabel->setMinimumWidth(180);
        itemLabel->setStyleSheet("color: #58a6ff; font-weight: 600; font-size: 13px;");
        
        // Требуемое количество
        QLabel *requiredLabel = new QLabel(QString("Нужно: %1 шт.").arg(req.amount));
        requiredLabel->setMinimumWidth(90);
        requiredLabel->setStyleSheet("color: #ffd700; font-weight: 500; font-size: 12px;");
        
        // Стрелка
        QLabel *arrowLabel = new QLabel("→");
        arrowLabel->setStyleSheet("color: #2ea043; font-weight: bold; font-size: 14px;");
        
        // Поле ввода для производства в минуту
        QLineEdit *rateInput = new QLineEdit();
        rateInput->setPlaceholderText("в мин.");
        rateInput->setMinimumWidth(70);
        rateInput->setMaximumWidth(90);
        rateInput->setText(QString::number(qMax(1.0, req.amount / 60.0), 'f', 2));
        rateInput->setStyleSheet(
            "QLineEdit {"
            "    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgba(33, 38, 45, 0.9), stop:1 rgba(22, 27, 34, 0.9));"
            "    border: 2px solid rgba(48, 54, 61, 0.8);"
            "    border-radius: 6px;"
            "    padding: 6px 10px;"
            "    font-size: 12px;"
            "    font-weight: 500;"
            "    color: #f0f6fc;"
            "}"
            "QLineEdit:focus {"
            "    border-color: #58a6ff;"
            "    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgba(56, 139, 253, 0.15), stop:1 rgba(33, 38, 45, 0.9));"
            "    box-shadow: 0 0 0 2px rgba(88, 166, 255, 0.2);"
            "}"
            "QLineEdit:hover {"
            "    border-color: rgba(88, 166, 255, 0.6);"
            "    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgba(56, 139, 253, 0.1), stop:1 rgba(33, 38, 45, 0.9));"
            "}"
        );
        
        QLabel *unitLabel = new QLabel("/мин");
        unitLabel->setStyleSheet("color: rgba(240, 246, 252, 0.7); font-size: 12px;");
        
        inputLayout->addWidget(itemLabel);
        inputLayout->addWidget(requiredLabel);
        inputLayout->addWidget(arrowLabel);
        inputLayout->addWidget(rateInput);
        inputLayout->addWidget(unitLabel);
        inputLayout->addStretch();
        
        // Стиль для контейнера
        inputWidget->setStyleSheet(
            "QWidget {"
            "    background: linear-gradient(135deg, rgba(255, 152, 0, 0.05), rgba(22, 27, 34, 0.3));"
            "    border: 1px solid rgba(255, 152, 0, 0.2);"
            "    border-radius: 8px;"
            "    padding: 10px 12px;"
            "    margin: 4px 0;"
            "}"
            "QWidget:hover {"
            "    background: linear-gradient(135deg, rgba(255, 152, 0, 0.1), rgba(22, 27, 34, 0.4));"
            "    border-color: rgba(255, 152, 0, 0.4);"
            "}"
        );
        
        m_hubInputsLayout->addWidget(inputWidget);
        m_hubProductionInputs[req.itemClass] = rateInput;
    }
    
    // Добавляем spacer
    m_hubInputsLayout->addStretch();
    
    // Автоматически подстраиваем высоту scroll area под количество элементов
    int itemCount = requirements.size();
    int itemHeight = 50; // Примерная высота одного элемента
    int totalHeight = itemCount * itemHeight + 40; // +40 для отступов
    
    // Ограничиваем минимальную и максимальную высоту
    totalHeight = qMax(100, qMin(totalHeight, 350));
    m_hubInputsScrollArea->setFixedHeight(totalHeight);
}

void MainWindow::onHubTierChanged()
{
    int tier = m_hubTierCombo->currentData().toInt();
    setupHubCustomInputs(tier);
}

void MainWindow::buildTree(const QString &itemClass, double amountPerMinute, QTreeWidgetItem *parentItem, int depth)
{
    const auto &gdata = GameData::instance();
    if (depth > 20) return;
    if (!gdata.hasRecipeForItem(itemClass)) {
        // raw resource
        parentItem->setForeground(0, QBrush(QColor("#89b4fa")));
        return;
    }
    GameRecipe recipe = getBestRecipeForItem(itemClass);
    double itemsPerCraft = 0.0;
    for (const auto &prod : recipe.products) {
        if (prod.itemClass == itemClass) { itemsPerCraft = prod.amount; break; }
    }
    if (itemsPerCraft == 0) return;
    double craftsPerMinute = amountPerMinute / itemsPerCraft;
    for (const auto &ing : recipe.ingredients) {
        double reqRate = ing.amount * craftsPerMinute;
        QTreeWidgetItem *child = new QTreeWidgetItem(parentItem);
        child->setText(0, gdata.getItemName(ing.itemClass));
        child->setText(1, QString::number(reqRate, 'f', 2));
        child->setText(2, recipe.building);
        buildTree(ing.itemClass, reqRate, child, depth + 1);
    }
} 