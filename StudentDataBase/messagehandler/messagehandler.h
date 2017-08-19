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
    /*************************************************************************************************/

    MessageHandler();
    ~MessageHandler();

    typedef void (MessageHandler::*CommandFunc)(QMap<QString, QString> &mapData);

    typedef struct DataMessage
    {
        char messageName[DATASIZE];
        CommandFunc commandhandler;
    }DataMessage;

    DataMessage *getCommandMessage();

    void receiveLoginData(QMap<QString, QString> &mapData);
};

#endif // MESSAGEHANDLER_H
