#ifndef PROTOCOL_H
#define PROTOCOL_H


namespace Protocol
{
const static int INVALID = -1;        //无用协议

enum TCPPROTOCOL
{
    LOGINREQ       = 0,  //登陆请求
    LOGININFO      = 1,  //服务器数据
    CLOSEREQ       = 2,  //关闭套接字
    PERSONINFOREQ  = 3,  //个人信息请求
    PERSONINFO     = 4,  //个人信息数据
    SAVEPERSONREQ  = 5,  //保存个人信息


    /*****************   好友相关   ***************/
    FRIENDLISYREQ  = 10,  //好友列表请求
    FRIENDLISTINFO = 11,  //好友列表信息
};

}

#endif // PROTOCOL_H
