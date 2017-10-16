#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QAction>
#include <QContextMenuEvent>
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
    void receiveIndex(int index);              //接收下标
    void on_comboBox_activated(int index);     //点击下拉框
    void newFloderSlot();                      //新建文件夹
    void newNodeSlot();                        //新建笔记
    void newMarkDownSlot();                    //新建MarkDown
    void importWordSlot();                     //导入Word
    void uploadFileSlot();                     //上传文件
    void uploadFloderSlot();                   //上传文件夹
    void extendAllDataSlot();                  //导出全部数据

private:
    Ui::MainWindow *ui;
    TitleBar * titleBar;                       //标题栏

    static MainWindow * instance;              //单例模式
    PersonInfoDialog * personInfoDialog;       //个人信息窗口

private:
    void closeEvent(QCloseEvent* event);       //关闭事件
    explicit MainWindow(QWidget *parent = 0);  //构造函数
    ~MainWindow();                             //析构函数

    void contextMenuEvent(QContextMenuEvent *event);
    void resizeEvent(QResizeEvent * event);
    void sendPersonInfo();
    void initControl();
    void createActions();

private:
    QMenu   *menu;                             //菜单
    QMenu   *newDoc;                           //新文档
    QAction *extendAllData;                    //导出全部数据
    QAction *newNode;                          //新建笔记
    QAction *newMarkDown;                      //新建MarkDown
    QAction *newFloder;                        //新建文件夹
    QAction *impordWord;                       //导入Word
    QAction *uploadFile;                       //上传文件
    QAction *uploadFloder;                     //上传文件夹
};

#endif // MAINWINDOW_H
