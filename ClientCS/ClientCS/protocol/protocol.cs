using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Client.protocol
{

enum TCPPROTOCOL
{
    INVALID        = -1, //无用协议
    LOGINREQ       = 0,  //登陆请求
    LOGININFO      = 1,  //服务器数据
    CLOSEREQ       = 2,  //关闭套接字
    PERSONINFOREQ  = 3,  //个人信息请求
    PERSONINFO     = 4,  //个人信息数据
    SAVEPERSONREQ  = 5,  //保存个人信息
};

}
