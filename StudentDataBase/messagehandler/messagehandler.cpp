#include "messagehandler.h"
#include "protocol.h"
#include <QDebug>
#include "logindialog/logindialog.h"
#include "mainwindow/mainwindow.h"

MessageHandler * MessageHandler::instance = NULL;

/*************************  构造函数                  *********************/
MessageHandler::MessageHandler()
{

    dataMessageList[Protocol::LOGININFO]   = DataMessage("logindata", &MessageHandler::receiveLoginData);
    dataMessageList[Protocol::PERSONINFO] = DataMessage("personinfo", &MessageHandler::receivePersonInfo);

}

/*************************   根据协议号调取对应函数       *********************/
void MessageHandler::onCommand(QMap<QString, QString> &mapData, int protocolNumber)
{
    if(NULL == dataMessageList[protocolNumber].commandhandler)  return;

    if(protocolNumber != Protocol::INVALID && protocolNumber < MSGSIZE)
    {
        (this->*(dataMessageList[protocolNumber].commandhandler))(mapData);
    }
}

/*************************   接收到客户端登录消息    *********************/
void MessageHandler::receiveLoginData(QMap<QString, QString> &mapData)
{
    int count = 0;
    for(auto iter = mapData.begin(); iter != mapData.end(); ++ iter)
    {
        count = iter.value().toInt();
    }

    LOGIN->loginData(count);
}

/*************************   接收到个人信息          *********************/
void MessageHandler::receivePersonInfo(QMap<QString, QString> &mapData)
{
    PersonData personData;

    personData.personUserName = mapData[Protocol::personUserName];
    personData.name = mapData[Protocol::name];
    personData.sex = mapData[Protocol::sex];
    personData.address = mapData[Protocol::address];
    personData.personInfo = mapData[Protocol::personInfo];
    personData.realName = mapData[Protocol::realName];
    personData.email = mapData[Protocol::email];
    personData.phone = mapData[Protocol::phone];
    personData.photo = mapData[Protocol::photo];



    MAINWINDOW->getPersonInfoDialog()->setPersonData(personData);
    MAINWINDOW->getPersonInfoDialog()->showDialog();
}
