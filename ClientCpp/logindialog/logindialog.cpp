#include "logindialog.h"
#include "ui_logindialog.h"
#include "client/client.h"
#include "protocol.h"
#include "globaldef.h"
#include <QListView>
#include <QMovie>

LoginDialog * LoginDialog::instance = NULL;

/**********************    构造函数       *************************/
LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);

    if(readXml())  //读取xml
    {
        for(int i=0;i<listStringUsnm.count();i++)
        {
            //将listFloat存储的信息读取出来，进行实时改变lineEdit的密码
            if(ui->comboBoxUserName->currentText()==listStringUsnm[i] && listStringRemember[i] == "1")
            {
                ui->lineEditPassWord->setText(listStringPsd[i]);
                ui->checkBoxRemeber->setChecked(true);
                if(listStringAuto[i] == "1")
                {
                    ui->checkBoxAuto->setChecked(true);
                }
            }
        }
    }

    minButton = new QToolButton(this);   //最小化按钮
    closeButton = new QToolButton(this); //关闭按钮
    int width = this->width();         //获取软件占得像素大小
    isMousePressed=false;              //鼠标点击标志位

    this->setWindowFlags(Qt::FramelessWindowHint);                                          //去掉标题栏
    QDesktopWidget *desktop = QApplication::desktop();                                      //程序显示在屏幕中间
    move((desktop->width()- this->width()) / 2, (desktop->height() - this->height()) / 2);  //程序显示在屏幕中间

    /*************************************加载图标********************************/
    QPixmap closePix = style()->standardPixmap(QStyle::SP_TitleBarCloseButton);
    closeButton->setIcon(closePix);
    QPixmap minPix = style()->standardPixmap(QStyle::SP_TitleBarMinButton);
    minButton->setIcon(minPix);

    /*************************************加载位置********************************/
    minButton->setGeometry(width - 60, 0, 30, 30);
    closeButton->setGeometry(width - 30, 0, 30, 30);

    //设置背景色
    QPalette paletteColor(palette());
    paletteColor.setColor(QPalette::Background, QColor(50, 50, 50));
    this->setAutoFillBackground(true);
    this->setPalette(paletteColor);

    ui->lineEditPassWord->setEchoMode(QLineEdit::Password);  //设置为加密形式

    /*************************************信号与槽连接******************************/
    connect(minButton,SIGNAL(clicked(bool)),SLOT(actionMin()));          //最小化按钮
    connect(closeButton,SIGNAL(clicked(bool)),SLOT(actionClose()));      //关闭按钮

    /*************************************背景色与父对话框一样************************/
    minButton->setStyleSheet("background-color:transparent");
    closeButton->setStyleSheet("background-color:transparent");
    ui->comboBoxUserName->setView(new QListView());

    //播放gif
    QMovie *movie = new QMovie(":/image/image/login.gif");
    ui->labelImage->setMovie(movie);
    movie->start();

    ui->labelImage->setScaledContents(true);
    ui->labelNode->setScaledContents(true);
    ui->labelNode->setPixmap(QPixmap(":/image/image/logo.png"));
}

/**********************    析构函数        *************************/
LoginDialog::~LoginDialog()
{
    delete ui;
}

/**********************    登录按钮        *************************/
void LoginDialog::loginData(int count)
{
    int tempCount = 0;
    QString tempRem, tempAuto;
    if(count != 0)
    {
        //判断出输入的用户名是否存在，如果存在则不写入xml中，如果不存在则写入xml中
        for(int i=0;i<listStringUsnm.count();i++)
        {
            if(ui->comboBoxUserName->currentText()==listStringUsnm[i]&&ui->lineEditPassWord->text()==listStringPsd[i])
            {
                tempCount ++;
                if(ui->checkBoxRemeber->isChecked())
                {
                    tempRem = "1";
                }
                else
                {
                    tempRem = "0";
                }
                if(ui->checkBoxAuto->isChecked())
                {
                    tempAuto = "1";
                }
                else
                {
                    tempAuto = "0";
                }
                if(tempRem!=listStringRemember[i]||tempAuto!=listStringAuto[i])//判断其自动登录和记住密码是否改变
                {
                    updateXml(listStringID[i],tempRem,tempAuto);               //更新xml文件
                }
            }
        }
        if(tempCount == 0) writeXml();

        accept();
    }
    else
    {
        QMessageBox::information(this,tr("系统提示"),tr("登录失败"));//登录失败
    }
}

/**********************    登录按钮        *************************/
void LoginDialog::on_pushButtonLogin_clicked()
{
    if(!CLIENT->isConnect()) CLIENT->connectServer();

    QMap<QString, QString> mapData;

    mapData[Protocol::userName] = ui->comboBoxUserName->currentText();
    mapData[Protocol::passWord] = ui->lineEditPassWord->text();

    this->userName = ui->comboBoxUserName->currentText();

    CLIENT->netSend(Protocol::LOGINREQ, userName, mapData);
}

/**********************    最小化          *************************/
void LoginDialog::actionMin()
{
    showMinimized();
}

/**********************    关闭            *************************/
void LoginDialog::actionClose()
{
    close();
}

/**********************    鼠标移动         *************************/
void LoginDialog::mouseMoveEvent(QMouseEvent *event)
{
    if(isMousePressed==true)
    {
        QPoint movePot=event->globalPos()-mousePosition;
        move(movePot);
    }
}

/**********************    鼠标点击         *************************/
void LoginDialog::mousePressEvent(QMouseEvent *event)
{
    mousePosition = event->pos();

    if(mousePosition.x() <= posMinX) return;

    if(mousePosition.x() >= posMaxX) return;

    if(mousePosition.y() <= posMinY) return;

    if(mousePosition.y() >= posMaxY) return;

    isMousePressed = true;
}

/**********************    鼠标释放         *************************/
void LoginDialog::mouseReleaseEvent(QMouseEvent *event)
{
    isMousePressed=false;
}

/**********************    写xml文件        *************************/
void LoginDialog::writeXml()
{
    QFile file("login.xml");
    QDomDocument dom;

    if(file.open(QIODevice::ReadOnly))
    {
        if(!dom.setContent(&file))  //将该xml文件导入到dom中
        {
            file.close();
            return ;
        }
    }
    else
    {
        return ;
    }
    file.close();

    //创建一个新的用户
    QDomElement root      = dom.documentElement();
    QDomElement user      = dom.createElement("user");
    QDomAttr    id        = dom.createAttribute("id");
    QDomElement usernm    = dom.createElement("username");
    QDomElement passwd    = dom.createElement("password");
    QDomElement remember  = dom.createElement("remember");
    QDomElement autoLogin = dom.createElement("autologin");

    QDomText text;

    QString num = root.lastChild().toElement().attribute("id");  //获取xml文件最后一个id的大小是多少
    int count = num.toInt()+1;
    id.setValue(QString::number(count));                       //将id+1后添加到新建的用户中
    user.setAttributeNode(id);

    //将从界面获取的用户名和密码，加到xml文件中
    text=dom.createTextNode(ui->comboBoxUserName->currentText());
    usernm.appendChild(text);
    text=dom.createTextNode(ui->lineEditPassWord->text());
    passwd.appendChild(text);
    if(ui->checkBoxRemeber->isChecked())
    {
        text = dom.createTextNode("1");
        remember.appendChild(text);
    }
    else
    {
        text = dom.createTextNode("0");
        remember.appendChild(text);
    }

    if(ui->checkBoxAuto->isChecked())
    {
        text = dom.createTextNode("1");
        autoLogin.appendChild(text);
    }
    else
    {
        text = dom.createTextNode("0");
        autoLogin.appendChild(text);
    }

    //将所有节点依次对应写到根节点的目录下
    user.appendChild(usernm);
    user.appendChild(passwd);
    user.appendChild(remember);
    user.appendChild(autoLogin);
    root.appendChild(user);

    QFile f("login.xml");
    if(!f.open(QIODevice::WriteOnly|QIODevice::Truncate)) return;

    QTextStream out(&f);
    dom.save(out, 4);
    f.close();
}

/**********************    读取xml文件      *************************/
bool LoginDialog::readXml()
{
    int Count=0;
    listStringPsd.clear();     //清空list存储
    listStringUsnm.clear();    //清空list存储
    listStringAuto.clear();    //清空list存储
    listStringRemember.clear();//清空list存储
    listStringID.clear();      //清空list存储

    QDomDocument dom;
    QFile *file = new QFile("login.xml");
    if(file->open(QIODevice::ReadOnly))
    {
        if(!dom.setContent(file))  //将该xml文件导入到dom中
        {
            file->close();
            return false;
        }
    }
    else
    {
        return false;
    }
    file->close();
    QDomElement docElem=dom.documentElement();   //返回根元素

    QDomNode node=docElem.firstChild();          //返回根节点的第一个子节点

    while(!node.isNull())                        //如果节点不为空
    {
        if(node.isElement())                     //如果节点是元素
        {
            QDomElement element=node.toElement();//将其转化为元素
            listStringID<<element.attribute("id");

            QDomNodeList list=element.childNodes();//取出该元素的所有子节点放到list中

            //将子节点元素全部取出来
            for(int i = 0; i < list.count(); i ++)
            {
                QDomNode domNode=list.at(i);
                if(domNode.isElement())
                {
                    //取出我们所要的数据
                    switch(i)
                    {
                    case 0:ui->comboBoxUserName->addItem(domNode.toElement().text());listStringUsnm<<domNode.toElement().text();break;
                    case 1:listStringPsd<<domNode.toElement().text();break;
                    case 2:listStringRemember<<domNode.toElement().text();break;
                    case 3:listStringAuto<<domNode.toElement().text();break;
                    }

                }
            }
        }

        Count++;
        node=node.nextSibling(); //下一个兄弟节点
    }

    return Count > 0 ? true : false;
}

/**********************    更新xml文件      *************************/
void LoginDialog::updateXml(QString id,QString rem,QString aut)
{
    QDomDocument dom;
    QFile *file=new QFile("login.xml");
    if(file->open(QIODevice::ReadOnly))
    {
        if(!dom.setContent(file))  //将该xml文件导入到dom中
        {
            file->close();
            return ;
        }
    }
    else
    {
        return ;
    }
    file->close();
    QDomNodeList nodeList=dom.elementsByTagName("user");   //返回根元素
    //以标签名进行查找
    for(int i=0;i<nodeList.count();i++)
    {
        QDomElement e=nodeList.at(i).toElement();

        if(e.attribute("id")==id)
        {
            QDomNodeList child=nodeList.at(i).childNodes();        //找到它的所有子节点
            child.at(2).toElement().firstChild().setNodeValue(rem);//将子节点的内容更新
            child.at(3).toElement().firstChild().setNodeValue(aut);//将子节点的内容更新

        }
    }


    QFile f("login.xml");
    if(!f.open(QIODevice::WriteOnly | QIODevice::Truncate)) return;

    QTextStream out(&f);
    dom.save(out,4);
    f.close();

}

/**********************    点击列表框       *************************/
void LoginDialog::on_comboBoxUserName_activated(const QString &arg1)
{
    int count=0;
    int tempCount=0;
    for(int i=0;i<ui->comboBoxUserName->count();i++)
    {
        //将listFloat存储的信息读取出来，进行实时改变lineEdit的密码
        if(ui->comboBoxUserName->currentText()==listStringUsnm[i]&&listStringRemember[i]=="1")
        {
            count++;
            ui->checkBoxRemeber->setChecked(true);
            ui->lineEditPassWord->setText(listStringPsd[i]);
            if(listStringAuto[i]=="1")
            {
                ui->checkBoxAuto->setChecked(true);
                tempCount++;
            }
        }
    }

    if(0 == count)
    {
        ui->checkBoxRemeber->setChecked(false);
        ui->lineEditPassWord->clear();
    }
    if(0 == tempCount)
    {
        ui->checkBoxAuto->setChecked(false);
    }
}

/**********************    列表框文本改变    *************************/
void LoginDialog::on_comboBoxUserName_currentTextChanged(const QString &arg1)
{
    int Count=0;

    for(int j=0;j<listStringUsnm.count();j++)
    {
        if(ui->comboBoxUserName->currentText() == listStringUsnm[j]) Count++;
    }

    if(Count==0)  ui->lineEditPassWord->clear();
}

/**********************    自动登陆         *************************/
void LoginDialog::on_checkBoxAuto_clicked()
{
    if(!ui->checkBoxRemeber->isChecked())
    {
        ui->checkBoxAuto->setChecked(false);
    }
}

/**********************    记住密码         *************************/
void LoginDialog::on_checkBoxRemeber_clicked()
{
    if(!ui->checkBoxRemeber->isChecked())
    {
        ui->checkBoxAuto->setChecked(false);
    }
}

/**********************    获取用户名         *************************/
QString LoginDialog::getUserName() const
{
    return userName;
}

/**********************    关闭事件         *************************/
void LoginDialog::closeEvent(QCloseEvent *event)
{
    CLIENT->closeSocket();
}

/**********************    注册         *************************/
void LoginDialog::on_pushButtonRegister_clicked()
{

}

/**********************    忘记密码         *************************/
void LoginDialog::on_pushButtonForgetPassWord_clicked()
{

}
