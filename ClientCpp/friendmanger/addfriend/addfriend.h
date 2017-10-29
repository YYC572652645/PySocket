#ifndef ADDFRIEND_H
#define ADDFRIEND_H

#include <QWidget>
#include "titlebar/titlebar.h"

namespace Ui {
class addfriend;
}

class AddFriend : public QWidget
{
    Q_OBJECT

public:
    explicit AddFriend(QWidget *parent = 0);
    ~AddFriend();
    void setData(const QMap<QString, QString> &mapData);

private slots:
    void on_pushButtonSelect_clicked();

private:
    Ui::addfriend *ui;

    TitleBar *titleBar;

    void initControl();
    void resizeEvent(QResizeEvent *event);
};

#endif // ADDFRIEND_H
