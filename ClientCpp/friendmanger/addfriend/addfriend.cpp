#include "addfriend.h"
#include "ui_addfriend.h"
#include "globaldef.h"
#include "client/client.h"

/*******************       构造函数              ***********************/
AddFriend::AddFriend(QWidget *parent) :
    QWidget(parent)
  ,titleBar(NULL)
  ,ui(new Ui::addfriend)
{
    ui->setupUi(this);

    this->initControl();
}

/*******************       析构函数              ***********************/
AddFriend::~AddFriend()
{
    delete ui;
}

/*******************       接收服务端信息              ***********************/
void AddFriend::setData(const QMap<QString, QString> &mapData)
{
    ui->tableWidget->setRowCount(mapData.size());

    int count = 0;
    for(auto iter = mapData.begin(); iter != mapData.end(); iter ++)
    {
        ui->tableWidget->setItem(count, 0, DATA(iter.key()));
        ui->tableWidget->setItem(count, 1, DATA(iter.value()));

        count ++;
    }
}

/*******************       初始化控件              ***********************/
void AddFriend::initControl()
{
    //去掉标题栏
    this->setWindowFlags(Qt::CoverWindow | Qt::FramelessWindowHint);

    //新建标题栏
    titleBar = new TitleBar(this);

    titleBar->setIcon(APPICOPATH);
    titleBar->setTitle("添加好友");
    titleBar->subButton(TITLEBAR::MAXMINWIDGET);

    //设置单行选中
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setAlternatingRowColors(true);

    //纵向隐藏序号
    ui->tableWidget->verticalHeader()->setHidden(true);

    //设置为不可编辑
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //设置表头点击禁止塌陷
    ui->tableWidget->horizontalHeader()->setHighlightSections(false);

    //设置点击表头排序
    ui->tableWidget->setSortingEnabled(true);

    //设置点击表头排序
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

/************************   改变事件              ************************/
void AddFriend::resizeEvent(QResizeEvent *event)
{
    titleBar->resize(this->width(), TitleBar::TITLEBARHEIGHT);
}

/************************   查找好友              ************************/
void AddFriend::on_pushButtonSelect_clicked()
{
    if(!CLIENT->isConnect()) CLIENT->connectServer();

    QMap<QString, QString> mapData;

    mapData[Protocol::userName] = ui->lineEditSelect->text();

    CLIENT->netSend(Protocol::SELECTFRIENDREQ, LOGIN->getUserName(), mapData);
}

/************************   设置单行选中              ************************/
void AddFriend::on_tableWidget_clicked(const QModelIndex &index)
{
    selectUserName = ui->tableWidget->item(index.row(), 0)->text();
}

/************************   发送添加请求              ************************/
void AddFriend::on_pushButton_clicked()
{
    if(!CLIENT->isConnect()) CLIENT->connectServer();

    QMap<QString, QString> mapData;

    mapData[Protocol::userName] = selectUserName;

    CLIENT->netSend(Protocol::ADDFRIENDREQ, LOGIN->getUserName(), mapData);
}
