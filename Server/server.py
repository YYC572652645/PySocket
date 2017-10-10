from socketserver  import  BaseRequestHandler
import globaldef
from protocol import PROTOCOL
from messagehandler import MessageHandler
import json

# 处理来自客户端的消息
class DataHandler(BaseRequestHandler):
    # 客户端列表
    userDict = {}

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
            self.userDict[self.address[1]] = connSock

            print("用户", connSock.getpeername(), "进行了连接请求")

            while True:
                # 接收客户端发来的消息
                jsonStr = self.userDict[self.address[1]].recv(globaldef.DATASIZE).decode()

                if(len(jsonStr) <= 0):
                    continue

                print("接收到用户信息", jsonStr)

                # 读取json包
                data = self.readJson(jsonStr)
                self.messageHandler.onCommand(self.protocolNumber, data, self)

                # 如果客户端退出了，则去除该套接字
                if(self.exit == globaldef.EXIT):
                    self.removeSock()
                    break

        except Exception as e:
            self.removeSock()
            print(e.args)

    # 去除已经关闭的Socket
    def removeSock(self):
        print("已关闭...", self.userDict[self.address[1]].getpeername())

        del self.userDict[self.address[1]]

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
        dataDictionary[globaldef.PROTOCOLNAME] = str(protocol)
        self.dataTotal[globaldef.DATANAME] = dataDictionary

        # 编码成json格式的数据
        encodejson = json.dumps(self.dataTotal, ensure_ascii = False)

        print(encodejson)

        self.userDict[self.address[1]].sendall(encodejson.encode())

    # 做一个广播
    def netSendAll(self, protocol, dataDictionary):
        self.dataTotal = {}  # 总的json数据

        # json组包
        dataDictionary[globaldef.PROTOCOLNAME] = str(protocol)
        self.dataTotal[globaldef.DATANAME] = dataDictionary

        # 编码成json格式的数据
        encodejson = json.dumps(self.dataTotal, ensure_ascii=False)

        print(encodejson)

        for key, value in self.userDict.items():
            value.sendall(encodejson.encode())



