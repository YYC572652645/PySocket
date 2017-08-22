#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client/client.h"
#include "protocol.h"
#include "globaldef.h"
#include "logindialog/logindialog.h"

MainWindow * MainWindow::instance = NULL;


/************************   构造函数    ************************/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("客户端");
    this->setWindowIcon(QIcon(":/image/image/image.png"));

    personInfoDialog = new PersonInfoDialog(this);
}


/************************   析构函数              ************************/
MainWindow::~MainWindow()
{
    delete ui;
}

/************************   关闭事件              ************************/
void MainWindow::closeEvent(QCloseEvent *event)
{
    CLIENT->closeSocket();
}

/************************   个人信息按钮           ************************/
void MainWindow::on_actionPersonInfo_triggered()
{
    if(!CLIENT->isConnect()) CLIENT->connectServer();

    QMap<QString, QString> mapData;

    mapData[Protocol::userName] = LOGIN->getUserName();

    CLIENT->netSend(Protocol::PERSONINFOREQ, mapData);
}

/************************   获取个人信息窗口对象    ************************/
PersonInfoDialog *MainWindow::getPersonInfoDialog() const
{
    return personInfoDialog;
}
