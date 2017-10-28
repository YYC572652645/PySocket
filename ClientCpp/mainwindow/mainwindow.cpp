#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client/client.h"
#include "protocol.h"
#include "globaldef.h"
#include "logindialog/logindialog.h"
#include "maintitlebar/maintitlebar.h"
#include <QVBoxLayout>
#include "globaldef.h"

MainWindow * MainWindow::instance = NULL;

/************************   构造函数              ************************/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("客户端");
    this->setWindowIcon(QIcon(":/image/image/image.png"));
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    QPalette paletteColor(palette());
    paletteColor.setColor(QPalette::Background, QColor(200, 200, 200));
    this->setAutoFillBackground(true);
    this->setPalette(paletteColor);

    titleBar = new MainTitleBar(this);
    QVBoxLayout *vBoxLayout = new QVBoxLayout(this);

    vBoxLayout->addWidget(titleBar);
    vBoxLayout->addStretch();
    vBoxLayout->setSpacing(0);
    vBoxLayout->setContentsMargins(0, 0, 0, 0);
    this->setLayout(vBoxLayout);

    connect(titleBar, SIGNAL(sendIndex(int)), this, SLOT(receiveIndex(int)));

    ui->splitter->setStyleSheet("background-color:transparent");
    ui->treeWidget->setFrameShape(QFrame::NoFrame);
    ui->listWidget->setFrameShape(QFrame::NoFrame);

    ui->comboBox->setView(new QListView());

    this->initControl();


    personInfoDialog = new PersonInfoDialog();

    friendeManger = new FriendManger(this);
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

/************************   初始化控件            ************************/
void MainWindow::initControl()
{
    //设置单行选中
    ui->treeWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->treeWidget->setSelectionMode(QAbstractItemView::SingleSelection);

    //设置为不可编辑
    ui->treeWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //设置字体
    ui->treeWidget->setFont(QFont("ZYsong", 12));

    //设置双击不收缩
    ui->treeWidget->setExpandsOnDoubleClick(false);

    //去掉表头
    ui->treeWidget->header()->setVisible(false);
    //创建菜单
    this->createActions();
}

/*******************        创建菜单              ***********************/
void MainWindow::createActions()
{
    menu          = new QMenu(this);
    newDoc        = new QMenu("新文档", this);
    newNode       = new QAction("新建笔记", this);
    newMarkDown   = new QAction("新建MarkDown", this);
    newFloder     = new QAction("新建文件夹", this);
    impordWord    = new QAction("导入Word", this);
    uploadFile    = new QAction("上传文件", this);
    uploadFloder  = new QAction("上传文件夹", this);
    extendAllData = new QAction("导出全部数据", this);

    connect(newNode,       SIGNAL(triggered(bool)), this,SLOT(newNodeSlot()));
    connect(newFloder,     SIGNAL(triggered(bool)), this,SLOT(newFloderSlot()));
    connect(newMarkDown,   SIGNAL(triggered(bool)), this,SLOT(newMarkDownSlot()));
    connect(impordWord,    SIGNAL(triggered(bool)), this,SLOT(importWordSlot()));
    connect(uploadFile,    SIGNAL(triggered(bool)), this,SLOT(uploadFileSlot()));
    connect(uploadFloder,  SIGNAL(triggered(bool)), this,SLOT(uploadFloderSlot()));
    connect(extendAllData, SIGNAL(triggered(bool)), this,SLOT(extendAllDataSlot()));
}

/*******************        显示菜单              ***********************/
void MainWindow::contextMenuEvent(QContextMenuEvent *event)
{
    if(ui->treeWidget->currentItem()->text(0) != "我的文件夹") return;

    newDoc->clear();
    menu->clear();

    newDoc->addAction(newNode);
    newDoc->addAction(newFloder);
    newDoc->addAction(newMarkDown);
    newDoc->addAction(impordWord);
    newDoc->addAction(uploadFile);
    newDoc->addAction(uploadFloder);

    menu->addMenu(newDoc);
    menu->addAction(extendAllData);

    menu->exec(QCursor::pos());

    event->accept();
}

/************************   接收下标              ************************/
void MainWindow::receiveIndex(int index)
{
    switch(index)
    {
    case PERSONINFO:  sendPersonInfoReq();break;
    case MYFRIEND:    sendFriendListReq(); break;
    case MYACCOUNT:   break;
    case VIP:         break;
    case LOGOUT:      break;
    }
}

/************************   获取个人信息窗口对象    ************************/
PersonInfoDialog *MainWindow::getPersonInfoDialog() const
{
    return personInfoDialog;
}

/************************   点击下拉列表           ************************/
void MainWindow::on_comboBox_activated(int index)
{
    ui->comboBox->setCurrentIndex(0);
}

/************************   新建文件夹             ************************/
void MainWindow::newFloderSlot()
{
    if(NULL == ui->treeWidget->currentItem()) return;

    QTreeWidgetItem *childItem = new QTreeWidgetItem();

    ui->treeWidget->currentItem()->addChild(childItem);
    childItem->setText(0, "新建文件夹");
    childItem->setFont(0, QFont("ZYSong", 12));
    childItem->setIcon(0, QIcon(":/image/image/folder.png"));
    ui->treeWidget->expandItem(ui->treeWidget->currentItem());

    //ui->treeWidget->openPersistentEditor(childItem);
}

/************************   新建笔记               ************************/
void MainWindow::newNodeSlot()
{

}

/************************   新建MarkDown          ************************/
void MainWindow::newMarkDownSlot()
{

}

/************************   导入Word               ************************/
void MainWindow::importWordSlot()
{

}

/************************   上传文件                ************************/
void MainWindow::uploadFileSlot()
{

}

/************************   上传文件夹               ************************/
void MainWindow::uploadFloderSlot()
{

}

/************************   导出全部数据             ************************/
void MainWindow::extendAllDataSlot()
{

}

FriendManger *MainWindow::getFriendeManger() const
{
    return friendeManger;
}

/************************   获取个人信息             ************************/
void MainWindow::sendPersonInfoReq()
{
    if(!CLIENT->isConnect()) CLIENT->connectServer();

    QMap<QString, QString> mapData;

    mapData[Protocol::userName] = LOGIN->getUserName();

    CLIENT->netSend(Protocol::PERSONINFOREQ, LOGIN->getUserName(), mapData);
}

/************************   获取好友列表             ************************/
void MainWindow::sendFriendListReq()
{
    if(!CLIENT->isConnect()) CLIENT->connectServer();

    QMap<QString, QString> mapData;

    mapData[Protocol::userName] = LOGIN->getUserName();

    CLIENT->netSend(Protocol::FRIENDLISYREQ, LOGIN->getUserName(), mapData);
}
