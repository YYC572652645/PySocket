/********************************************************************************
** Form generated from reading UI file 'addfriend.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDFRIEND_H
#define UI_ADDFRIEND_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addfriend
{
public:
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEditSelect;
    QPushButton *pushButtonSelect;
    QPushButton *pushButton;
    QTableWidget *tableWidget;

    void setupUi(QWidget *addfriend)
    {
        if (addfriend->objectName().isEmpty())
            addfriend->setObjectName(QStringLiteral("addfriend"));
        addfriend->resize(561, 443);
        verticalLayout_2 = new QVBoxLayout(addfriend);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_2->addItem(horizontalSpacer);

        horizontalSpacer_2 = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_2->addItem(horizontalSpacer_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lineEditSelect = new QLineEdit(addfriend);
        lineEditSelect->setObjectName(QStringLiteral("lineEditSelect"));
        lineEditSelect->setMinimumSize(QSize(0, 36));
        lineEditSelect->setStyleSheet(QLatin1String("\n"
"QLineEdit\n"
"{\n"
"    border:2px solid  #5F92B2;\n"
"    border-radius:5px;\n"
"    color:black;\n"
"}\n"
""));

        horizontalLayout->addWidget(lineEditSelect);

        pushButtonSelect = new QPushButton(addfriend);
        pushButtonSelect->setObjectName(QStringLiteral("pushButtonSelect"));
        pushButtonSelect->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
"color: rgb(0, 170, 255);\n"
"font: 10pt \"\345\256\213\344\275\223\";"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/image/Btn_Input_Search.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonSelect->setIcon(icon);
        pushButtonSelect->setIconSize(QSize(36, 36));

        horizontalLayout->addWidget(pushButtonSelect);

        pushButton = new QPushButton(addfriend);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
"color: rgb(0, 170, 255);\n"
"font: 10pt \"\345\256\213\344\275\223\";"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/image/addto.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon1);
        pushButton->setIconSize(QSize(36, 36));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);

        tableWidget = new QTableWidget(addfriend);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        verticalLayout->addWidget(tableWidget);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(addfriend);

        QMetaObject::connectSlotsByName(addfriend);
    } // setupUi

    void retranslateUi(QWidget *addfriend)
    {
        addfriend->setWindowTitle(QApplication::translate("addfriend", "Form", 0));
        pushButtonSelect->setText(QString());
        pushButton->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("addfriend", "\347\224\250\346\210\267", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("addfriend", "\347\224\250\346\210\267\345\220\215", 0));
    } // retranslateUi

};

namespace Ui {
    class addfriend: public Ui_addfriend {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDFRIEND_H
