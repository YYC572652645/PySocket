#include "friendmanger.h"
#include "ui_friendmanger.h"
#include "globaldef.h"

FriendManger::FriendManger(QWidget *parent) :
    QMainWindow(parent)
  ,titleBar(NULL)
  ,addFriend(NULL)
  ,ui(new Ui::friendmanger)
{
    ui->setupUi(this);

    this->initControl();
}

FriendManger::~FriendManger()
{
    delete ui;
}

void FriendManger::showWidget()
{
    this->showMaximized();
}

/*******************   设置好友列表          ***********************/
void FriendManger::setData(const QMap<QString, QString> &mapData)
{
    ui->treeWidget->clear();
    for(auto iter = mapData.begin(); iter != mapData.end(); iter ++)
    {
        QTreeWidgetItem* parentItem = new QTreeWidgetItem(ui->treeWidget);

        parentItem->setText(0, iter.value());
    }
}

void FriendManger::setMessage(const QMap<QString, QString> &mapData)
{
    ui->textEditContent->setText(mapData[Protocol::sendContext]);
}

/*******************   初始化控件          ***********************/
void FriendManger::initControl()
{
    //去掉标题栏
    this->setWindowFlags(Qt::CoverWindow | Qt::FramelessWindowHint);

    //新建标题栏
    titleBar = new TitleBar(this);

    titleBar->setIcon(APPICOPATH);
    titleBar->setTitle("好友");
    titleBar->subButton(TITLEBAR::MAXMINWIDGET);

    ui->labelTitle->setAlignment(Qt::AlignCenter);

    //添加好友
    addFriend = new AddFriend(this);

    //设置单行选中
    ui->treeWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->treeWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->treeWidget->setAlternatingRowColors(true);

    //设置为不可编辑
    ui->treeWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //设置表头点击禁止塌陷
    ui->treeWidget->header()->setHighlightSections(false);

    //设置字体
    ui->treeWidget->setFont(QFont("ZYsong", 12));

    //去掉表头
    ui->treeWidget->header()->setVisible(false);
}

/************************   改变事件              ************************/
void FriendManger::resizeEvent(QResizeEvent *event)
{
    titleBar->resize(this->width(), TitleBar::TITLEBARHEIGHT);
}

/************************   添加好友              ************************/
void FriendManger::on_pushButtonAddFriend_clicked()
{
    addFriend->show();
}

AddFriend *FriendManger::getAddFriend() const
{
    return addFriend;
}

/************************   发送消息              ************************/
void FriendManger::on_pushButtonSend_clicked()
{
    if(!CLIENT->isConnect()) CLIENT->connectServer();

    QMap<QString, QString> mapData;

    mapData[Protocol::sendContext] = ui->textEditSendText->toPlainText();
    mapData[Protocol::userName] = selectUser;

    CLIENT->netSend(Protocol::SENDMESSAGEREQ, LOGIN->getUserName(), mapData);
}

/************************   双击树形控件              ************************/
void FriendManger::on_treeWidget_doubleClicked(const QModelIndex &index)
{
    selectUser = ui->treeWidget->currentItem()->text(0);
}
