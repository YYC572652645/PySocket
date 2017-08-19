#ifndef GLOBALDEF_H
#define GLOBALDEF_H
#include <QString>

#define DATASIZE 100

const static int posMinX=0;
const static int posMaxX=20000;

const static int posMinY=0;
const static int posMaxY=40;

namespace Protocol
{

/***************************   对应0号和1号协议，登录请求，和登陆数据   ****************************/
const static QString userName = "username";
const static QString passWord = "password";

typedef struct LoginData
{
    QString userName;
    QString passWord;
}LoginData;



/***************************      ****************************/



}




#endif // GLOBALDEF_H
