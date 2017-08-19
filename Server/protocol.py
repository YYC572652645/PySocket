#通信协议号

INVALID = -1        #无用协议

class PROTOCOL:
    LOGINREQUEST = 0, # 登陆请求
    LOGINDATA = 1,    # 服务器数据
    CLOSESOCKET = 2,  # 关闭套接字

