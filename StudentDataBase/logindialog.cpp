#include "logindialog.h"
#include "ui_logindialog.h"
#include "client.h"
#include "globaldef.h"

/**********************    鼠标作用域     *************************/
using namespace std;
const static int posMinX=0;
const static int posMaxX=20000;

const static int posMinY=0;
const static int posMaxY=40;


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
            if(ui->comboBoxUserName->currentText()==listStringUsnm[i]&&listStringRemember[i]=="1")
            {

                ui->lineEditPassWord->setText(listStringPsd[i]);
                ui->checkBoxRemeber->setChecked(true);
                if(listStringAuto[i]=="1")
                {
                    ui->checkBoxAuto->setChecked(true);
                }
            }
        }
    }

    minButton=new QToolButton(this);   //最小化按钮
    closeButton=new QToolButton(this); //关闭按钮
    int width=this->width();           //获取软件占得像素大小
    isMousePressed=false;              //鼠标点击标志位

    this->setWindowFlags(Qt::FramelessWindowHint);                                          //去掉标题栏
    QDesktopWidget *desktop = QApplication::desktop();                                      //程序显示在屏幕中间
    move((desktop->width()- this->width()) / 2, (desktop->height() - this->height()) / 2);  //程序显示在屏幕中间

    /*************************************加载图标********************************/
    QPixmap closePix=style()->standardPixmap(QStyle::SP_TitleBarCloseButton);
    closeButton->setIcon(closePix);
    QPixmap minPix =style()->standardPixmap(QStyle::SP_TitleBarMinButton);
    minButton->setIcon(minPix);

    /*************************************加载位置********************************/
    minButton->setGeometry(width - 60, 0, 30, 30);
    closeButton->setGeometry(width - 30, 0, 30, 30);

    setPalette(QPalette(Qt::darkCyan));                      //设置背景色
    setAutoFillBackground(true);
    ui->lineEditPassWord->setEchoMode(QLineEdit::Password);  //设置为加密形式

    /*************************************信号与槽连接******************************/
    connect(minButton,SIGNAL(clicked(bool)),SLOT(actionMin()));          //最小化按钮
    connect(closeButton,SIGNAL(clicked(bool)),SLOT(actionClose()));      //关闭按钮

    /*************************************背景色与父对话框一样************************/
    minButton->setStyleSheet("background-color:transparent");
    closeButton->setStyleSheet("background-color:transparent");

    //客户端运行线程
    client = new Client();
    connect(client, SIGNAL(sendData(QString)), this, SLOT(readJson(QString)));

    client->writeJson(Protocol::LOGINREQUEST);
}

/**********************    析构函数        *************************/
LoginDialog::~LoginDialog()
{
    delete client;
    delete ui;
}

/**********************    登录按钮        *************************/
void LoginDialog::on_pushButtonLogin_clicked()
{
    int Count=0;
    QString tempRem,tempAuto;


    if(true)
    {
        //判断出输入的用户名是否存在，如果存在则不写入xml中，如果不存在则写入xml中
        for(int i=0;i<listStringUsnm.count();i++)
        {
            if(ui->comboBoxUserName->currentText()==listStringUsnm[i]&&ui->lineEditPassWord->text()==listStringPsd[i])
            {
                Count ++;
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
        if(Count == 0) writeXml();

        accept();
    }
    else
    {
        QMessageBox::information(this,tr("系统提示"),tr("登录失败"));//登录失败
    }
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
    mousePosition=event->pos();

    if(mousePosition.x()<=posMinX)
    {
        return;
    }
    if(mousePosition.x() >= posMaxX)
    {
        return;
    }
    if(mousePosition.y() <= posMinY)
    {
        return;
    }
    if(mousePosition.y() >= posMaxY)
    {
        return;
    }

    isMousePressed=true;
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
    QDomElement root=dom.documentElement();
    QDomElement user=dom.createElement("user");
    QDomAttr    id=dom.createAttribute("id");
    QDomElement usernm=dom.createElement("username");
    QDomElement passwd=dom.createElement("password");
    QDomElement remember=dom.createElement("remember");
    QDomElement autoLogin=dom.createElement("autologin");

    QDomText text;

    QString num=root.lastChild().toElement().attribute("id");  //获取xml文件最后一个id的大小是多少
    int count=num.toInt()+1;
    id.setValue(QString::number(count));                       //将id+1后添加到新建的用户中
    user.setAttributeNode(id);

    //将从界面获取的用户名和密码，加到xml文件中
    text=dom.createTextNode(ui->comboBoxUserName->currentText());
    usernm.appendChild(text);
    text=dom.createTextNode(ui->lineEditPassWord->text());
    passwd.appendChild(text);
    if(ui->checkBoxRemeber->isChecked())
    {
        text=dom.createTextNode("1");
        remember.appendChild(text);
    }
    else
    {
        text=dom.createTextNode("0");
        remember.appendChild(text);
    }

    if(ui->checkBoxAuto->isChecked())
    {
        text=dom.createTextNode("1");
        autoLogin.appendChild(text);
    }
    else
    {
        text=dom.createTextNode("0");
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
    dom.save(out,4);
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
    QFile *file=new QFile("login.xml");
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
            for(int i=0;i<list.count();i++)
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
    if(!f.open(QIODevice::WriteOnly|QIODevice::Truncate))
    {
        return;
    }

    QTextStream out(&f);
    dom.save(out,4);
    f.close();

}

/**********************    点击列表框       *************************/
void LoginDialog::on_comboBoxUserName_activated(const QString &arg1)
{
    int Count=0;
    int tempCount=0;
    for(int i=0;i<ui->comboBoxUserName->count();i++)
    {
        //将listFloat存储的信息读取出来，进行实时改变lineEdit的密码
        if(ui->comboBoxUserName->currentText()==listStringUsnm[i]&&listStringRemember[i]=="1")
        {
            Count++;
            ui->checkBoxRemeber->setChecked(true);
            ui->lineEditPassWord->setText(listStringPsd[i]);
            if(listStringAuto[i]=="1")
            {
                ui->checkBoxAuto->setChecked(true);
                tempCount++;
            }
        }
    }

    if(Count==0)
    {
        ui->checkBoxRemeber->setChecked(false);
        ui->lineEditPassWord->clear();
    }
    if(tempCount==0)
    {
        ui->checkBoxAuto->setChecked(false);
    }
}

/**********************    列表框文本改变    *************************/
void LoginDialog::on_comboBoxUserName_currentTextChanged(const QString &arg1)
{
    int Count=0;
    //判断出如果不是已经在此登录过的密码,则清空
    for(int j=0;j<listStringUsnm.count();j++)
    {
        if(ui->comboBoxUserName->currentText()==listStringUsnm[j])
        {
            Count++;
        }
    }
    if(Count==0)
    {
        ui->lineEditPassWord->clear();
    }
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

/**********************    读取Json数据     *************************/
void LoginDialog::readJson(QString arrayData)
{
    QJsonDocument jsonDom = QJsonDocument::fromJson(arrayData.toUtf8());
    QJsonObject jsonObject = jsonDom.object();
    QJsonValue jsonValue = jsonObject.value(QString("data"));


    QJsonObject objectItem = jsonValue.toObject();

    qDebug()<<objectItem["username"].toString();
    qDebug()<<objectItem["password"].toString();
}
