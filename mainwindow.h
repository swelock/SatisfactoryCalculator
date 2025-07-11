#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>
#include <QList>
#include "game_data.h" // Включаем для GameRecipe
// Forward declarations
class QTabWidget;
class QComboBox;
class QLineEdit;
class QPushButton;
class QTextBrowser;
class QWidget;
class QScrollArea;
class QVBoxLayout;
class QCheckBox;
class QProgressBar;
class QLabel;
class QTimer;
class QTreeWidget;
class QTreeWidgetItem;

// Helper function declaration
GameRecipe selectBestRecipe(const QList<GameRecipe>& recipes);

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void calculateLift();
    void calculateHub();
    void calculateCustom();

private:
    void setupUi();
    void setupConnections();
    void populateComboBoxes();
    void applyStyles();

    void calculateRequirements(const QString& itemClass, double amountPerMinute, QMap<QString, double>& total, int depth = 0);
    void clearCalculationCache();
    QMap<QString, QMap<QString, double>>& getCalculationCache();
    
    void setupAlternateRecipesTab();
    void populateAlternateRecipes();
    void resetAlternateRecipes();
    void applyAlternateRecipes();
    GameRecipe getBestRecipeForItem(const QString& itemClass) const;
    
    // Ленивая загрузка альтернативных рецептов
    void startLazyLoadAlternateRecipes();
    void loadNextRecipeBatch();
    void onTabChanged(int index);
    void filterRecipes();
    QString getBuildingIcon(const QString& building) const;
    QString getRecipeCategory(const QString& recipeName) const;
    
    void setupLiftCustomInputs(int phase);
    void onLiftPhaseChanged();
    void setupHubCustomInputs(int tier);
    void onHubTierChanged();

    void buildTree(const QString& itemClass, double amountPerMinute, QTreeWidgetItem* parentItem, int depth = 0);

    // Main layout
    QTabWidget* m_tabWidget;

    // Lift Tab
    QWidget* m_liftTab;
    QComboBox* m_liftPhaseCombo;
    QPushButton* m_liftCalculateButton;
    QTextBrowser* m_liftResultOutput;
    QWidget* m_liftCustomInputsWidget;
    QScrollArea* m_liftInputsScrollArea;
    QVBoxLayout* m_liftInputsLayout;

    // Hub Tab
    QWidget* m_hubTab;
    QComboBox* m_hubTierCombo;
    QPushButton* m_hubCalculateButton;
    QTextBrowser* m_hubResultOutput;
    QWidget* m_hubCustomInputsWidget;
    QScrollArea* m_hubInputsScrollArea;
    QVBoxLayout* m_hubInputsLayout;

    // Custom Tab
    QWidget* m_customTab;
    QComboBox* m_customItemCombo;
    QLineEdit* m_customAmountInput;
    QPushButton* m_calculateCustomButton;
    QTextBrowser* m_customResultOutput;

    // Alternate Recipes Tab
    QWidget* m_alternateTab;
    QScrollArea* m_alternateScrollArea;
    QWidget* m_alternateContentWidget;
    QVBoxLayout* m_alternateLayout;
    QPushButton* m_resetAlternatesButton;
    QPushButton* m_applyAlternatesButton;
    
    // Поиск и фильтрация
    QLineEdit* m_searchInput;
    QComboBox* m_categoryFilter;
    
    // Ленивая загрузка
    QProgressBar* m_loadingProgressBar;
    QLabel* m_loadingLabel;
    QTimer* m_loadingTimer;
    QWidget* m_loadingWidget;
    bool m_recipesLoaded;
    int m_currentRecipeIndex;
    QList<QPair<QString, QList<GameRecipe>>> m_allAlternateRecipes;

    // Calculation helper
    QList<QString> m_tempCalculationSteps;
    
    // Alternate recipes management
    QMap<QString, QString> m_selectedAlternateRecipes; // itemClass -> recipeClassName
    
    // Lift production customization
    QMap<QString, QLineEdit*> m_liftProductionInputs; // itemClass -> input field
    QMap<QString, double> m_customLiftRates; // itemClass -> custom rate per minute

    // Hub production customization
    QMap<QString, QLineEdit*> m_hubProductionInputs; // itemClass -> input field
    QMap<QString, double> m_customHubRates; // itemClass -> custom rate per minute

    QTreeWidget* m_treeWidgetResults;
    QTreeWidget* m_treeWidgetHubResults;
    QTreeWidget* m_treeWidgetCustomResults;
};

#endif // MAINWINDOW_H 