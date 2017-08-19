import protocol
class MessageHandler():
    # 构造函数
    def __init__(self):
        self.commandList = []
        self.initCommandList()

    # 所有接收客户端数据函数存储到列表
    def initCommandList(self):
        self.commandList.append(self.receiveLoginData)

    # 所有接收客户端数据函数的调用
    def onCommand(self, protocolNumber, dict):
        print(protocolNumber, dict)
        self.commandList[protocolNumber](dict)

    # 接收客户端的登录请求
    def receiveLoginData(self, dict):
        for item in dict.items():
            pass



