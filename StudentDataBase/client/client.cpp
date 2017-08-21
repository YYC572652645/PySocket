#include "client.h"
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>
#include "globaldef.h"
#include "protocol.h"
#include "messagehandler/messagehandler.h"

Client * Client::instance = NULL;


/**********************    构造函数     *************************/
Client::Client(): protocolNumber(Protocol::INVALID)
{
    //实例化套接字对象
    tcpSocket = new QTcpSocket(this);

    //连接信号与槽
    connect(tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(displayError(QAbstractSocket::SocketError)));
    connect(tcpSocket, SIGNAL(readyRead()),this, SLOT(readData()));
}

/**********************    析构函数     *************************/
Client::~Client()
{
    delete tcpSocket;
}

/**********************    连接服务器     *************************/
void Client::connectServer()
{
    tcpSocket->abort();                                       //终止过去的连接
    tcpSocket->connectToHost(QHostAddress("127.0.0.1"), 8080);//连接到服务器
}

/**********************    输出错误信息     *************************/
void Client::displayError(QAbstractSocket::SocketError)
{
    qDebug()<<tcpSocket->errorString();      //输出错误提示
    tcpSocket->close();                      //关闭套接字
}

/**********************    关闭Socket     *************************/
void Client::closeSocket()
{
    QMap<QString, QString> mapData;

    this->netSend(Protocol::CLOSEREQ, mapData);

    tcpSocket->close();
}

/**********************    读取数据     *************************/
void Client::readData()
{
    QString str;
    while(tcpSocket->bytesAvailable() > 0)
    {
        QByteArray data;

        data.resize(tcpSocket->bytesAvailable());

        int size = tcpSocket->read(data.data(), data.size());

        str += data.data();

        if(!str.isEmpty())
        {
            this->readJson(str);

            str.clear();

            if(protocolNumber == Protocol::INVALID) continue;

            MESSAGEHANDLE->onCommand(mapData, protocolNumber);
        }
    }
}

/**********************    是否连接到服务器     *************************/
bool Client::isConnect()
{
    return tcpSocket->isWritable();
}

/**********************    组合json数据，然后发送     *************************/
void Client::netSend(int protocol, QMap<QString, QString> &mapData)
{
    QJsonObject jsonTotal;
    QJsonObject jsonData;

    jsonData.insert("protocol", QString::number(protocol));

    for(auto iter = mapData.begin(); iter != mapData.end(); ++ iter)
    {
        jsonData.insert(iter.key(), iter.value());
    }

    jsonTotal.insert("data", jsonData);

    QJsonDocument document;
    document.setObject(jsonTotal);

    QByteArray arrayData = document.toJson();

    tcpSocket->write(arrayData, arrayData.length());
}

/**********************    读取Json数据     *************************/
void Client::readJson(QString arrayData)
{
    mapData.clear();
    protocolNumber = Protocol::INVALID;
    QJsonParseError err;
    QJsonDocument jsonDom = QJsonDocument::fromJson(arrayData.toUtf8(), &err);

    QJsonObject jsonObject = jsonDom.object();
    QJsonValue jsonValue = jsonObject.value(QString("data"));

    QJsonObject objectItem = jsonValue.toObject();
    QStringList stringList = objectItem.keys();

    for(int i = 0; i < stringList.size(); i ++)
    {
        mapData[stringList[i]] = objectItem[stringList[i]].toString();
    }

    auto iter = mapData.find("protocol");

    protocolNumber = iter.value().toInt();
    mapData.remove("protocol");
}
