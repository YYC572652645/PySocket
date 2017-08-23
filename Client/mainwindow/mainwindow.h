#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "personinfodialog/personinfodialog.h"

namespace Ui {
class MainWindow;
}

class TitleBar;

#define MAINWINDOW MainWindow::getInstance()

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //单例模式
    static MainWindow * getInstance()
    {
        if(NULL == instance)
        {
            instance = new MainWindow();
        }

        return instance;
    }

    PersonInfoDialog *getPersonInfoDialog() const;

private slots:
    void on_actionPersonInfo_triggered();     //个人信息窗口按钮

private:
    Ui::MainWindow *ui;
    TitleBar * titleBar;                      //标题栏

    static MainWindow * instance;              //单例模式
    PersonInfoDialog * personInfoDialog;       //个人信息窗口

private:
    void closeEvent(QCloseEvent* event);       //关闭事件
    explicit MainWindow(QWidget *parent = 0);  //构造函数
    ~MainWindow();                             //析构函数
    void resizeEvent(QResizeEvent * event);

};

#endif // MAINWINDOW_H
