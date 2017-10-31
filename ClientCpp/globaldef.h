#ifndef GLOBALDEF_H
#define GLOBALDEF_H
#include <QString>
#include "client/client.h"
#include "mainwindow/mainwindow.h"
#include "logindialog/logindialog.h"
#include "messagebox/messagedialog.h"
#include "protocol.h"

#define MSGSIZE  100
#define BUFFERSIZE 4096 * 1024

#define DATA(str) new QTableWidgetItem(str)

#define LOADQSS(qssFile)                      \
{                                             \
    QString strQss;                           \
    QFile file(qssFile);                      \
    file.open(QFile::ReadOnly);               \
    if(file.isOpen())                         \
    {                                         \
        strQss=QLatin1String(file.readAll()); \
        qApp->setStyleSheet(strQss);          \
        file.close();                         \
    }                                         \
}

const static int posMinX=0;
const static int posMaxX=20000;

const static int posMinY=0;
const static int posMaxY=40;

const static int TITLEBARHEIGHT = 50;
const static int TITLECONTROLWIDTH = 40;


const static QString APPICOPATH   = ":/image/image/image.png";    //Logo
const static QString SUCCESSIMAGE = ":/image/image/ok.png";       //成功图片
const static QString FAILIMAGE    = ":/image/image/fail.png";     //失败图片
const static QString SYSTEMINFO    = "系统提示";                    //失败图片


enum NODETEXT
{
    PERSONINFO,
    MYFRIEND,
    MYACCOUNT,
    VIP,
    LOGOUT,
};

namespace Protocol
{

/***************************   对应0号和1号协议，登录请求，和登陆数据   ****************************/
const static QString userName = "username";
const static QString passWord = "password";


/***************************   对应3号和4号协议，个人信息请求，和个人信息数据   ****************************/
const static QString personUserName  = "username";
const static QString name            = "name";
const static QString sex             = "sex";
const static QString address         = "address";
const static QString personInfo      = "personinfo";
const static QString realName        = "realname";
const static QString email           = "email";
const static QString phone           = "phone";
const static QString photo           = "photo";


/***************************   好友相关   ****************************/
const static QString sendContext  = "text";
const static QString user = "user";
const static QString font = "font";
const static QString fontSize = "fontSize";
const static QString fontColor = "fontColor";
}




#endif // GLOBALDEF_H
