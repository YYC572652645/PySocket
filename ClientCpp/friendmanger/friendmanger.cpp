#include "friendmanger.h"
#include "ui_friendmanger.h"
#include <QColorDialog>
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
    this->show();
}

/*******************   设置好友列表          ***********************/
void FriendManger::setData(const QMap<QString, QString> &mapData)
{
    userList.clear();
    ui->treeWidget->clear();
    for(auto iter = mapData.begin(); iter != mapData.end(); iter ++)
    {
        QTreeWidgetItem* parentItem = new QTreeWidgetItem(ui->treeWidget);

        parentItem->setText(0, iter.value());

        userList.append(iter.key());
    }
}

/*******************   设置接收消息          ***********************/
void FriendManger::setMessage(const QMap<QString, QString> &mapData)
{
    selectUser = mapData.value(Protocol::user);

    MessageData messageData;

    messageData.userName    = mapData.value(Protocol::user);
    messageData.font        = mapData.value(Protocol::font);
    messageData.fontSize    = mapData.value(Protocol::fontSize);
    messageData.fontColor   = mapData.value(Protocol::fontColor);
    messageData.textContent = mapData.value(Protocol::sendContext);

    this->setText(messageData);
}

/*******************   接收添加好友信息       ***********************/
void FriendManger::setAddFriendInfo(const QMap<QString, QString> &mapData)
{
    this->show();

    QString info = mapData.value(Protocol::user) + "添加您为好友";

    int ok = messageDialog.setInfo(SYSTEMINFO, info, QPixmap(SUCCESSIMAGE), false, this);

    if(NULL == ui->treeWidget->currentItem()) return;
    if(!CLIENT->isConnect()) CLIENT->connectServer();

    //是否同意添加为好友
    {
        QMap<QString, QString> mapData;

        if(ok == QDialog::Accepted)
        {
            mapData[Protocol::agreeFriend] = "1";
        }
        else
        {
            mapData[Protocol::agreeFriend] = "0";
        }

        CLIENT->netSend(Protocol::AGREERIENDREQ, LOGIN->getUserName(), mapData);
    }
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
    titleBar->subButton(TITLEBAR::MINWIDGET);

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

    fontColor = QColor(0, 0, 0);

    this->createActions();
}


/*******************        创建菜单              ***********************/
void FriendManger::createActions()
{
    menu       = new QMenu(this);
    personInfo = new QAction("查看资料", this);

    connect(personInfo, SIGNAL(triggered(bool)), this,SLOT(lookPersonInfo()));
}

/*******************        显示菜单              ***********************/
void FriendManger::contextMenuEvent(QContextMenuEvent *event)
{
    if(NULL == ui->treeWidget->currentItem()) return;

    menu->clear();

    menu->addAction(personInfo);

    menu->exec(QCursor::pos());

    event->accept();
}

/*******************        设置文本              ***********************/
void FriendManger::setText(const MessageData &messageData)
{
    ui->textBrowserContent->setTextColor(Qt::blue);
    ui->textBrowserContent->setCurrentFont(QFont("ZYsong", 14, true));
    ui->textBrowserContent->append(" [" + messageData.userName + "]   " + QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));


    ui->textBrowserContent->setTextColor(QColor::fromRgb(messageData.fontColor.toUInt()));
    ui->textBrowserContent->setCurrentFont(QFont(messageData.font, messageData.fontSize.toInt()));
    ui->textBrowserContent->append(messageData.textContent);
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

/************************   获取添加好友对象        ************************/
AddFriend *FriendManger::getAddFriend() const
{
    return addFriend;
}

/************************   查看资料              ************************/
void FriendManger::lookPersonInfo()
{
    if(NULL == ui->treeWidget->currentItem()) return;
    if(!CLIENT->isConnect()) CLIENT->connectServer();

    QMap<QString, QString> mapData;

    mapData[Protocol::userName] = ui->treeWidget->currentItem()->text(0);

    CLIENT->netSend(Protocol::PERSONINFOREQ, LOGIN->getUserName(), mapData);
}

/************************   发送消息              ************************/
void FriendManger::on_pushButtonSend_clicked()
{
    if(!CLIENT->isConnect()) CLIENT->connectServer();

    QMap<QString, QString> mapData;

    mapData[Protocol::sendContext] = ui->textEditSendText->toPlainText();
    mapData[Protocol::userName] = selectUser;
    mapData[Protocol::font] = ui->fontComboBoxFont->currentFont().toString();
    mapData[Protocol::fontSize] = ui->comboBoxSize->currentText();
    mapData[Protocol::fontColor] = QString::number(fontColor.rgb());

    CLIENT->netSend(Protocol::SENDMESSAGEREQ, LOGIN->getUserName(), mapData);

    MessageData messageData;

    messageData.userName = LOGIN->getUserName();
    messageData.font = ui->fontComboBoxFont->currentFont().toString();
    messageData.fontSize = ui->comboBoxSize->currentText();
    messageData.fontColor = QString::number(fontColor.rgb());
    messageData.textContent = ui->textEditSendText->toPlainText();

    this->setText(messageData);

    ui->textEditSendText->clear();
}

/************************   双击树形控件              ************************/
void FriendManger::on_treeWidget_doubleClicked(const QModelIndex &index)
{
    selectUser = userList.at(index.row());
    ui->labelFriendName->setText("聊天对象：" + ui->treeWidget->currentItem()->text(0));
    ui->textBrowserContent->clear();
}

/************************   字体颜色              ************************/
void FriendManger::on_pushButtonColor_clicked()
{
    fontColor = QColorDialog::getColor(Qt::black, this);

    QPalette palette = ui->pushButtonColor->palette();
    palette.setColor(QPalette::Button, fontColor);
    ui->pushButtonColor->setPalette(palette);
    ui->pushButtonColor->setAutoFillBackground(true);
    ui->pushButtonColor->setFlat(true);

    this->setTextEdit();
}

/************************   字体改变              ************************/
void FriendManger::on_fontComboBoxFont_currentIndexChanged(const QString &arg1)
{
    this->setTextEdit();
}

/************************   字体大小              ************************/
void FriendManger::on_comboBoxSize_activated(const QString &arg1)
{
    this->setTextEdit();
}

/************************   设置文本框              ************************/
void FriendManger::setTextEdit()
{
    QFont font = ui->fontComboBoxFont->currentFont();

    font.setPointSize(ui->comboBoxSize->currentText().toInt());

    ui->textEditSendText->setFont(font);

    ui->textEditSendText->setTextColor(fontColor);

    ui->textEditSendText->setTextColor(fontColor);

    QString text = ui->textEditSendText->toPlainText();

    ui->textEditSendText->clear();

    ui->textEditSendText->setText(text);
}

