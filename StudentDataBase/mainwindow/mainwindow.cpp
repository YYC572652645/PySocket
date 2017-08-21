#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client/client.h"
#include "protocol.h"
#include "globaldef.h"
#include "logindialog/logindialog.h"

MainWindow * MainWindow::instance = NULL;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("客户端");
    this->setWindowIcon(QIcon(":/image/image/image.png"));

    personInfoDialog = new PersonInfoDialog(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    CLIENT->closeSocket();
}

void MainWindow::setPersonInfo(QMap<QString, QString> &mapData)
{

}

void MainWindow::on_actionPersonInfo_triggered()
{
    if(!CLIENT->isConnect()) CLIENT->connectServer();

    QMap<QString, QString> mapData;

    mapData[Protocol::userName] = LOGIN->getUserName();

    CLIENT->netSend(Protocol::PERSONINFOREQ, mapData);
}

PersonInfoDialog *MainWindow::getPersonInfoDialog() const
{
    return personInfoDialog;
}
