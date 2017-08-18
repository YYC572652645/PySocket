from socketserver  import  BaseRequestHandler
from myjson import MyJson
import globaldef
from protocol import PROTOCOL


# 处理来自客户端的消息
class DataHandler(BaseRequestHandler):

    userList = []
    def handle(self):
        try:
            # 接收客户端的Socket
            self.flage = False;
            self.index = 0

            connSock = self.request

            #判断该用户是否已经连接
            for user in self.userList:
                if (user == connSock):
                    self.flage = True

            # 如果不存在则添加至列表
            if(self.flage == False) :
                self.userList.append(self.request)

            #获取该用户的在列表中的Socket下表
            self.index = self.userList.index(connSock)

            print(self.index)

            while True:
                # 接收客户端发来的消息
                data = self.userList[self.index].recv(globaldef.DATASIZE).decode()

                if(len(data) <= 0):
                    break

                if(data == globaldef.EXIT):
                    self.removeSock()
                    break

                # 发送消息
                self.netSend(data)

                print("接收到消息", data)

        except Exception as e:
            self.removeSock()
            print(e.args)

    # 向客户端发送消息
    def netSend(self, data):
        self.userList[self.index].sendall(data.encode())

    # 去除已经关闭的Socket
    def removeSock(self):
        self.userList.remove(self.userList[self.index])


