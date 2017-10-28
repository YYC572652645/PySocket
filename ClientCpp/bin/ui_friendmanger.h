/********************************************************************************
** Form generated from reading UI file 'friendmanger.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRIENDMANGER_H
#define UI_FRIENDMANGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_friendmanger
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QSplitter *splitter;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QLabel *labelTitle;
    QTreeWidget *treeWidget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButtonAddFriend;
    QPushButton *pushButtonFriendTj;
    QWidget *widget;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_3;
    QTextEdit *textEditContent;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonFont;
    QPushButton *pushButtonFile;
    QSpacerItem *horizontalSpacer_2;
    QTextEdit *textEdit_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonSend;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *friendmanger)
    {
        if (friendmanger->objectName().isEmpty())
            friendmanger->setObjectName(QStringLiteral("friendmanger"));
        friendmanger->resize(800, 600);
        centralwidget = new QWidget(friendmanger);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout_7 = new QVBoxLayout(centralwidget);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_3);

        horizontalSpacer_4 = new QSpacerItem(40, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_4);


        verticalLayout_6->addLayout(verticalLayout);

        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        widget_2 = new QWidget(splitter);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy);
        verticalLayout_5 = new QVBoxLayout(widget_2);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        labelTitle = new QLabel(widget_2);
        labelTitle->setObjectName(QStringLiteral("labelTitle"));
        labelTitle->setMinimumSize(QSize(0, 40));
        labelTitle->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"    font-size:20px;\n"
"	background-color:#2c3e50;\n"
"	color:white;\n"
"}"));

        verticalLayout_4->addWidget(labelTitle);

        treeWidget = new QTreeWidget(widget_2);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));

        verticalLayout_4->addWidget(treeWidget);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        pushButtonAddFriend = new QPushButton(widget_2);
        pushButtonAddFriend->setObjectName(QStringLiteral("pushButtonAddFriend"));

        horizontalLayout_3->addWidget(pushButtonAddFriend);

        pushButtonFriendTj = new QPushButton(widget_2);
        pushButtonFriendTj->setObjectName(QStringLiteral("pushButtonFriendTj"));

        horizontalLayout_3->addWidget(pushButtonFriendTj);


        verticalLayout_4->addLayout(horizontalLayout_3);


        verticalLayout_5->addLayout(verticalLayout_4);

        splitter->addWidget(widget_2);
        widget = new QWidget(splitter);
        widget->setObjectName(QStringLiteral("widget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);
        verticalLayout_8 = new QVBoxLayout(widget);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        textEditContent = new QTextEdit(widget);
        textEditContent->setObjectName(QStringLiteral("textEditContent"));

        verticalLayout_3->addWidget(textEditContent);

        frame = new QFrame(widget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setStyleSheet(QLatin1String("background-color:#2c3e50;\n"
"color:white;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButtonFont = new QPushButton(frame);
        pushButtonFont->setObjectName(QStringLiteral("pushButtonFont"));
        pushButtonFont->setStyleSheet(QStringLiteral("color:white;"));

        horizontalLayout->addWidget(pushButtonFont);

        pushButtonFile = new QPushButton(frame);
        pushButtonFile->setObjectName(QStringLiteral("pushButtonFile"));
        pushButtonFile->setStyleSheet(QStringLiteral("color:white;"));

        horizontalLayout->addWidget(pushButtonFile);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout);


        verticalLayout_3->addWidget(frame);

        textEdit_2 = new QTextEdit(widget);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setMaximumSize(QSize(16777215, 100));

        verticalLayout_3->addWidget(textEdit_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButtonSend = new QPushButton(widget);
        pushButtonSend->setObjectName(QStringLiteral("pushButtonSend"));

        horizontalLayout_2->addWidget(pushButtonSend);


        verticalLayout_3->addLayout(horizontalLayout_2);


        verticalLayout_8->addLayout(verticalLayout_3);

        splitter->addWidget(widget);

        verticalLayout_6->addWidget(splitter);


        verticalLayout_7->addLayout(verticalLayout_6);

        friendmanger->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(friendmanger);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        friendmanger->setStatusBar(statusbar);

        retranslateUi(friendmanger);

        QMetaObject::connectSlotsByName(friendmanger);
    } // setupUi

    void retranslateUi(QMainWindow *friendmanger)
    {
        friendmanger->setWindowTitle(QApplication::translate("friendmanger", "MainWindow", 0));
        labelTitle->setText(QApplication::translate("friendmanger", "\345\245\275\345\217\213\345\210\227\350\241\250", 0));
        pushButtonAddFriend->setText(QApplication::translate("friendmanger", "\346\267\273\345\212\240\345\245\275\345\217\213", 0));
        pushButtonFriendTj->setText(QApplication::translate("friendmanger", "\345\245\275\345\217\213\346\216\250\350\215\220", 0));
        pushButtonFont->setText(QApplication::translate("friendmanger", "\345\255\227\344\275\223", 0));
        pushButtonFile->setText(QApplication::translate("friendmanger", "\346\226\207\344\273\266", 0));
        pushButtonSend->setText(QApplication::translate("friendmanger", "\345\217\221\351\200\201", 0));
    } // retranslateUi

};

namespace Ui {
    class friendmanger: public Ui_friendmanger {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRIENDMANGER_H
