#ifndef GLOBALDEF_H
#define GLOBALDEF_H
#include <QString>

#define MSGSIZE  100
#define BUFFERSIZE 4096 * 1024

const static int posMinX=0;
const static int posMaxX=20000;

const static int posMinY=0;
const static int posMaxY=40;

namespace Protocol
{

/***************************   对应0号和1号协议，登录请求，和登陆数据   ****************************/
const static QString userName = "username";
const static QString passWord = "password";


/***************************   对应3号和4号协议，个人信息请求，和个人信息数据   ****************************/
const static QString personUserName  = "username";
const static QString name  = "name";
const static QString sex = "sex";
const static QString address = "address";
const static QString personInfo = "personinfo";
const static QString realName = "realname";
const static QString email = "email";
const static QString phone = "phone";
const static QString photo = "photo";


}




#endif // GLOBALDEF_H
