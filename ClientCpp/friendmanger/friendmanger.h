#ifndef FRIENDMANGER_H
#define FRIENDMANGER_H

#include <QMainWindow>
#include "titlebar/titlebar.h"
#include "addfriend/addfriend.h"

namespace Ui {
class friendmanger;
}

class FriendManger : public QMainWindow
{
    Q_OBJECT

public:
    explicit FriendManger(QWidget *parent = 0);
    ~FriendManger();

    void showWidget();
    void setData(const QMap<QString, QString> &mapData);

    AddFriend *getAddFriend() const;

private slots:
    void on_pushButtonAddFriend_clicked();

private:
    Ui::friendmanger *ui;
    TitleBar * titleBar;
    AddFriend * addFriend;

    void initControl();
    void resizeEvent(QResizeEvent *event);
};

#endif // FRIENDMANGER_H
