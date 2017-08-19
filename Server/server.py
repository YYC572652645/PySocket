from socketserver  import  BaseRequestHandler
import globaldef
from protocol import PROTOCOL
from messagehandler import MessageHandler
import json

# 处理来自客户端的消息
class DataHandler(BaseRequestHandler):
    # 客户端列表
    userList = []

    # 处理客户端请求
    def handle(self):
        try:
            # 初始化
            self.messageHandler = MessageHandler()

            # 接收客户端的Socket
            connSock = self.request
            self.flage = False;
            self.index = 0

            #判断该用户是否已经连接
            for user in self.userList:
                if (user == connSock):
                    self.flage = True

            # 如果不存在则添加至列表
            if(self.flage == False) :
                self.userList.append(self.request)

            #获取该用户的在列表中的Socket下表
            self.index = self.userList.index(connSock)

            while True:
                # 接收客户端发来的消息
                jsonStr = self.userList[self.index].recv(globaldef.DATASIZE).decode()

                if(len(jsonStr) <= 0):
                    continue

                # 读取json包
                data = self.readJson(jsonStr)
                self.messageHandler.onCommand(self.protocolNumber, data, self)

                if(data == globaldef.EXIT):
                    self.removeSock()
                    break

        except Exception as e:
            self.removeSock()
            print(e.args)

    # 去除已经关闭的Socket
    def removeSock(self):
        self.userList.remove(self.userList[self.index])

    # 读取json数据
    def readJson(self, jsonStr):
        data = json.loads(jsonStr)
        data = data["data"]

        self.protocolNumber = int(data[globaldef.PROTOCOLNAME])
        del data[globaldef.PROTOCOLNAME]

        return data

    # 向客户端发送消息
    def netSend(self, protocol, dataDictionary):
        self.dataTotal = {}       # 总的json数据

        # json组包
        dataDictionary[globaldef.PROTOCOLNAME] = protocol
        self.dataTotal[globaldef.DATANAME] = dataDictionary

        # 编码成json格式的数据
        encodejson = json.dumps(self.dataTotal, ensure_ascii = False)

        self.userList[self.index].sendall(encodejson.encode())



