/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionPersonInfo;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer;
    QTreeWidget *treeWidget;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *lineEdit;
    QPushButton *pushButtonSelect;
    QListWidget *listWidget;
    QWidget *widget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(914, 614);
        MainWindow->setMinimumSize(QSize(750, 592));
        actionPersonInfo = new QAction(MainWindow);
        actionPersonInfo->setObjectName(QStringLiteral("actionPersonInfo"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_5 = new QVBoxLayout(centralWidget);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalSpacer = new QSpacerItem(20, 50, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout_4->addItem(verticalSpacer);

        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(4);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(splitter->sizePolicy().hasHeightForWidth());
        splitter->setSizePolicy(sizePolicy);
        splitter->setOrientation(Qt::Horizontal);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        comboBox = new QComboBox(layoutWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy1);
        comboBox->setMaximumSize(QSize(200, 16777215));
        comboBox->setStyleSheet(QLatin1String("QComboBox\n"
"{\n"
"min-height: 50px;\n"
"min-width: 60px;\n"
"background-color:transparent;\n"
"color:rgb(0, 0, 0);\n"
"selection-background-color: rgb(200, 200, 200);\n"
"}\n"
"\n"
"QComboBox QAbstractItemView\n"
"{\n"
"selection-color:black;\n"
"selection-background-color:black;\n"
"background-color:rgb(200, 200, 200);\n"
"color:black;\n"
"font:14px;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView::item\n"
"{\n"
"min-height: 50px;\n"
"min-width: 60px;\n"
"color:balck;\n"
"}"));

        verticalLayout->addWidget(comboBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer);

        treeWidget = new QTreeWidget(layoutWidget);
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/image/Icon_Category_LastMod.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/image/Icon_Category_Group.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/image/image/Icon_Category_OPenGroup.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/image/image/Icon_Category_ShareToMe.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/image/image/Icon_Notebook_shared.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/image/image/Icon_Category_Trash.png"), QSize(), QIcon::Normal, QIcon::Off);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem->setIcon(0, icon);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem1->setIcon(0, icon1);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem2->setIcon(0, icon2);
        QTreeWidgetItem *__qtreewidgetitem3 = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem3->setIcon(0, icon3);
        QTreeWidgetItem *__qtreewidgetitem4 = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem4->setIcon(0, icon4);
        QTreeWidgetItem *__qtreewidgetitem5 = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem5->setIcon(0, icon5);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(treeWidget->sizePolicy().hasHeightForWidth());
        treeWidget->setSizePolicy(sizePolicy2);
        treeWidget->setMaximumSize(QSize(200, 16777215));
        treeWidget->setStyleSheet(QStringLiteral("*{outline:0px;}"));

        verticalLayout->addWidget(treeWidget);

        splitter->addWidget(layoutWidget);
        widget_2 = new QWidget(splitter);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy3);
        widget_2->setStyleSheet(QStringLiteral("background-image: url(:/image/image/color.png);"));
        verticalLayout_3 = new QVBoxLayout(widget_2);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 10, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(10, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        lineEdit = new QLineEdit(widget_2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMinimumSize(QSize(0, 36));
        lineEdit->setStyleSheet(QLatin1String("\n"
"QLineEdit\n"
"{\n"
"    background-color: rgb(134,183,200);\n"
"    border:2px solid  #5F92B2;\n"
"    border-radius:5px;\n"
"    color:black;\n"
"}\n"
""));

        horizontalLayout->addWidget(lineEdit);

        pushButtonSelect = new QPushButton(widget_2);
        pushButtonSelect->setObjectName(QStringLiteral("pushButtonSelect"));
        pushButtonSelect->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
"color: rgb(0, 170, 255);\n"
"font: 10pt \"\345\256\213\344\275\223\";"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/image/image/Btn_Input_Search.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonSelect->setIcon(icon6);
        pushButtonSelect->setIconSize(QSize(36, 36));

        horizontalLayout->addWidget(pushButtonSelect);


        verticalLayout_2->addLayout(horizontalLayout);

        listWidget = new QListWidget(widget_2);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setStyleSheet(QStringLiteral("background-image: url(:/image/image/color.png);"));

        verticalLayout_2->addWidget(listWidget);


        verticalLayout_3->addLayout(verticalLayout_2);

        splitter->addWidget(widget_2);
        widget = new QWidget(splitter);
        widget->setObjectName(QStringLiteral("widget"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(1);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy4);
        widget->setStyleSheet(QStringLiteral("background-color: rgb(220, 220, 220);"));
        splitter->addWidget(widget);

        verticalLayout_4->addWidget(splitter);


        verticalLayout_5->addLayout(verticalLayout_4);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(treeWidget, comboBox);
        QWidget::setTabOrder(comboBox, listWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionPersonInfo->setText(QApplication::translate("MainWindow", "\344\270\252\344\272\272\344\277\241\346\201\257", 0));
#ifndef QT_NO_TOOLTIP
        actionPersonInfo->setToolTip(QApplication::translate("MainWindow", "\344\270\252\344\272\272\344\277\241\346\201\257", 0));
#endif // QT_NO_TOOLTIP
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\346\226\260\345\273\272\347\254\224\350\256\260", 0)
         << QApplication::translate("MainWindow", "\346\226\260\345\273\272\346\226\207\344\273\266\345\244\271", 0)
         << QApplication::translate("MainWindow", "\345\257\274\345\205\245Word", 0)
         << QApplication::translate("MainWindow", "\344\270\212\344\274\240\346\226\207\344\273\266", 0)
         << QApplication::translate("MainWindow", "\344\270\212\344\274\240\346\226\207\344\273\266\345\244\271", 0)
        );
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWindow", "\346\226\260\345\273\272\345\210\227", 0));

        const bool __sortingEnabled = treeWidget->isSortingEnabled();
        treeWidget->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidget->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QApplication::translate("MainWindow", "\346\234\200\346\226\260\346\226\207\346\241\243", 0));
        QTreeWidgetItem *___qtreewidgetitem2 = treeWidget->topLevelItem(1);
        ___qtreewidgetitem2->setText(0, QApplication::translate("MainWindow", "\346\210\221\347\232\204\346\226\207\344\273\266\345\244\271", 0));
        QTreeWidgetItem *___qtreewidgetitem3 = treeWidget->topLevelItem(2);
        ___qtreewidgetitem3->setText(0, QApplication::translate("MainWindow", "\344\272\221\345\215\217\344\275\234", 0));
        QTreeWidgetItem *___qtreewidgetitem4 = treeWidget->topLevelItem(3);
        ___qtreewidgetitem4->setText(0, QApplication::translate("MainWindow", "\344\270\216\346\210\221\345\210\206\344\272\253", 0));
        QTreeWidgetItem *___qtreewidgetitem5 = treeWidget->topLevelItem(4);
        ___qtreewidgetitem5->setText(0, QApplication::translate("MainWindow", "\346\210\221\347\232\204\345\210\206\344\272\253", 0));
        QTreeWidgetItem *___qtreewidgetitem6 = treeWidget->topLevelItem(5);
        ___qtreewidgetitem6->setText(0, QApplication::translate("MainWindow", "\345\233\236\346\224\266\347\253\231", 0));
        treeWidget->setSortingEnabled(__sortingEnabled);

        pushButtonSelect->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
