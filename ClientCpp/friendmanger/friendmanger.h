#ifndef FRIENDMANGER_H
#define FRIENDMANGER_H

#include <QMainWindow>
#include <QContextMenuEvent>
#include "titlebar/titlebar.h"
#include "addfriend/addfriend.h"
#include "messagebox/messagedialog.h"
#include "personinfodialog/personinfodialog.h"

namespace Ui {
class friendmanger;
}
typedef struct MessageData
{
    QString userName;
    QString textContent;
    QString font;
    QString fontSize;
    QString fontColor;
}MessageData;

class FriendManger : public QMainWindow
{
    Q_OBJECT

public:
    explicit FriendManger(QWidget *parent = 0);
    ~FriendManger();

    void showWidget();
    void setData(const QMap<QString, QString> &mapData);
    void setMessage(const QMap<QString, QString> &mapData);
    void setAddFriendInfo(const QMap<QString, QString> &mapData);
    AddFriend *getAddFriend() const;

private slots:
    void lookPersonInfo();                  //查看资料
    void on_pushButtonAddFriend_clicked();
    void on_pushButtonSend_clicked();
    void on_treeWidget_doubleClicked(const QModelIndex &index);
    void on_pushButtonColor_clicked();
    void on_fontComboBoxFont_currentIndexChanged(const QString &arg1);
    void on_comboBoxSize_activated(const QString &arg1);

private:
    Ui::friendmanger *ui;
    TitleBar * titleBar;
    AddFriend * addFriend;
    QString selectUser;
    QColor fontColor;
    MessageDialog messageDialog;
    PersonInfoDialog personDialog;
    QList<QString> userList;
    QMenu   *menu;                             //菜单
    QAction *personInfo;                       //查看资料
    QAction *deleteFriend;                     //删除好友

    void initControl();
    void createActions();
    void setTextEdit();
    void setText(const MessageData &messageData);
    void resizeEvent(QResizeEvent *event);
    void contextMenuEvent(QContextMenuEvent *event);

};

#endif // FRIENDMANGER_H
