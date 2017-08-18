#include "client.h"
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>
#include "globaldef.h"
/**********************    构造函数     *************************/
Client::Client()
{
    //实例化套接字对象
    tcpSocket = new QTcpSocket(this);

    //连接信号与槽，如果发现运行中套接字出现错误，则输出错误信息
    connect(tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(displayError(QAbstractSocket::SocketError)));
    connect(tcpSocket, SIGNAL(readyRead()),this, SLOT(readData()));

    this->connectServer();
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

void Client::readData()
{
    while(tcpSocket->bytesAvailable() > 0)
    {
        QByteArray data;

        data.resize(tcpSocket->bytesAvailable());

        tcpSocket->read(data.data(), data.size());

        QString str = data.data();

        emit sendData(str);
    }
}

/**********************    组合Json数据     *************************/
void Client::writeJson(int protocol)
{
    QJsonObject jsonTotal;
    QJsonObject jsonData;

    jsonData.insert("protocol", QString::number(protocol));
    jsonData.insert("username", "1305120114");
    jsonData.insert("password", "1305120114");

    jsonTotal.insert("data", jsonData);

    QJsonDocument document;
    document.setObject(jsonTotal);

    QByteArray arrayData = document.toJson();

    qDebug()<<arrayData;
    this->netSend(arrayData);
}

/**********************    向服务端发送请求     *************************/
void Client::netSend(QByteArray &arrayData)
{
    tcpSocket->write(arrayData, arrayData.length());
}
