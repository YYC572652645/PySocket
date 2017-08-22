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

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QPushButton *pushButtonLogin;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEditPassWord;
    QCheckBox *checkBoxRemeber;
    QCheckBox *checkBoxAuto;
    QComboBox *comboBoxUserName;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QStringLiteral("LoginDialog"));
        LoginDialog->resize(400, 300);
        LoginDialog->setMinimumSize(QSize(400, 300));
        LoginDialog->setMaximumSize(QSize(400, 300));
        LoginDialog->setSizeGripEnabled(true);
        LoginDialog->setModal(true);
        pushButtonLogin = new QPushButton(LoginDialog);
        pushButtonLogin->setObjectName(QStringLiteral("pushButtonLogin"));
        pushButtonLogin->setGeometry(QRect(80, 220, 221, 31));
        pushButtonLogin->setStyleSheet(QLatin1String("\n"
"background-color: rgb(85, 170, 255);"));
        label = new QLabel(LoginDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 70, 54, 21));
        label_2 = new QLabel(LoginDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(70, 115, 54, 21));
        lineEditPassWord = new QLineEdit(LoginDialog);
        lineEditPassWord->setObjectName(QStringLiteral("lineEditPassWord"));
        lineEditPassWord->setGeometry(QRect(140, 120, 171, 20));
        lineEditPassWord->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        checkBoxRemeber = new QCheckBox(LoginDialog);
        checkBoxRemeber->setObjectName(QStringLiteral("checkBoxRemeber"));
        checkBoxRemeber->setGeometry(QRect(72, 169, 91, 21));
        checkBoxAuto = new QCheckBox(LoginDialog);
        checkBoxAuto->setObjectName(QStringLiteral("checkBoxAuto"));
        checkBoxAuto->setGeometry(QRect(220, 167, 91, 21));
        comboBoxUserName = new QComboBox(LoginDialog);
        comboBoxUserName->setObjectName(QStringLiteral("comboBoxUserName"));
        comboBoxUserName->setGeometry(QRect(140, 70, 171, 22));
        comboBoxUserName->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        comboBoxUserName->setEditable(true);

        retranslateUi(LoginDialog);

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QString());
        pushButtonLogin->setText(QApplication::translate("LoginDialog", "\347\231\273\345\275\225", 0));
        label->setText(QApplication::translate("LoginDialog", "\347\224\250\346\210\267\345\220\215\357\274\232", 0));
        label_2->setText(QApplication::translate("LoginDialog", "\345\257\206\347\240\201\357\274\232", 0));
        checkBoxRemeber->setText(QApplication::translate("LoginDialog", "\350\256\260\344\275\217\345\257\206\347\240\201", 0));
        checkBoxAuto->setText(QApplication::translate("LoginDialog", "\350\207\252\345\212\250\347\231\273\345\275\225", 0));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
