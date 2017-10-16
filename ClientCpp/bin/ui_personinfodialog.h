/********************************************************************************
** Form generated from reading UI file 'personinfodialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERSONINFODIALOG_H
#define UI_PERSONINFODIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_personinfodialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *labelPhoto;
    QPushButton *pushButtonPhoto;
    QFrame *line_4;
    QFrame *lineFirst;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLineEdit *lineEditName;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QLineEdit *lineEditSex;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QLineEdit *lineEditAddress;
    QFrame *lineSecond;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_4;
    QTextEdit *textEditPersonInfo;
    QFrame *lineThird;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_5;
    QLineEdit *lineEditRealName;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_6;
    QLineEdit *lineEditEmail;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_7;
    QLineEdit *lineEditPhone;
    QFrame *line;
    QFrame *lineFourth;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButtonSave;
    QPushButton *pushButtonCancel;

    void setupUi(QDialog *personinfodialog)
    {
        if (personinfodialog->objectName().isEmpty())
            personinfodialog->setObjectName(QStringLiteral("personinfodialog"));
        personinfodialog->resize(389, 484);
        personinfodialog->setMinimumSize(QSize(389, 484));
        personinfodialog->setMaximumSize(QSize(389, 484));
        verticalLayout_2 = new QVBoxLayout(personinfodialog);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        labelPhoto = new QLabel(personinfodialog);
        labelPhoto->setObjectName(QStringLiteral("labelPhoto"));
        labelPhoto->setMinimumSize(QSize(60, 60));
        labelPhoto->setMaximumSize(QSize(60, 60));

        horizontalLayout->addWidget(labelPhoto);

        pushButtonPhoto = new QPushButton(personinfodialog);
        pushButtonPhoto->setObjectName(QStringLiteral("pushButtonPhoto"));
        pushButtonPhoto->setMinimumSize(QSize(90, 0));
        pushButtonPhoto->setMaximumSize(QSize(90, 16777215));
        pushButtonPhoto->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(pushButtonPhoto);


        verticalLayout->addLayout(horizontalLayout);

        line_4 = new QFrame(personinfodialog);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_4);

        lineFirst = new QFrame(personinfodialog);
        lineFirst->setObjectName(QStringLiteral("lineFirst"));
        lineFirst->setMinimumSize(QSize(0, 20));
        lineFirst->setFrameShape(QFrame::HLine);
        lineFirst->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(lineFirst);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label = new QLabel(personinfodialog);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_3->addWidget(label);

        lineEditName = new QLineEdit(personinfodialog);
        lineEditName->setObjectName(QStringLiteral("lineEditName"));

        horizontalLayout_3->addWidget(lineEditName);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_2 = new QLabel(personinfodialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_4->addWidget(label_2);

        lineEditSex = new QLineEdit(personinfodialog);
        lineEditSex->setObjectName(QStringLiteral("lineEditSex"));

        horizontalLayout_4->addWidget(lineEditSex);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_3 = new QLabel(personinfodialog);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_5->addWidget(label_3);

        lineEditAddress = new QLineEdit(personinfodialog);
        lineEditAddress->setObjectName(QStringLiteral("lineEditAddress"));

        horizontalLayout_5->addWidget(lineEditAddress);


        verticalLayout->addLayout(horizontalLayout_5);

        lineSecond = new QFrame(personinfodialog);
        lineSecond->setObjectName(QStringLiteral("lineSecond"));
        lineSecond->setMinimumSize(QSize(0, 20));
        lineSecond->setFrameShape(QFrame::HLine);
        lineSecond->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(lineSecond);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_4 = new QLabel(personinfodialog);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_6->addWidget(label_4);

        textEditPersonInfo = new QTextEdit(personinfodialog);
        textEditPersonInfo->setObjectName(QStringLiteral("textEditPersonInfo"));

        horizontalLayout_6->addWidget(textEditPersonInfo);


        verticalLayout->addLayout(horizontalLayout_6);

        lineThird = new QFrame(personinfodialog);
        lineThird->setObjectName(QStringLiteral("lineThird"));
        lineThird->setMinimumSize(QSize(0, 20));
        lineThird->setFrameShape(QFrame::HLine);
        lineThird->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(lineThird);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_5 = new QLabel(personinfodialog);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_7->addWidget(label_5);

        lineEditRealName = new QLineEdit(personinfodialog);
        lineEditRealName->setObjectName(QStringLiteral("lineEditRealName"));

        horizontalLayout_7->addWidget(lineEditRealName);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_6 = new QLabel(personinfodialog);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_8->addWidget(label_6);

        lineEditEmail = new QLineEdit(personinfodialog);
        lineEditEmail->setObjectName(QStringLiteral("lineEditEmail"));

        horizontalLayout_8->addWidget(lineEditEmail);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_7 = new QLabel(personinfodialog);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_9->addWidget(label_7);

        lineEditPhone = new QLineEdit(personinfodialog);
        lineEditPhone->setObjectName(QStringLiteral("lineEditPhone"));

        horizontalLayout_9->addWidget(lineEditPhone);


        verticalLayout->addLayout(horizontalLayout_9);

        line = new QFrame(personinfodialog);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        lineFourth = new QFrame(personinfodialog);
        lineFourth->setObjectName(QStringLiteral("lineFourth"));
        lineFourth->setMinimumSize(QSize(0, 20));
        lineFourth->setFrameShape(QFrame::HLine);
        lineFourth->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(lineFourth);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButtonSave = new QPushButton(personinfodialog);
        pushButtonSave->setObjectName(QStringLiteral("pushButtonSave"));

        horizontalLayout_2->addWidget(pushButtonSave);

        pushButtonCancel = new QPushButton(personinfodialog);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));

        horizontalLayout_2->addWidget(pushButtonCancel);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(personinfodialog);

        QMetaObject::connectSlotsByName(personinfodialog);
    } // setupUi

    void retranslateUi(QDialog *personinfodialog)
    {
        personinfodialog->setWindowTitle(QApplication::translate("personinfodialog", "Dialog", 0));
        labelPhoto->setText(QApplication::translate("personinfodialog", "\345\244\264\345\203\217", 0));
        pushButtonPhoto->setText(QApplication::translate("personinfodialog", "\346\233\264\346\215\242\345\244\264\345\203\217", 0));
        label->setText(QApplication::translate("personinfodialog", "    \346\230\265\347\247\260\357\274\232", 0));
        label_2->setText(QApplication::translate("personinfodialog", "    \346\200\247\345\210\253\357\274\232", 0));
        label_3->setText(QApplication::translate("personinfodialog", "    \345\234\260\345\214\272\357\274\232", 0));
        label_4->setText(QApplication::translate("personinfodialog", "\344\270\252\344\272\272\347\256\200\344\273\213\357\274\232", 0));
        label_5->setText(QApplication::translate("personinfodialog", "\347\234\237\345\256\236\345\247\223\345\220\215\357\274\232", 0));
        label_6->setText(QApplication::translate("personinfodialog", "\345\212\236\345\205\254\351\202\256\347\256\261\357\274\232", 0));
        label_7->setText(QApplication::translate("personinfodialog", "\345\212\236\345\205\254\347\224\265\350\257\235\357\274\232", 0));
        pushButtonSave->setText(QApplication::translate("personinfodialog", "\344\277\235\345\255\230", 0));
        pushButtonCancel->setText(QApplication::translate("personinfodialog", "\345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class personinfodialog: public Ui_personinfodialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERSONINFODIALOG_H
