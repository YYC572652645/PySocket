#ifndef FRIENDMANGER_H
#define FRIENDMANGER_H

#include <QMainWindow>
#include "titlebar/titlebar.h"

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
    void setFriendList(const QMap<QString, QString> &mapData);

private:
    Ui::friendmanger *ui;
    TitleBar * titleBar;

    void initControl();
    void resizeEvent(QResizeEvent *event);
};

#endif // FRIENDMANGER_H
