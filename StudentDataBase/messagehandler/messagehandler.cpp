#include "messagehandler.h"
#include "protocol.h"
#include <QDebug>
#include "logindialog/logindialog.h"

MessageHandler * MessageHandler::instance = NULL;

/*************************  构造函数                  *********************/
MessageHandler::MessageHandler()
{

}

/*************************   获取函数结构体数组首地址    *********************/
MessageHandler::DataMessage *MessageHandler::getCommandMessage()
{
    static DataMessage setDataMessage[] =
    {
        {"logindata"  , &MessageHandler::receiveLoginData},
    };

    return &setDataMessage[0];
}

/*************************   根据协议号调取对应函数       *********************/
void MessageHandler::onCommand(QMap<QString, QString> &mapData, int protocolNumber)
{
    DataMessage *messageList = this->getCommandMessage();

    if(NULL != messageList && protocolNumber != Protocol::INVALID)
    {
        (this->*messageList[protocolNumber].commandhandler)(mapData);
    }

    delete messageList;
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
