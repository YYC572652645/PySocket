#****************************************************
# 作者：YYC
# 功能：接收消息
# 日期：2017-10-28
#****************************************************

from socketserver  import  BaseRequestHandler
import globaldef
from server.protocol import PROTOCOL
from server.messagehandler import MessageHandler
from role.role import Role
import json
import time


# 处理来自客户端的消息
class DataHandler(BaseRequestHandler):
    # 客户端列表
    data = {}

    # 创建用户管理对象
    role = Role()

    # 处理客户端请求
    def handle(self):
        try:
            # 初始化
            self.messageHandler = MessageHandler()

            # 接收客户端的Socket
            connSock = self.request
            self.exit = ""

            # 获取客户端的IP
            self.address = connSock.getpeername()

            print("用户", connSock.getpeername(), "进行了连接请求")

            while True:
                # 接收客户端发来的消息
                jsonStr = connSock.recv(globaldef.DATASIZE).decode()

                if(len(jsonStr) <= 0):
                    continue

                print("接收到用户信息", jsonStr)

                # 读取json包
                self.data = self.readJson(jsonStr)
                self.role.addRole(self.data.get(globaldef.user), connSock)
                self.messageHandler.onCommand(self.protocolNumber, self.data, self)

                # 如果客户端退出了，则去除该套接字
                if(self.exit == globaldef.EXIT):
                    self.removeSock()
                    break

                # 休眠0.1秒，减小cpu消耗
                time.sleep(0.1)

        except Exception as e:
            self.removeSock()
            print("出错了" , e.args)

    # 去除已经关闭的Socket
    def removeSock(self):
        try:
            print("已关闭...", self.role.getRole(self.data.get(globaldef.user)).getpeername())

            self.role.deleteRole(self.data.get(globaldef.user))

        except Exception as e:
            print(e.args)

    # 读取json数据
    def readJson(self, jsonStr):
        data = json.loads(jsonStr)
        data = data["data"]

        self.protocolNumber = int(data[globaldef.PROTOCOLNAME])

        del data[globaldef.PROTOCOLNAME]

        return data

    # 向客户端发送消息
    def netSend(self, protocol, dataDictionary, user = None):
        try:
            self.dataTotal = {}       # 总的json数据

            # json组包
            dataDictionary[globaldef.PROTOCOLNAME] = str(protocol)
            self.dataTotal[globaldef.DATANAME] = dataDictionary

            # 编码成json格式的数据
            encodejson = json.dumps(self.dataTotal, ensure_ascii = False)

            print(encodejson)

            if(user == None):
                self.role.getRole(self.data.get(globaldef.user)).sendall(encodejson.encode())
            else:
                self.role.getRole(user).sendall(encodejson.encode())

        except Exception as e:
            print(e.args)

    # 做一个广播
    def netSendAll(self, protocol, dataDictionary):
        self.dataTotal = {}  # 总的json数据

        # json组包
        dataDictionary[globaldef.PROTOCOLNAME] = str(protocol)
        self.dataTotal[globaldef.DATANAME] = dataDictionary

        # 编码成json格式的数据
        encodejson = json.dumps(self.dataTotal, ensure_ascii=False)

        print(encodejson)

        for key, value in self.role.getAllRole().items():
            value.sendall(encodejson.encode())