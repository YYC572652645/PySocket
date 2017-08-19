from protocol import PROTOCOL
from database import DataBase
import globaldef

class MessageHandler():
    # 构造函数
    def __init__(self):
        self.commandList = []
        self.initCommandList()
        self.dataBase =  DataBase()

    # 所有接收客户端数据函数存储到列表
    def initCommandList(self):
        self.commandList.append(self.receiveLoginData)
        self.commandList.append(None)
        self.commandList.append(self.receiveCloseRequest)

    # 所有接收客户端数据函数的调用
    def onCommand(self, protocolNumber, dict, sock):
        self.commandList[protocolNumber](dict, sock)

    # 接收客户端的登录请求
    def receiveLoginData(self, dict, sock):

        countData = self.dataBase.dataSelect(dict[globaldef.userName], dict[globaldef.passWord])

        count = 0
        for item in countData:
            for element in item:
                count = element

        data = {}
        data[globaldef.countData] = str(count)
        sock.netSend(PROTOCOL.LOGINDATA, data)

        # 接收客户端的关闭请求
    def receiveCloseRequest(self, dict, sock):
        sock.exit = globaldef.EXIT



