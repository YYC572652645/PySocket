#include "messagehandler.h"
#include "protocol.h"
#include <QDebug>
#include "logindialog/logindialog.h"
#include "mainwindow/mainwindow.h"

MessageHandler * MessageHandler::instance = NULL;

/*************************  构造函数                  *********************/
MessageHandler::MessageHandler()
{
    dataMessageList[Protocol::LOGININFO]  = DataMessage("logindata", &MessageHandler::receiveLoginData);
    dataMessageList[Protocol::PERSONINFO] = DataMessage("personinfo", &MessageHandler::receivePersonInfo);
    dataMessageList[Protocol::FRIENDLISTINFO] = DataMessage("friendinfo", &MessageHandler::receiveFriendList);
    dataMessageList[Protocol::SELECTFRIENDINFO] = DataMessage("friendselectinfo", &MessageHandler::receiveFriendInfo);
    dataMessageList[Protocol::ADDFRIENDINFO] = DataMessage("addfriendinfo", &MessageHandler::receiveAddFriendInfo);
    dataMessageList[Protocol::AGREERIENDINFO] = DataMessage("agreefriendinfo", &MessageHandler::receiveSendMessageInfo);
    dataMessageList[Protocol::SENDMESSAGEINFO] = DataMessage("sendmessageinfo", &MessageHandler::receiveSendMessageInfo);
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
    PERSONINFODIALOG->setData(mapData);
    PERSONINFODIALOG->showDialog();
}

/*************************   接收好友列表          *********************/
void MessageHandler::receiveFriendList(QMap<QString, QString> &mapData)
{
    FRIENDMANGER->setData(mapData);
    FRIENDMANGER->showWidget();
}

/*************************   接收查询好友信息          *********************/
void MessageHandler::receiveFriendInfo(QMap<QString, QString> &mapData)
{
    FRIENDMANGER->getAddFriend()->setData(mapData);
}

/*************************   接收添加好友信息          *********************/
void MessageHandler::receiveAddFriendInfo(QMap<QString, QString> &mapData)
{
    FRIENDMANGER->setAddFriendInfo(mapData);
}

/*************************   接收发送信息          *********************/
void MessageHandler::receiveSendMessageInfo(QMap<QString, QString> &mapData)
{
    FRIENDMANGER->setMessage(mapData);
}

/*************************   好友添加结果信息          *********************/
void MessageHandler::receiveAgreeFriendInfo(QMap<QString, QString> &mapData)
{

}
