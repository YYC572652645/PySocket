#****************************************************
# 作者：YYC
# 功能：全局定义
# 日期：2017-10-28
#****************************************************

ROLE = None                    # 用户全局对象

FUNSIZE = 100                  # 列表函数长度
DATASIZE = 4096 * 1024         # 接收消息的最大长度
IP = "127.0.0.1"               # IP地址
PORT = 8080                    # 端口号
EXIT = "exit"                  # 退出
PROTOCOLNAME = "protocol"      # 协议
DATANAME = "data"              # 协议数据
TABLEUSER = "user"             # user表
TABLEPERSONDATA = "persondata" # persondata表
TABLEFRIENDDATA = "friend"      # friend表

#***************************   对应0号和1号协议，登录请求，和登陆数据   ****************************#
userName  = "username"
passWord  = "password"
countData = "countData"
user = "user"

#***************************   对应3号和4号协议，登录请求，和登陆数据   ****************************#
personUserName  = "username"
name  = "name"
sex = "sex"
address = "address"
personInfo = "personinfo"
realName = "realname"
email = "email"
phone = "phone"
photo = "photo"

# 数据库对象类型
class DATABASETYPE:
    PERSONDATA = 0
    FRIENDDATA = 1

# personinfo数据库字段
class PERSONINFO:
    USERNAME   = 0      # 用户名
    NAME       = 1      # 昵称
    SEX        = 2      # 性别
    ADDRESS    = 3      # 地址
    PERSONINFO = 4      # 个人信息
    REALNAME   = 5      # 真实姓名
    EMAIL      = 6      # 邮箱
    PHONE      = 7      # 电话
    PHOTO      = 8      # 头像
