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
        MainWindow->resize(1200, 800);
        MainWindow->setStyleSheet(QString::fromUtf8("\n"
"    QMainWindow {\n"
"        background-color: #1e1e2e;\n"
"        color: #cdd6f4;\n"
"    }\n"
"    QTabWidget::pane {\n"
"        border: 1px solid #313244;\n"
"        background: #1e1e2e;\n"
"        border-radius: 8px;\n"
"    }\n"
"    QTabWidget::tab-bar {\n"
"        alignment: center;\n"
"    }\n"
"    QTabBar::tab {\n"
"        background: #313244;\n"
"        color: #cdd6f4;\n"
"        padding: 8px 20px;\n"
"        border-top-left-radius: 8px;\n"
"        border-top-right-radius: 8px;\n"
"        margin-right: 2px;\n"
"    }\n"
"    QTabBar::tab:selected {\n"
"        background: #45475a;\n"
"        color: #89b4fa;\n"
"    }\n"
"    QLabel {\n"
"        color: #cdd6f4;\n"
"        font-size: 14px;\n"
"    }\n"
"    QPushButton {\n"
"        background-color: #89b4fa;\n"
"        color: #1e1e2e;\n"
"        padding: 8px 16px;\n"
"        border: none;\n"
"        border-radius: 6px;\n"
"        font-weight: bold;\n"
"    }\n"
"    QPushButton:hover {\n"
"        background-color: #b4befe;\n"
""
                        "    }\n"
"    QLineEdit, QComboBox {\n"
"        background-color: #313244;\n"
"        color: #cdd6f4;\n"
"        padding: 6px;\n"
"        border: 1px solid #45475a;\n"
"        border-radius: 6px;\n"
"    }\n"
"    QTextBrowser {\n"
"        background-color: #313244;\n"
"        color: #cdd6f4;\n"
"        border: 1px solid #45475a;\n"
"        border-radius: 8px;\n"
"        padding: 10px;\n"
"        font-family: 'Segoe UI', sans-serif;\n"
"        font-size: 14px;\n"
"    }\n"
"    QScrollArea {\n"
"        border: 1px solid #45475a;\n"
"        border-radius: 8px;\n"
"        background-color: #313244;\n"
"    }\n"
"   "));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(12);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(16, 16, 16, 16);
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
        horizontalLayout_input->setSpacing(12);
        horizontalLayout_input->setObjectName(QString::fromUtf8("horizontalLayout_input"));
        label_product = new QLabel(tab_custom);
        label_product->setObjectName(QString::fromUtf8("label_product"));

        horizontalLayout_input->addWidget(label_product);

        comboBox_product = new QComboBox(tab_custom);
        comboBox_product->setObjectName(QString::fromUtf8("comboBox_product"));
        comboBox_product->setMinimumWidth(200);

        horizontalLayout_input->addWidget(comboBox_product);

        label_quantity = new QLabel(tab_custom);
        label_quantity->setObjectName(QString::fromUtf8("label_quantity"));

        horizontalLayout_input->addWidget(label_quantity);

        lineEdit_quantity = new QLineEdit(tab_custom);
        lineEdit_quantity->setObjectName(QString::fromUtf8("lineEdit_quantity"));
        lineEdit_quantity->setMaximumWidth(100);

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
        menubar->setGeometry(QRect(0, 0, 1200, 21));
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
        tabWidget->setTabText(tabWidget->indexOf(tab_lift), QCoreApplication::translate("MainWindow", "\320\233\320\270\321\204\321\202", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_hub), QCoreApplication::translate("MainWindow", "\320\245\320\260\320\261", nullptr));
        label_welcome->setText(QCoreApplication::translate("MainWindow", "<h1 style=\"color: #89b4fa;\">Satisfactory Calculator</h1>", nullptr));
        label_product->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\320\264\321\203\320\272\321\202:", nullptr));
        label_quantity->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276:", nullptr));
        lineEdit_quantity->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        pushButton_calculate->setText(QCoreApplication::translate("MainWindow", "\360\237\224\215 \320\240\320\260\321\201\321\201\321\207\320\270\321\202\320\260\321\202\321\214", nullptr));
        label_tree->setText(QCoreApplication::translate("MainWindow", "<h3 style=\"color: #89b4fa;\">\320\224\320\265\321\200\320\265\320\262\320\276 \320\277\321\200\320\276\320\270\320\267\320\262\320\276\320\264\321\201\321\202\320\262\320\260</h3>", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget_results->headerItem();
        ___qtreewidgetitem->setText(2, QCoreApplication::translate("MainWindow", "\320\227\320\264\320\260\320\275\320\270\321\217", nullptr));
        ___qtreewidgetitem->setText(1, QCoreApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276", nullptr));
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("MainWindow", "\320\232\320\276\320\274\320\277\320\276\320\275\320\265\320\275\321\202", nullptr));
        treeWidget_results->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"                QTreeWidget {\n"
"                    background-color: #313244;\n"
"                    color: #cdd6f4;\n"
"                    border: 1px solid #45475a;\n"
"                    border-radius: 8px;\n"
"                    padding: 10px;\n"
"                }\n"
"                QTreeWidget::item {\n"
"                    padding: 5px;\n"
"                    border-bottom: 1px solid #45475a;\n"
"                }\n"
"                QTreeWidget::item:selected {\n"
"                    background-color: #45475a;\n"
"                    color: #89b4fa;\n"
"                }\n"
"               ", nullptr));
        label_summary->setText(QCoreApplication::translate("MainWindow", "<h3 style=\"color: #89b4fa;\">\320\241\320\262\320\276\320\264\320\272\320\260 \321\200\320\265\321\201\321\203\321\200\321\201\320\276\320\262</h3>", nullptr));
        textBrowser_results->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"                QTextBrowser {\n"
"                    line-height: 1.6;\n"
"                }\n"
"               ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_custom), QCoreApplication::translate("MainWindow", "\320\232\320\260\320\273\321\214\320\272\321\203\320\273\321\217\321\202\320\276\321\200", nullptr));
        label_alternates_header->setText(QCoreApplication::translate("MainWindow", "<h2 style=\"color: #89b4fa;\">\360\237\224\247 \320\243\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\260\320\273\321\214\321\202\320\265\321\200\320\275\320\260\321\202\320\270\320\262\320\275\321\213\320\274\320\270 \321\200\320\265\321\206\320\265\320\277\321\202\320\260\320\274\320\270</h2><p>\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\260\320\273\321\214\321\202\320\265\321\200\320\275\320\260\321\202\320\270\320\262\320\275\321\213\320\265 \321\200\320\265\321\206\320\265\320\277\321\202\321\213 \320\264\320\273\321\217 \320\270\321\201\320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\320\275\320\270\321\217 \320\262 \321\200\320\260\321\201\321\207\320\265\321\202\320\260\321\205.</p>", nullptr));
        pushButton_reset_alternates->setText(QCoreApplication::translate("MainWindow", "\342\206\272 \320\241\320\261\321\200\320\276\321\201\320\270\321\202\321\214 \320\262\321\201\320\265", nullptr));
        pushButton_apply_alternates->setText(QCoreApplication::translate("MainWindow", "\342\234\223 \320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\321\217", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_alternates), QCoreApplication::translate("MainWindow", "\320\220\320\273\321\214\321\202\320\265\321\200\320\275\320\260\321\202\320\270\320\262\320\275\321\213\320\265 \321\200\320\265\321\206\320\265\320\277\321\202\321\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
