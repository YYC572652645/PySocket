﻿#include "messagedialog.h"
#include "ui_messagedialog.h"
#include "globaldef.h"

const static QString okText     = "确定";
const static QString cancelText = "取消";

MessageDialog* MessageDialog::instance = NULL;

/****************          构造函数              ***************/
MessageDialog::MessageDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MessageDialog)
  ,mousePress(false)
  ,closeButton (NULL)
  ,titleLabel(NULL)
  ,imgLabel(NULL)
  ,msgLabel(NULL)
  ,cancelButton(NULL)
  ,okButton(NULL)
{
    ui->setupUi(this);

    this->setWindowTitle(tr("系统提示"));            //设置标题
    this->resize(320, 160);                         //重定义界面大小
    int width = this->width();                      //获取界面宽度
    int height = this->height();                    //获取界面高度
    this->setWindowFlags(Qt::FramelessWindowHint);  //标题框隐藏

    //加载图标
    QPixmap closePix = style()->standardPixmap(QStyle::SP_TitleBarCloseButton);
    closeButton = new QToolButton(this);
    closeButton->setIcon(closePix);
    closeButton->setGeometry(width - 30, 0, 30, 30);
    closeButton->setStyleSheet("background-image: url(:/image/image/messagecolor.png);background-color:transparent;");

    //设置标题
    titleLabel = new QLabel(this);
    titleLabel->setObjectName(QString::fromUtf8("labelOne"));
    QFont font = titleLabel->font();
    font.setBold(true);
    titleLabel->setFont(font);
    titleLabel->setGeometry(0, 0, width - 50, 30);

    //设置图片
    imgLabel=new QLabel(this);
    imgLabel->setGeometry(20, 50, 36, 36);
    imgLabel->setScaledContents(true);

    //设置消息
    msgLabel=new QLabel(this);
    msgLabel->setGeometry(65, 60, width - 100, 50);
    msgLabel->setWordWrap(true);
    msgLabel->setAlignment(Qt::AlignTop);

    //取消按钮
    cancelButton=new QPushButton(this);
    cancelButton->resize(100, 25);
    cancelButton->move(width - cancelButton->width() - 10, height - 35);

    //确定按钮
    okButton = new QPushButton(this);
    okButton->resize(100,25);
    okButton->move(width - okButton->width() - cancelButton->width() - 20, height - 35);

    //连接信号与槽
    connect(okButton,     SIGNAL(clicked(bool)), this, SLOT(okOperate()));
    connect(cancelButton, SIGNAL(clicked(bool)), this, SLOT(cancelOperate()));
    connect(closeButton,  SIGNAL(clicked(bool)), this, SLOT(close()));
}

/****************          析构函数              ***************/
MessageDialog::~MessageDialog()
{
    delete ui;
}

/****************          单例模式              ***************/
MessageDialog *MessageDialog::getInstance()
{
    if(NULL == instance)
    {
        instance = new MessageDialog();
    }
    return instance;
}

/****************          设置函数              ***************/
int MessageDialog::setInfo(QString titleInfo, QString info, QPixmap pixmap, bool isOkHidden, QWidget * parent)
{
    //设置标题
    titleLabel->setText(" " + titleInfo);

    //设置提示信息
    msgLabel->setText(info);

    //设置图标
    imgLabel->setPixmap(pixmap);

    //是否隐藏确定按钮
    okButton->setHidden(isOkHidden);
    if(isOkHidden)
    {
        cancelButton->setText(okText);
    }
    else
    {
        okButton->setText(okText);
        cancelButton->setText(cancelText);
    }

    //设置默认按钮为取消按钮
    cancelButton->setFocus();

    //指定父窗口
    if(NULL != parent)
    {
        this->setParent(parent);
        this->move((parent->width() - this->width()) / 2 , (parent->height()- this->height()) / 2);
    }

    return this->exec();
}

/****************          画图函数              ***************/
void MessageDialog::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    painter.drawPixmap(rect(),QPixmap(":/image/image/messagebackground.png"));
    QBitmap bitmap(this->size());

    QPainter painterSecond(&bitmap);
    painterSecond.fillRect(bitmap.rect(),Qt::white);
    painterSecond.setBrush(QColor(0,0,0));
    painterSecond.drawRoundedRect(rect(), 4, 4);
    setMask(bitmap);
}

/****************          鼠标点击              ***************/
void MessageDialog::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton) mousePress = true;

    movePoint = event->globalPos()-pos();
}

/****************          鼠标释放              ***************/
void MessageDialog::mouseReleaseEvent(QMouseEvent *event)
{
    mousePress = false;
}

/****************          鼠标移动              ***************/
void MessageDialog::mouseMoveEvent(QMouseEvent *event)
{
    if( mousePress)
    {
        QPoint movePos = event->globalPos();
        move(movePos - movePoint);
    }
}

/****************          确定函数              ***************/
void MessageDialog::okOperate()
{
    this->accept();
}

/****************          取消函数              ***************/
void MessageDialog::cancelOperate()
{
    this->reject();
}
