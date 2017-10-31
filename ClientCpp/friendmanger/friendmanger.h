#ifndef FRIENDMANGER_H
#define FRIENDMANGER_H

#include <QMainWindow>
#include "titlebar/titlebar.h"
#include "addfriend/addfriend.h"
#include "messagebox/messagedialog.h"

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

    void initControl();
    void setText(const MessageData &messageData);
    void setTextEdit();
    void resizeEvent(QResizeEvent *event);
};

#endif // FRIENDMANGER_H
