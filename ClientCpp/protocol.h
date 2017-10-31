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
    FRIENDLISYREQ  = 10,   //好友列表请求
    FRIENDLISTINFO = 11,   //好友列表信息
    SELECTFRIENDREQ = 12,  //查找好友
    SELECTFRIENDINFO = 13, //查找好友信息
    ADDFRIENDREQ = 14,     //添加好友请求
    ADDFRIENDINFO = 15,    //添加好友信息

    SUBFRIENDREQ  = 16,    //删除好友
    SUBFRIENDINFO = 17,    //删除好友回馈
    SENDMESSAGEREQ = 18,   //发送消息请求
    SENDMESSAGEINFO = 19,  //发送消息信息
};

}

#endif // PROTOCOL_H
