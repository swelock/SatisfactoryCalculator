/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.16
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab_lift;
    QVBoxLayout *verticalLayout_lift;
    QWidget *tab_hub;
    QVBoxLayout *verticalLayout_hub;
    QWidget *tab_custom;
    QVBoxLayout *verticalLayout_custom;
    QLabel *label_welcome;
    QHBoxLayout *horizontalLayout_input;
    QLabel *label_product;
    QComboBox *comboBox_product;
    QLabel *label_quantity;
    QLineEdit *lineEdit_quantity;
    QPushButton *pushButton_calculate;
    QSplitter *splitter;
    QWidget *widget_tree;
    QVBoxLayout *verticalLayout_tree;
    QLabel *label_tree;
    QTreeWidget *treeWidget_results;
    QWidget *widget_summary;
    QVBoxLayout *verticalLayout_summary;
    QLabel *label_summary;
    QTextBrowser *textBrowser_results;
    QWidget *tab_alternates;
    QVBoxLayout *verticalLayout_alternates;
    QLabel *label_alternates_header;
    QHBoxLayout *horizontalLayout_alternates_buttons;
    QPushButton *pushButton_reset_alternates;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_apply_alternates;
    QScrollArea *scrollArea_alternates;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_alternates_content;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1400, 900);
        MainWindow->setStyleSheet(QString::fromUtf8("\n"
"    /* ===== \320\223\320\233\320\236\320\221\320\220\320\233\320\254\320\235\320\253\320\225 \320\241\320\242\320\230\320\233\320\230 ===== */\n"
"    QMainWindow {\n"
"        background: qlineargradient(x1:0, y1:0, x2:1, y2:1, \n"
"            stop:0 #0f0f23, stop:0.3 #1a1a2e, stop:0.7 #16213e, stop:1 #0f3460);\n"
"        color: #e1e5f2;\n"
"        font-family: 'Segoe UI', 'Roboto', 'Inter', sans-serif;\n"
"    }\n"
"    \n"
"    /* ===== \320\222\320\232\320\233\320\220\320\224\320\232\320\230 ===== */\n"
"    QTabWidget::pane {\n"
"        border: 2px solid rgba(88, 166, 255, 0.3);\n"
"        background: rgba(22, 27, 34, 0.85);\n"
"        border-radius: 16px;\n"
"        margin-top: 8px;\n"
"    }\n"
"    \n"
"    QTabWidget::tab-bar {\n"
"        alignment: center;\n"
"    }\n"
"    \n"
"    QTabBar::tab {\n"
"        background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"            stop:0 rgba(49, 50, 68, 0.9), stop:1 rgba(33, 38, 45, 0.9));\n"
"        color: #a5b0bd;\n"
"        padding: 16"
                        "px 28px;\n"
"        border-top-left-radius: 12px;\n"
"        border-top-right-radius: 12px;\n"
"        margin-right: 4px;\n"
"        font-size: 15px;\n"
"        font-weight: 600;\n"
"        border: 2px solid rgba(88, 166, 255, 0.1);\n"
"        border-bottom: none;\n"
"        transition: all 0.3s ease;\n"
"    }\n"
"    \n"
"    QTabBar::tab:selected {\n"
"        background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"            stop:0 #58a6ff, stop:0.3 #388bfd, stop:0.7 #2563eb, stop:1 #1d4ed8);\n"
"        color: white;\n"
"        border-color: #58a6ff;\n"
"        text-shadow: 0 1px 3px rgba(0, 0, 0, 0.5);\n"
"        transform: translateY(-2px);\n"
"    }\n"
"    \n"
"    QTabBar::tab:hover:!selected {\n"
"        background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"            stop:0 rgba(88, 166, 255, 0.4), stop:1 rgba(56, 139, 253, 0.3));\n"
"        color: #e1e5f2;\n"
"        border-color: rgba(88, 166, 255, 0.6);\n"
"        transform: translateY(-1px);\n"
"    }\n"
"    \n"
"    /* ===="
                        "= \320\232\320\235\320\236\320\237\320\232\320\230 ===== */\n"
"    QPushButton {\n"
"        background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"            stop:0 #2563eb, stop:0.5 #1d4ed8, stop:1 #1e40af);\n"
"        color: white;\n"
"        padding: 12px 24px;\n"
"        border: 2px solid rgba(37, 99, 235, 0.8);\n"
"        border-radius: 10px;\n"
"        font-weight: 700;\n"
"        font-size: 14px;\n"
"        text-transform: uppercase;\n"
"        letter-spacing: 0.5px;\n"
"    }\n"
"    \n"
"    QPushButton:hover {\n"
"        background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"            stop:0 #3b82f6, stop:0.5 #2563eb, stop:1 #1d4ed8);\n"
"        border-color: #3b82f6;\n"
"        transform: translateY(-2px);\n"
"        box-shadow: 0 8px 25px rgba(59, 130, 246, 0.4);\n"
"    }\n"
"    \n"
"    QPushButton:pressed {\n"
"        background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"            stop:0 #1d4ed8, stop:1 #1e3a8a);\n"
"        transform: translateY(0px);\n"
"        box-sh"
                        "adow: 0 4px 15px rgba(29, 78, 216, 0.3);\n"
"    }\n"
"    \n"
"    /* ===== \320\237\320\236\320\233\320\257 \320\222\320\222\320\236\320\224\320\220 ===== */\n"
"    QLineEdit, QComboBox {\n"
"        background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"            stop:0 rgba(30, 41, 59, 0.95), stop:1 rgba(15, 23, 42, 0.95));\n"
"        color: #e1e5f2;\n"
"        padding: 12px 16px;\n"
"        border: 2px solid rgba(71, 85, 105, 0.6);\n"
"        border-radius: 10px;\n"
"        font-size: 14px;\n"
"        font-weight: 500;\n"
"    }\n"
"    \n"
"    QLineEdit:focus, QComboBox:focus {\n"
"        border-color: #58a6ff;\n"
"        background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"            stop:0 rgba(56, 139, 253, 0.15), stop:1 rgba(30, 41, 59, 0.95));\n"
"        box-shadow: 0 0 0 4px rgba(88, 166, 255, 0.15);\n"
"    }\n"
"    \n"
"    QLineEdit:hover, QComboBox:hover {\n"
"        border-color: rgba(100, 116, 139, 0.8);\n"
"        background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
" "
                        "           stop:0 rgba(51, 65, 85, 0.95), stop:1 rgba(30, 41, 59, 0.95));\n"
"    }\n"
"    \n"
"    /* ===== DROPDOWN ===== */\n"
"    QComboBox::drop-down {\n"
"        border: none;\n"
"        width: 40px;\n"
"        background: transparent;\n"
"    }\n"
"    \n"
"    QComboBox::down-arrow {\n"
"        image: none;\n"
"        border-left: 8px solid transparent;\n"
"        border-right: 8px solid transparent;\n"
"        border-top: 10px solid #94a3b8;\n"
"        margin-right: 20px;\n"
"    }\n"
"    \n"
"    QComboBox::down-arrow:hover {\n"
"        border-top-color: #58a6ff;\n"
"    }\n"
"    \n"
"    QComboBox QAbstractItemView {\n"
"        background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"            stop:0 rgba(30, 41, 59, 0.98), stop:1 rgba(15, 23, 42, 0.98));\n"
"        border: 2px solid rgba(88, 166, 255, 0.6);\n"
"        border-radius: 12px;\n"
"        selection-background-color: rgba(88, 166, 255, 0.4);\n"
"        color: #e1e5f2;\n"
"        font-size: 14px;\n"
"        padding: 8p"
                        "x;\n"
"        backdrop-filter: blur(10px);\n"
"    }\n"
"    \n"
"    QComboBox QAbstractItemView::item {\n"
"        padding: 12px 16px;\n"
"        border-radius: 8px;\n"
"        margin: 2px;\n"
"        min-height: 20px;\n"
"    }\n"
"    \n"
"    QComboBox QAbstractItemView::item:hover {\n"
"        background: rgba(88, 166, 255, 0.25);\n"
"        color: white;\n"
"    }\n"
"    \n"
"    QComboBox QAbstractItemView::item:selected {\n"
"        background: rgba(88, 166, 255, 0.5);\n"
"        color: white;\n"
"        font-weight: 600;\n"
"    }\n"
"    \n"
"    /* ===== \320\242\320\225\320\232\320\241\320\242\320\236\320\222\320\253\320\225 \320\236\320\221\320\233\320\220\320\241\320\242\320\230 ===== */\n"
"    QTextBrowser {\n"
"        background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"            stop:0 rgba(15, 23, 42, 0.95), stop:1 rgba(30, 41, 59, 0.85));\n"
"        color: #e1e5f2;\n"
"        border: 2px solid rgba(71, 85, 105, 0.4);\n"
"        border-radius: 12px;\n"
"        padding: "
                        "20px;\n"
"        font-family: 'JetBrains Mono', 'Fira Code', 'Consolas', monospace;\n"
"        font-size: 14px;\n"
"        line-height: 1.8;\n"
"        selection-background-color: rgba(88, 166, 255, 0.3);\n"
"        backdrop-filter: blur(5px);\n"
"    }\n"
"    \n"
"    QTextBrowser:focus {\n"
"        border-color: rgba(88, 166, 255, 0.8);\n"
"        box-shadow: 0 0 0 4px rgba(88, 166, 255, 0.1);\n"
"    }\n"
"    \n"
"    /* ===== \320\224\320\225\320\240\320\225\320\222\320\254\320\257 ===== */\n"
"    QTreeWidget {\n"
"        background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"            stop:0 rgba(15, 23, 42, 0.95), stop:1 rgba(30, 41, 59, 0.85));\n"
"        color: #e1e5f2;\n"
"        border: 2px solid rgba(71, 85, 105, 0.4);\n"
"        border-radius: 12px;\n"
"        padding: 12px;\n"
"        font-size: 14px;\n"
"        gridline-color: rgba(71, 85, 105, 0.3);\n"
"        selection-background-color: rgba(88, 166, 255, 0.3);\n"
"        alternate-background-color: rgba(51, 65, 85, 0.3);\n"
""
                        "        backdrop-filter: blur(5px);\n"
"    }\n"
"    \n"
"    QTreeWidget::item {\n"
"        padding: 8px 4px;\n"
"        border-bottom: 1px solid rgba(71, 85, 105, 0.2);\n"
"        border-radius: 6px;\n"
"        margin: 1px;\n"
"    }\n"
"    \n"
"    QTreeWidget::item:selected {\n"
"        background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"            stop:0 rgba(88, 166, 255, 0.4), stop:1 rgba(59, 130, 246, 0.3));\n"
"        color: white;\n"
"        font-weight: 600;\n"
"    }\n"
"    \n"
"    QTreeWidget::item:hover {\n"
"        background: rgba(71, 85, 105, 0.4);\n"
"        color: #f1f5f9;\n"
"    }\n"
"    \n"
"    QHeaderView::section {\n"
"        background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"            stop:0 rgba(71, 85, 105, 0.8), stop:1 rgba(51, 65, 85, 0.8));\n"
"        color: #f1f5f9;\n"
"        padding: 12px 8px;\n"
"        border: 1px solid rgba(100, 116, 139, 0.3);\n"
"        font-weight: 700;\n"
"        font-size: 13px;\n"
"        text-transform: uppercase;\n"
""
                        "        letter-spacing: 0.5px;\n"
"    }\n"
"    \n"
"    /* ===== \320\236\320\221\320\233\320\220\320\241\320\242\320\230 \320\237\320\240\320\236\320\232\320\240\320\243\320\242\320\232\320\230 ===== */\n"
"    QScrollArea {\n"
"        border: 2px solid rgba(71, 85, 105, 0.3);\n"
"        border-radius: 12px;\n"
"        background: rgba(15, 23, 42, 0.6);\n"
"        backdrop-filter: blur(10px);\n"
"    }\n"
"    \n"
"    QScrollBar:vertical, QScrollBar:horizontal {\n"
"        background: rgba(30, 41, 59, 0.7);\n"
"        width: 14px;\n"
"        height: 14px;\n"
"        border-radius: 7px;\n"
"        margin: 0;\n"
"    }\n"
"    \n"
"    QScrollBar::handle:vertical, QScrollBar::handle:horizontal {\n"
"        background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"            stop:0 rgba(88, 166, 255, 0.7), stop:1 rgba(59, 130, 246, 0.7));\n"
"        border-radius: 7px;\n"
"        min-height: 30px;\n"
"        min-width: 30px;\n"
"    }\n"
"    \n"
"    QScrollBar::handle:hover {\n"
"        backgro"
                        "und: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"            stop:0 rgba(88, 166, 255, 0.9), stop:1 rgba(59, 130, 246, 0.9));\n"
"    }\n"
"    \n"
"    QScrollBar::add-line, QScrollBar::sub-line {\n"
"        background: none;\n"
"        border: none;\n"
"    }\n"
"    \n"
"    /* ===== \320\234\320\225\320\242\320\232\320\230 ===== */\n"
"    QLabel {\n"
"        color: #e1e5f2;\n"
"        font-size: 14px;\n"
"        font-weight: 500;\n"
"    }\n"
"    \n"
"    /* ===== \320\240\320\220\320\227\320\224\320\225\320\233\320\230\320\242\320\225\320\233\320\230 ===== */\n"
"    QSplitter::handle {\n"
"        background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"            stop:0 rgba(71, 85, 105, 0.6), stop:0.5 rgba(88, 166, 255, 0.4), stop:1 rgba(71, 85, 105, 0.6));\n"
"        border-radius: 3px;\n"
"        margin: 2px;\n"
"    }\n"
"    \n"
"    QSplitter::handle:hover {\n"
"        background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"            stop:0 rgba(88, 166, 255, 0.6), stop:0.5 rgba(59, 13"
                        "0, 246, 0.8), stop:1 rgba(88, 166, 255, 0.6));\n"
"    }\n"
"   "));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(16);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(20, 20, 20, 20);
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab_lift = new QWidget();
        tab_lift->setObjectName(QString::fromUtf8("tab_lift"));
        verticalLayout_lift = new QVBoxLayout(tab_lift);
        verticalLayout_lift->setObjectName(QString::fromUtf8("verticalLayout_lift"));
        tabWidget->addTab(tab_lift, QString());
        tab_hub = new QWidget();
        tab_hub->setObjectName(QString::fromUtf8("tab_hub"));
        verticalLayout_hub = new QVBoxLayout(tab_hub);
        verticalLayout_hub->setObjectName(QString::fromUtf8("verticalLayout_hub"));
        tabWidget->addTab(tab_hub, QString());
        tab_custom = new QWidget();
        tab_custom->setObjectName(QString::fromUtf8("tab_custom"));
        verticalLayout_custom = new QVBoxLayout(tab_custom);
        verticalLayout_custom->setObjectName(QString::fromUtf8("verticalLayout_custom"));
        label_welcome = new QLabel(tab_custom);
        label_welcome->setObjectName(QString::fromUtf8("label_welcome"));
        label_welcome->setAlignment(Qt::AlignCenter);

        verticalLayout_custom->addWidget(label_welcome);

        horizontalLayout_input = new QHBoxLayout();
        horizontalLayout_input->setSpacing(16);
        horizontalLayout_input->setObjectName(QString::fromUtf8("horizontalLayout_input"));
        label_product = new QLabel(tab_custom);
        label_product->setObjectName(QString::fromUtf8("label_product"));

        horizontalLayout_input->addWidget(label_product);

        comboBox_product = new QComboBox(tab_custom);
        comboBox_product->setObjectName(QString::fromUtf8("comboBox_product"));
        comboBox_product->setMinimumWidth(250);

        horizontalLayout_input->addWidget(comboBox_product);

        label_quantity = new QLabel(tab_custom);
        label_quantity->setObjectName(QString::fromUtf8("label_quantity"));

        horizontalLayout_input->addWidget(label_quantity);

        lineEdit_quantity = new QLineEdit(tab_custom);
        lineEdit_quantity->setObjectName(QString::fromUtf8("lineEdit_quantity"));
        lineEdit_quantity->setMaximumWidth(120);

        horizontalLayout_input->addWidget(lineEdit_quantity);

        pushButton_calculate = new QPushButton(tab_custom);
        pushButton_calculate->setObjectName(QString::fromUtf8("pushButton_calculate"));

        horizontalLayout_input->addWidget(pushButton_calculate);


        verticalLayout_custom->addLayout(horizontalLayout_input);

        splitter = new QSplitter(tab_custom);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        widget_tree = new QWidget(splitter);
        widget_tree->setObjectName(QString::fromUtf8("widget_tree"));
        verticalLayout_tree = new QVBoxLayout(widget_tree);
        verticalLayout_tree->setObjectName(QString::fromUtf8("verticalLayout_tree"));
        label_tree = new QLabel(widget_tree);
        label_tree->setObjectName(QString::fromUtf8("label_tree"));

        verticalLayout_tree->addWidget(label_tree);

        treeWidget_results = new QTreeWidget(widget_tree);
        treeWidget_results->setObjectName(QString::fromUtf8("treeWidget_results"));

        verticalLayout_tree->addWidget(treeWidget_results);

        splitter->addWidget(widget_tree);
        widget_summary = new QWidget(splitter);
        widget_summary->setObjectName(QString::fromUtf8("widget_summary"));
        verticalLayout_summary = new QVBoxLayout(widget_summary);
        verticalLayout_summary->setObjectName(QString::fromUtf8("verticalLayout_summary"));
        label_summary = new QLabel(widget_summary);
        label_summary->setObjectName(QString::fromUtf8("label_summary"));

        verticalLayout_summary->addWidget(label_summary);

        textBrowser_results = new QTextBrowser(widget_summary);
        textBrowser_results->setObjectName(QString::fromUtf8("textBrowser_results"));

        verticalLayout_summary->addWidget(textBrowser_results);

        splitter->addWidget(widget_summary);

        verticalLayout_custom->addWidget(splitter);

        tabWidget->addTab(tab_custom, QString());
        tab_alternates = new QWidget();
        tab_alternates->setObjectName(QString::fromUtf8("tab_alternates"));
        verticalLayout_alternates = new QVBoxLayout(tab_alternates);
        verticalLayout_alternates->setObjectName(QString::fromUtf8("verticalLayout_alternates"));
        label_alternates_header = new QLabel(tab_alternates);
        label_alternates_header->setObjectName(QString::fromUtf8("label_alternates_header"));
        label_alternates_header->setWordWrap(true);

        verticalLayout_alternates->addWidget(label_alternates_header);

        horizontalLayout_alternates_buttons = new QHBoxLayout();
        horizontalLayout_alternates_buttons->setObjectName(QString::fromUtf8("horizontalLayout_alternates_buttons"));
        pushButton_reset_alternates = new QPushButton(tab_alternates);
        pushButton_reset_alternates->setObjectName(QString::fromUtf8("pushButton_reset_alternates"));

        horizontalLayout_alternates_buttons->addWidget(pushButton_reset_alternates);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_alternates_buttons->addItem(horizontalSpacer);

        pushButton_apply_alternates = new QPushButton(tab_alternates);
        pushButton_apply_alternates->setObjectName(QString::fromUtf8("pushButton_apply_alternates"));

        horizontalLayout_alternates_buttons->addWidget(pushButton_apply_alternates);


        verticalLayout_alternates->addLayout(horizontalLayout_alternates_buttons);

        scrollArea_alternates = new QScrollArea(tab_alternates);
        scrollArea_alternates->setObjectName(QString::fromUtf8("scrollArea_alternates"));
        scrollArea_alternates->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        verticalLayout_alternates_content = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_alternates_content->setObjectName(QString::fromUtf8("verticalLayout_alternates_content"));
        scrollArea_alternates->setWidget(scrollAreaWidgetContents);

        verticalLayout_alternates->addWidget(scrollArea_alternates);

        tabWidget->addTab(tab_alternates, QString());

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1400, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Satisfactory Calculator", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_lift), QCoreApplication::translate("MainWindow", "\360\237\232\200 \320\232\320\276\321\201\320\274\320\270\321\207\320\265\321\201\320\272\320\270\320\271 \320\233\320\270\321\204\321\202", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_hub), QCoreApplication::translate("MainWindow", "\360\237\217\255 \320\243\320\273\321\203\321\207\321\210\320\265\320\275\320\270\321\217 \320\245\320\220\320\221\320\260", nullptr));
        label_welcome->setText(QCoreApplication::translate("MainWindow", "<h1 style=\"color: #58a6ff; text-align: center; margin: 20px 0; font-size: 32px; font-weight: 700; text-shadow: 0 2px 10px rgba(88, 166, 255, 0.3);\">\360\237\216\257 Satisfactory Calculator</h1><p style=\"text-align: center; color: #94a3b8; font-size: 16px; margin-bottom: 30px;\">\320\237\321\200\320\276\321\204\320\265\321\201\321\201\320\270\320\276\320\275\320\260\320\273\321\214\320\275\321\213\320\271 \321\200\320\260\321\201\321\207\321\221\321\202 \320\277\321\200\320\276\320\270\320\267\320\262\320\276\320\264\321\201\321\202\320\262\320\265\320\275\320\275\321\213\321\205 \321\206\320\265\320\277\320\276\321\207\320\265\320\272</p>", nullptr));
        label_product->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\320\264\321\203\320\272\321\202:", nullptr));
        label_quantity->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276:", nullptr));
        lineEdit_quantity->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        pushButton_calculate->setText(QCoreApplication::translate("MainWindow", "\360\237\224\215 \320\240\320\260\321\201\321\201\321\207\320\270\321\202\320\260\321\202\321\214", nullptr));
        label_tree->setText(QCoreApplication::translate("MainWindow", "<h3 style=\"color: #58a6ff; margin: 0 0 12px 0; font-size: 18px; font-weight: 600;\">\360\237\223\212 \320\224\320\265\321\200\320\265\320\262\320\276 \320\277\321\200\320\276\320\270\320\267\320\262\320\276\320\264\321\201\321\202\320\262\320\260</h3>", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget_results->headerItem();
        ___qtreewidgetitem->setText(2, QCoreApplication::translate("MainWindow", "\320\227\320\264\320\260\320\275\320\270\321\217", nullptr));
        ___qtreewidgetitem->setText(1, QCoreApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276", nullptr));
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("MainWindow", "\320\232\320\276\320\274\320\277\320\276\320\275\320\265\320\275\321\202", nullptr));
        label_summary->setText(QCoreApplication::translate("MainWindow", "<h3 style=\"color: #58a6ff; margin: 0 0 12px 0; font-size: 18px; font-weight: 600;\">\342\233\217\357\270\217 \320\241\320\262\320\276\320\264\320\272\320\260 \321\200\320\265\321\201\321\203\321\200\321\201\320\276\320\262</h3>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_custom), QCoreApplication::translate("MainWindow", "\342\232\231\357\270\217 \320\232\320\260\320\273\321\214\320\272\321\203\320\273\321\217\321\202\320\276\321\200", nullptr));
        label_alternates_header->setText(QCoreApplication::translate("MainWindow", "<h2 style=\"color: #58a6ff; text-align: center; margin: 15px 0; font-size: 24px; font-weight: 700;\">\360\237\224\247 \320\243\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\260\320\273\321\214\321\202\320\265\321\200\320\275\320\260\321\202\320\270\320\262\320\275\321\213\320\274\320\270 \321\200\320\265\321\206\320\265\320\277\321\202\320\260\320\274\320\270</h2><p style=\"text-align: center; color: #94a3b8; font-size: 15px; margin-bottom: 25px;\">\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\260\320\273\321\214\321\202\320\265\321\200\320\275\320\260\321\202\320\270\320\262\320\275\321\213\320\265 \321\200\320\265\321\206\320\265\320\277\321\202\321\213 \320\264\320\273\321\217 \320\276\320\277\321\202\320\270\320\274\320\270\320\267\320\260\321\206\320\270\320\270 \320\277\321\200\320\276\320\270\320\267\320\262\320\276\320\264\321\201\321\202\320\262\320\265\320\275\320\275\321\213\321\205 \321\206\320\265\320\277\320\276\321\207\320\265\320\272</p>", nullptr));
        pushButton_reset_alternates->setText(QCoreApplication::translate("MainWindow", "\342\206\272 \320\241\320\261\321\200\320\276\321\201\320\270\321\202\321\214 \320\262\321\201\320\265", nullptr));
        pushButton_apply_alternates->setText(QCoreApplication::translate("MainWindow", "\342\234\223 \320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\321\217", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_alternates), QCoreApplication::translate("MainWindow", "\360\237\224\247 \320\220\320\273\321\214\321\202\320\265\321\200\320\275\320\260\321\202\320\270\320\262\320\275\321\213\320\265 \321\200\320\265\321\206\320\265\320\277\321\202\321\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
