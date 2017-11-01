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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
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
    QLabel *labelFriendName;
    QTextBrowser *textBrowserContent;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QFontComboBox *fontComboBoxFont;
    QComboBox *comboBoxSize;
    QPushButton *pushButtonColor;
    QSpacerItem *horizontalSpacer_2;
    QTextEdit *textEditSendText;
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
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
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
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));

        verticalLayout_4->addWidget(treeWidget);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        pushButtonAddFriend = new QPushButton(widget_2);
        pushButtonAddFriend->setObjectName(QStringLiteral("pushButtonAddFriend"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/image/addto.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonAddFriend->setIcon(icon);

        horizontalLayout_3->addWidget(pushButtonAddFriend);

        pushButtonFriendTj = new QPushButton(widget_2);
        pushButtonFriendTj->setObjectName(QStringLiteral("pushButtonFriendTj"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/image/timg.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonFriendTj->setIcon(icon1);

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
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        labelFriendName = new QLabel(widget);
        labelFriendName->setObjectName(QStringLiteral("labelFriendName"));
        labelFriendName->setMinimumSize(QSize(0, 40));
        labelFriendName->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"    font-size:20px;\n"
"	background-color:#2c3e50;\n"
"	color:white;\n"
"}"));

        verticalLayout_3->addWidget(labelFriendName);

        textBrowserContent = new QTextBrowser(widget);
        textBrowserContent->setObjectName(QStringLiteral("textBrowserContent"));

        verticalLayout_3->addWidget(textBrowserContent);

        frame = new QFrame(widget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setStyleSheet(QStringLiteral(""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        fontComboBoxFont = new QFontComboBox(frame);
        fontComboBoxFont->setObjectName(QStringLiteral("fontComboBoxFont"));

        horizontalLayout->addWidget(fontComboBoxFont);

        comboBoxSize = new QComboBox(frame);
        comboBoxSize->setObjectName(QStringLiteral("comboBoxSize"));
        comboBoxSize->setMinimumSize(QSize(80, 0));
        comboBoxSize->setEditable(true);

        horizontalLayout->addWidget(comboBoxSize);

        pushButtonColor = new QPushButton(frame);
        pushButtonColor->setObjectName(QStringLiteral("pushButtonColor"));
        pushButtonColor->setMinimumSize(QSize(80, 0));
        pushButtonColor->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));

        horizontalLayout->addWidget(pushButtonColor);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout);


        verticalLayout_3->addWidget(frame);

        textEditSendText = new QTextEdit(widget);
        textEditSendText->setObjectName(QStringLiteral("textEditSendText"));
        textEditSendText->setMaximumSize(QSize(16777215, 100));

        verticalLayout_3->addWidget(textEditSendText);

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
        pushButtonAddFriend->setText(QApplication::translate("friendmanger", "  \346\267\273\345\212\240\345\245\275\345\217\213", 0));
        pushButtonFriendTj->setText(QApplication::translate("friendmanger", "    \345\245\275\345\217\213\346\216\250\350\215\220", 0));
        labelFriendName->setText(QString());
        comboBoxSize->clear();
        comboBoxSize->insertItems(0, QStringList()
         << QApplication::translate("friendmanger", "2", 0)
         << QApplication::translate("friendmanger", "4", 0)
         << QApplication::translate("friendmanger", "6", 0)
         << QApplication::translate("friendmanger", "8", 0)
         << QApplication::translate("friendmanger", "10", 0)
         << QApplication::translate("friendmanger", "12", 0)
         << QApplication::translate("friendmanger", "14", 0)
         << QApplication::translate("friendmanger", "16", 0)
         << QApplication::translate("friendmanger", "18", 0)
         << QApplication::translate("friendmanger", "20", 0)
         << QApplication::translate("friendmanger", "22", 0)
         << QApplication::translate("friendmanger", "24", 0)
         << QApplication::translate("friendmanger", "26", 0)
         << QApplication::translate("friendmanger", "28", 0)
         << QApplication::translate("friendmanger", "30", 0)
         << QApplication::translate("friendmanger", "32", 0)
         << QApplication::translate("friendmanger", "34", 0)
         << QApplication::translate("friendmanger", "36", 0)
        );
        comboBoxSize->setCurrentText(QApplication::translate("friendmanger", "12", 0));
        pushButtonColor->setText(QString());
        pushButtonSend->setText(QApplication::translate("friendmanger", "\345\217\221\351\200\201", 0));
    } // retranslateUi

};

namespace Ui {
    class friendmanger: public Ui_friendmanger {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRIENDMANGER_H
