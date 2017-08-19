#include "messagehandler.h"
#include "protocol.h"
#include <QDebug>
#include "logindialog/logindialog.h"

MessageHandler * MessageHandler::instance = NULL;

MessageHandler::MessageHandler()
{

}

MessageHandler::DataMessage *MessageHandler::getCommandMessage()
{
    static DataMessage setDataMessage[] =
    {
        {"logindata"  , &MessageHandler::receiveLoginData},
    };

    return &setDataMessage[0];
}


void MessageHandler::onCommand(QMap<QString, QString> &mapData, int protocolNumber)
{
    DataMessage *messageList = this->getCommandMessage();

    if(NULL != messageList && protocolNumber != Protocol::INVALID)
    {
        (this->*messageList[protocolNumber].commandhandler)(mapData);
    }

    delete messageList;
}

void MessageHandler::receiveLoginData(QMap<QString, QString> &mapData)
{
    int count = 0;
    for(auto iter = mapData.begin(); iter != mapData.end(); ++ iter)
    {
        count = iter.value().toInt();
    }

    LOGIN->loginData(count);
}
