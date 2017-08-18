#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QHostAddress>
#include <QThread>

class Client : public QObject
{
    Q_OBJECT
public:
    Client();
    ~Client();

    void netSend(QByteArray &arrayData);  //向服务端发送请求

public slots:
    void displayError(QAbstractSocket::SocketError);
    void readData();

private:
    QTcpSocket * tcpSocket;           //客户端套接字
    void connectServer();             //连接服务器
    int protocolNumber;               //协议号
    QMap<QString, QString>mapData;    //存储接收到的JSON数据

public:
    void writeJson(int protocol, QMap<QString, QString> &mapData);         //组合json数据
    void readJson(QString arrayData);                                   //读取json数据
};

#endif // CLIENT_H
