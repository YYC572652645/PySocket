#ifndef PERSONINFODIALOG_H
#define PERSONINFODIALOG_H

#include "titlebar/titlebar.h"
#include <QMainWindow>

namespace Ui {
class personinfodialog;
}

//个人信息数据
typedef struct PersonData
{
    QString personUserName;
    QString name;
    QString sex;
    QString address;
    QString personInfo;
    QString realName;
    QString email;
    QString phone;
    QString photo;
}PersonData;

class PersonInfoDialog : public QMainWindow
{
    Q_OBJECT

public:
    explicit PersonInfoDialog(QWidget *parent = 0);
    ~PersonInfoDialog();

    void showDialog();                                   //显示当前窗口
    void setData(const QMap<QString, QString> &mapData); //设置个人信息

private slots:
    void on_pushButtonPhoto_clicked();           //更换头像
    void on_pushButtonSave_clicked();            //保存信息
    void on_pushButtonCancel_clicked();          //取消按钮

private:
    Ui::personinfodialog *ui;
    TitleBar *titleBar;
    PersonData personData;  //个人信息
    QImage photoImage;      //头像图片
    QString fileName;       //文件名称

    void resizeEvent(QResizeEvent *event);
};

#endif // PERSONINFODIALOG_H
