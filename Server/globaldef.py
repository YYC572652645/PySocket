

DATASIZE = 2048                # 接收消息的最大长度
IP = "127.0.0.1"               # IP地址
PORT = 8080                    # 端口号
EXIT = "exit"                  # 退出
PROTOCOLNAME = "protocol"      # 协议
DATANAME = "data"              # 协议数据
TABLEUSER = "user"             # user表

#***************************   对应0号和1号协议，登录请求，和登陆数据   ****************************#
userName = "username";
passWord = "password";


class UserData():
    def __init__(self):
        self.userName = ""
        self.passWord = ""