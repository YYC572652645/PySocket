#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client/client.h"
#include "protocol.h"
#include "globaldef.h"
#include "logindialog/logindialog.h"
#include "titlebar/titlebar.h"
#include <QVBoxLayout>
#include "globaldef.h"

MainWindow * MainWindow::instance = NULL;


/************************   构造函数    ************************/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("客户端");
    this->setWindowIcon(QIcon(":/image/image/image.png"));

    this->setWindowFlags(Qt::FramelessWindowHint);

    personInfoDialog = new PersonInfoDialog(this);

    QPalette paletteColor(palette());
    paletteColor.setColor(QPalette::Background, QColor(50, 50, 50));
    this->setAutoFillBackground(true);
    this->setPalette(paletteColor);

    titleBar = new TitleBar(this);
    QVBoxLayout *vBoxLayout = new QVBoxLayout(this);

    vBoxLayout->addWidget(titleBar);
    vBoxLayout->addStretch();
    vBoxLayout->setSpacing(0);
    vBoxLayout->setContentsMargins(0, 0, 0, 0);
    this->setLayout(vBoxLayout);
}


/************************   析构函数              ************************/
MainWindow::~MainWindow()
{
    delete ui;
}

/************************   改变事件              ************************/
void MainWindow::resizeEvent(QResizeEvent *event)
{
    titleBar->resize(this->width(), TITLEBARHEIGHT);
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
