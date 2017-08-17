import socket
import globaldef
import time

# 客户端代码连接服务器
class  Client():
    def connServer(self):
        try:
            # 连接服务端
            self.dataConn()

            # while (True):
            #     sendData = input("请输入发送信息:")         # 输入需要发送的消息
            #     self.dataSend(sendData)                     # 发送输入的消息
            #     self.dataRecv()                             # 接收客户端消息
            #     if (sendData == globaldef.EXIT):
            #         break

        except Exception as e:
            print(e.args)
            self.sock.close()

    # 连接服务端
    def dataConn(self):
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)      # 使用套接字连接服务器
        self.sock.setsockopt(socket.SOL_SOCKET, socket.SO_KEEPALIVE, 1)    # 客户端开启心跳维护
        self.sock.connect((globaldef.IP, globaldef.PORT))                  # 指定IP，PORT连接服务端


    # 接收客户端消息
    def dataRecv(self):
        data = self.sock.recv(globaldef.DATASIZE).decode()
        print("接收到消息...", data)

    # 发送客户端消息
    def dataSend(self, data):
        self.sock.sendall(data.encode())