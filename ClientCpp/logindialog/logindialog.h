#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QToolButton>
#include <QPixmap>
#include <QDesktopWidget>
#include <QPoint>
#include <QMoveEvent>
#include <QPaintEvent>
#include <QTextStream>
#include <QList>
#include <QtXml>
#include <QFile>
#include <QIODevice>
#include <QDomNodeList>

namespace Ui {
class LoginDialog;
}

class Client;

#define LOGIN  LoginDialog::getInstance()

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    static LoginDialog * getInstance()
    {
        if(NULL == instance)
        {
            instance = new LoginDialog();
        }

        return instance;
    }

    void loginData(int count);

    QString getUserName() const;

private slots:
    void on_pushButtonLogin_clicked();                                //登录按钮
    void actionMin();                                                 //最小化窗口
    void actionClose();                                               //关闭窗口
    void on_comboBoxUserName_activated(const QString &arg1);          //用户名点击
    void on_comboBoxUserName_currentTextChanged(const QString &arg1); //用户名改变
    void on_checkBoxAuto_clicked();                                   //自动登录
    void on_checkBoxRemeber_clicked();                                //记住密码

    void on_pushButtonRegister_clicked();

    void on_pushButtonForgetPassWord_clicked();

private:
    Ui::LoginDialog *ui;
    static LoginDialog *instance;                         //静态对象
    QPoint mousePosition;                                 //自己实现拖动操作
    bool isMousePressed;                                  //自己实现拖动操作
    QString userName;                                     //用户名
    QToolButton *minButton;                               //最小化按钮
    QToolButton *closeButton;                             //关闭按钮
    QList<QString>listStringUsnm;                         //用来存储用户名
    QList<QString>listStringPsd;                          //用来存储密码
    QList<QString>listStringRemember;                     //用来存储是否密码
    QList<QString>listStringAuto;                         //用来存储是否自动登录
    QList<QString>listStringID;                           //用来存储是否自动登录

protected:
    void closeEvent(QCloseEvent* event);
    void mouseMoveEvent(QMouseEvent*event);               //鼠标移动
    void mousePressEvent(QMouseEvent*event);              //鼠标点击
    void mouseReleaseEvent(QMouseEvent*event);            //鼠标释放
    void writeXml();                                      //写xml文件
    bool readXml();                                       //读取xml文件
    void updateXml(QString id, QString rem, QString aut); //更新xml文件

private:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();
};

#endif // LOGINDIALOG_H
