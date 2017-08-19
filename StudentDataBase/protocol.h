#ifndef PROTOCOL_H
#define PROTOCOL_H


namespace Protocol
{
const static int INVALID = -1;        //无用协议

enum TCPPROTOCOL
{
    LOGINREQUEST = 0,   //登陆请求
    LOGINDATA    = 1,   //服务器数据
    CLOSESOCKET  = 2,   //关闭套接字
};

}

#endif // PROTOCOL_H
