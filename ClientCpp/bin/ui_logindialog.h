/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QPushButton *pushButtonLogin;
    QLineEdit *lineEditPassWord;
    QCheckBox *checkBoxRemeber;
    QCheckBox *checkBoxAuto;
    QComboBox *comboBoxUserName;
    QWidget *widget;
    QLabel *labelImage;
    QLabel *labelNode;
    QLabel *labelText;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButtonRegister;
    QPushButton *pushButtonForgetPassWord;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QStringLiteral("LoginDialog"));
        LoginDialog->resize(861, 498);
        LoginDialog->setMinimumSize(QSize(861, 498));
        LoginDialog->setMaximumSize(QSize(861, 498));
        LoginDialog->setStyleSheet(QStringLiteral("background-color:white;"));
        LoginDialog->setSizeGripEnabled(true);
        LoginDialog->setModal(true);
        pushButtonLogin = new QPushButton(LoginDialog);
        pushButtonLogin->setObjectName(QStringLiteral("pushButtonLogin"));
        pushButtonLogin->setGeometry(QRect(420, 310, 401, 41));
        pushButtonLogin->setStyleSheet(QLatin1String("border-image: url(:/image/image/loginbackground.png);\n"
"color:white;"));
        lineEditPassWord = new QLineEdit(LoginDialog);
        lineEditPassWord->setObjectName(QStringLiteral("lineEditPassWord"));
        lineEditPassWord->setGeometry(QRect(420, 200, 401, 41));
        lineEditPassWord->setStyleSheet(QStringLiteral(""));
        checkBoxRemeber = new QCheckBox(LoginDialog);
        checkBoxRemeber->setObjectName(QStringLiteral("checkBoxRemeber"));
        checkBoxRemeber->setGeometry(QRect(420, 270, 91, 21));
        checkBoxRemeber->setStyleSheet(QString::fromUtf8("color:gray;\n"
"font: 10pt \"\345\256\213\344\275\223\";"));
        checkBoxAuto = new QCheckBox(LoginDialog);
        checkBoxAuto->setObjectName(QStringLiteral("checkBoxAuto"));
        checkBoxAuto->setGeometry(QRect(730, 270, 91, 21));
        checkBoxAuto->setStyleSheet(QString::fromUtf8("color:gray;\n"
"font: 10pt \"\345\256\213\344\275\223\";"));
        comboBoxUserName = new QComboBox(LoginDialog);
        comboBoxUserName->setObjectName(QStringLiteral("comboBoxUserName"));
        comboBoxUserName->setGeometry(QRect(420, 120, 401, 41));
        comboBoxUserName->setStyleSheet(QLatin1String("QComboBox{border:1px solid gray;}\n"
"QComboBox QAbstractItemView::item{height:25px;}\n"
"QComboBox::down-arrow{image:url(:/image/image/down.png);}\n"
"QComboBox::drop-down{border:0px;min-width: 40px;}"));
        comboBoxUserName->setEditable(true);
        widget = new QWidget(LoginDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 351, 498));
        widget->setStyleSheet(QStringLiteral("background-image: url(:/image/image/background.png);"));
        labelImage = new QLabel(widget);
        labelImage->setObjectName(QStringLiteral("labelImage"));
        labelImage->setGeometry(QRect(40, 90, 271, 311));
        labelImage->setStyleSheet(QStringLiteral("border-image: url(:/image/image/IntroGif.gif);"));
        labelNode = new QLabel(widget);
        labelNode->setObjectName(QStringLiteral("labelNode"));
        labelNode->setGeometry(QRect(80, 40, 171, 38));
        labelNode->setStyleSheet(QStringLiteral(""));
        labelText = new QLabel(widget);
        labelText->setObjectName(QStringLiteral("labelText"));
        labelText->setGeometry(QRect(0, 351, 351, 141));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 400, 251, 41));
        label->setStyleSheet(QString::fromUtf8("font: 75 18pt \"\345\256\213\344\275\223\";\n"
"color: rgb(85, 170, 255);"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 440, 261, 31));
        label_2->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_3 = new QLabel(LoginDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(420, 90, 101, 16));
        label_3->setStyleSheet(QString::fromUtf8("font: 75 10pt \"\345\256\213\344\275\223\";"));
        pushButtonRegister = new QPushButton(LoginDialog);
        pushButtonRegister->setObjectName(QStringLiteral("pushButtonRegister"));
        pushButtonRegister->setGeometry(QRect(410, 370, 80, 20));
        pushButtonRegister->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
"color: rgb(0, 170, 255);\n"
"font: 10pt \"\345\256\213\344\275\223\";"));
        pushButtonForgetPassWord = new QPushButton(LoginDialog);
        pushButtonForgetPassWord->setObjectName(QStringLiteral("pushButtonForgetPassWord"));
        pushButtonForgetPassWord->setGeometry(QRect(750, 370, 80, 20));
        pushButtonForgetPassWord->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
"font: 10pt \"\345\256\213\344\275\223\";\n"
"color: rgb(0, 170, 255);"));

        retranslateUi(LoginDialog);

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QString());
        pushButtonLogin->setText(QApplication::translate("LoginDialog", "\347\231\273\345\275\225", 0));
        checkBoxRemeber->setText(QApplication::translate("LoginDialog", "\350\256\260\344\275\217\345\257\206\347\240\201", 0));
        checkBoxAuto->setText(QApplication::translate("LoginDialog", "\350\207\252\345\212\250\347\231\273\345\275\225", 0));
        labelImage->setText(QString());
        labelNode->setText(QString());
        labelText->setText(QString());
        label->setText(QApplication::translate("LoginDialog", "\345\244\232\347\253\257\350\275\273\346\235\276\345\220\214\346\255\245", 0));
        label_2->setText(QApplication::translate("LoginDialog", "\345\221\212\345\210\253\346\225\260\346\215\256\347\272\277  \346\211\213\346\234\272\347\224\265\350\204\221\350\207\252\345\212\250\345\220\214\346\255\245\346\225\260\346\215\256", 0));
        label_3->setText(QApplication::translate("LoginDialog", "\347\275\221\346\230\223\351\200\232\350\241\214\350\257\201\350\264\246\345\217\267", 0));
        pushButtonRegister->setText(QApplication::translate("LoginDialog", "\346\263\250\345\206\214\350\264\246\345\217\267", 0));
        pushButtonForgetPassWord->setText(QApplication::translate("LoginDialog", "\345\277\230\350\256\260\345\257\206\347\240\201", 0));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
