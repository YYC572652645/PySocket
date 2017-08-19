#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QHostAddress>
#include <QThread>

#define CLIENT Client::getInstance()

class Client : public QObject
{
    Q_OBJECT
public:
    static Client * getInstance()
    {
        if(NULL == instance)
        {
            instance = new Client();
        }

        return instance;
    }

    void connectServer();             //连接服务器

public slots:
    void displayError(QAbstractSocket::SocketError); //显示错误信息
    void closeSocket();                              //关闭Socket
    void readData();                                 //读取数据

private:
    static Client * instance;         //单例模式
    QTcpSocket * tcpSocket;           //客户端套接字

    int protocolNumber;               //协议号
    QMap<QString, QString>mapData;    //存储接收到的JSON数据

public:
    void netSend(int protocol, QMap<QString, QString> &mapData);    //组合json数据，然后发送
    bool isConnect();

private:
    Client();
    ~Client();
    void readJson(QString arrayData);  //读取json数据

};

#endif // CLIENT_H
