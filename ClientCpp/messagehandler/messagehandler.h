#ifndef MESSAGEHANDLER_H
#define MESSAGEHANDLER_H
#include <QMap>
#include "globaldef.h"
#define MESSAGEHANDLE MessageHandler::getInstyance()

class MessageHandler
{
public:
    static MessageHandler * getInstyance()
    {
        if(NULL == instance)
        {
            instance = new MessageHandler();
        }
        return instance;
    }

public:
    void onCommand(QMap<QString, QString> &mapData, int protocolNumber);

private:
    static MessageHandler * instance;

    MessageHandler();
    ~MessageHandler();

    //使用函数指针
    typedef void (MessageHandler::*CommandFunc)(QMap<QString, QString> &mapData);

    typedef struct DataMessage
    {
        DataMessage() : messageName(""),commandhandler(0) {}
        DataMessage(QString message, CommandFunc func) : messageName(message),commandhandler(func) {}

        QString messageName;
        CommandFunc commandhandler;
    }DataMessage;

    DataMessage dataMessageList[MSGSIZE];

private:
    /********************************   接收函数      ******************************/
    void receiveLoginData(QMap<QString, QString> &mapData);
    void receivePersonInfo(QMap<QString, QString> &mapData);
    void receiveFriendList(QMap<QString, QString> &mapData);
};

#endif // MESSAGEHANDLER_H
