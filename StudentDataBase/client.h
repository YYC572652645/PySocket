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

signals:
    void sendData(QString);

public slots:
    void displayError(QAbstractSocket::SocketError);
    void readData();

private:
    QTcpSocket * tcpSocket;  //客户端套接字
    void connectServer();    //连接服务器

public:
    void writeJson(int protocol);         //组合json数据
    void readJson(QByteArray arrayData);  //读取json数据
};

#endif // CLIENT_H
