#****************************************************
# 作者：YYC
# 功能：通信协议号
# 日期：2017-10-28
#****************************************************

INVALID = -1        #无用协议

class PROTOCOL:
    LOGINREQUEST  = 0  # 登陆请求
    LOGINDATA     = 1  # 服务器数据
    CLOSESOCKET   = 2  # 关闭套接字
    PERSONINFOREQ = 3  # 个人信息请求
    PERSONINFO    = 4  # 个人信息数据
    SAVEPERSONREQ = 5  # 保存个人信息

    #*************   好友相关   *************
    FRIENDLISTREQ = 10    # 好友列表请求
    FRIENDLISTINFO = 11    # 好友列表信息
    ADDFRIENDREQ  = 12     # 添加好友
    ADDFRIENDINFO = 13     # 添加好友回馈
    SUBFRIENDREQ  = 14     # 删除好友
    SUBFRIENDINFO = 15     # 删除好友回馈
    SELECTFRIENDREQ = 16   # 查询好友
    SELECTFRIENDINFO = 17  # 查询好友回馈


