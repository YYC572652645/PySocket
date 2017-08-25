#include "titlebar.h"
#include <QStyle>
#include <QHBoxLayout>
#include <QDebug>
#include <QAction>
#include <QListView>
#include "globaldef.h"

/***************************            构造函数              ***************************/
TitleBar::TitleBar(QWidget *parent) : QWidget(parent)
{
    //最大化按钮设置图标+

    QPixmap pixMap = this->style()->standardPixmap(QStyle::SP_TitleBarMaxButton);
    maxButton = new QPushButton(this);
    maxButton->setIcon(pixMap);

    //最小化按钮设置图标
    pixMap = this->style()->standardPixmap(QStyle::SP_TitleBarMinButton);
    minButton = new QPushButton(this);
    minButton->setIcon(pixMap);

    //关闭按钮设置图标
    pixMap = this->style()->standardPixmap(QStyle::SP_TitleBarCloseButton);
    closeButton = new QPushButton(this);
    closeButton->setIcon(pixMap);

    //设置标签
    titleCombox = new QComboBox(this);
    imgLabel = new QLabel(this);
    spaceLabel = new QLabel(this);
    spaceLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    titleCombox->addItem("个人信息");
    titleCombox->addItem("我的账户");
    titleCombox->addItem("会员");
    titleCombox->addItem("注销当前账户");

    //设置标题栏控件内容
    imgLabel->setPixmap(QPixmap(":/image/image/image.png"));

    imgLabel->setFixedSize(TITLECONTROLWIDTH , TITLECONTROLWIDTH);
    imgLabel->setScaledContents(true);

    minButton->setFixedSize(TITLECONTROLWIDTH, TITLECONTROLWIDTH);
    maxButton->setFixedSize(TITLECONTROLWIDTH, TITLECONTROLWIDTH);
    closeButton->setFixedSize(TITLECONTROLWIDTH, TITLECONTROLWIDTH);

    //云笔记
    nodeButton= new QPushButton(this);
    nodeButton->setText("云笔记");

    //云协作
    teamButton= new QPushButton(this);
    teamButton->setText("云协作");

    //会员
    vipButton= new QPushButton(this);
    vipButton->setText("会员");

    //设置布局
    QHBoxLayout *hBoxLayout = new QHBoxLayout(this);
    hBoxLayout->addWidget(imgLabel);
    hBoxLayout->addSpacing(5);
    hBoxLayout->addWidget(titleCombox);
    hBoxLayout->addWidget(nodeButton);
    hBoxLayout->addWidget(teamButton);
    hBoxLayout->addWidget(vipButton);
    hBoxLayout->addWidget(spaceLabel);
    hBoxLayout->addWidget(minButton);
    hBoxLayout->addWidget(maxButton);
    hBoxLayout->addWidget(closeButton);
    hBoxLayout->setSpacing(0);
    hBoxLayout->setContentsMargins(5, 0, 5, 0);
    this->setLayout(hBoxLayout);

    //设置背景色
    QPalette paletteColor(palette());
    paletteColor.setColor(QPalette::Background, QColor(80, 80, 80));
    this->setAutoFillBackground(true);
    this->setPalette(paletteColor);

    //重置窗口大小
    this->resize(parent->width(), TITLEBARHEIGHT);

    //设置父类窗口
    parentWidget = parent;

    this->initValue();
}

/***************************            初始化              ***************************/
void TitleBar::initValue()
{
    //设置样式表
    closeButton->setStyleSheet("background-color:transparent;");
    minButton->setStyleSheet("background-color:transparent;");
    maxButton->setStyleSheet("background-color:transparent;");
    nodeButton->setStyleSheet("background-color:transparent; color:white;");
    teamButton->setStyleSheet("background-color:transparent; color:white;");
    vipButton->setStyleSheet("background-color:transparent;  color:white;");
    titleCombox->setObjectName("titleCombox");
    titleCombox->setView(new QListView());

    //连接信号与槽
    connect(minButton,   SIGNAL(clicked(bool)), this, SLOT(showMin()));
    connect(maxButton,   SIGNAL(clicked(bool)), this, SLOT(showMax()));
    connect(closeButton, SIGNAL(clicked(bool)), this, SLOT(showClose()));
    connect(titleCombox, SIGNAL(activated(int)), this, SLOT(receiveIndex(int)));

    //按钮点击标志位
    mousePress = false;
}

/***************************            最大化              ***************************/
void TitleBar::showMax()
{
    static int count = 0;

    if(count % 2 == 0)
    {
        QPixmap normalPix = style()->standardPixmap(QStyle::SP_TitleBarNormalButton);
        maxButton->setIcon(normalPix);

        parentWidget->showMaximized();
    }
    else
    {
        QPixmap maxPix = style()->standardPixmap(QStyle::SP_TitleBarMaxButton);
        maxButton->setIcon(maxPix);
        parentWidget->showNormal();
    }
    count ++;
}

/***************************            最小化              ***************************/
void TitleBar::showMin()
{
    parentWidget->showMinimized();
}

/***************************            关闭                 ***************************/
void TitleBar::showClose()
{
    parentWidget->close();
}

/***************************            接收下标              ***************************/
void TitleBar::receiveIndex(int index)
{
    sendIndex(index);
    titleCombox->setCurrentIndex(0);
}

QLabel *TitleBar::getImgLabel() const
{
    return imgLabel;
}

/***************************            鼠标点击              ***************************/
void TitleBar::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        mousePress = true;
    }
    movePoint = event->globalPos() - parentWidget->pos();
}

/**************************             鼠标释放              ***************************/
void TitleBar::mouseReleaseEvent(QMouseEvent *event)
{
    mousePress = false;
}

/**************************             鼠标移动              **************************/
void TitleBar::mouseMoveEvent(QMouseEvent *event)
{
    if( mousePress)
    {
        QPoint movePos = event->globalPos();
        parentWidget->move(movePos - movePoint);
    }
}
