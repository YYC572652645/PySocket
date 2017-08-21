from protocol import PROTOCOL
from database import DataBase
import globaldef
from globaldef import PERSONINFO

class MessageHandler():
    # 构造函数
    def __init__(self):
        self.commandList = [None] * 100
        self.initCommandList()
        self.dataBase =  DataBase()

    # 所有接收客户端数据函数存储到列表
    def initCommandList(self):
        self.commandList[PROTOCOL.LOGINREQUEST]  = self.receiveLoginData
        self.commandList[PROTOCOL.CLOSESOCKET] = self.receiveCloseRequest
        self.commandList[PROTOCOL.PERSONINFOREQ] = self.receivePersonInfoRequest
        self.commandList[PROTOCOL.SAVEPERSONREQ] = self.receiveSavePersonRequest

    # 所有接收客户端数据函数的调用
    def onCommand(self, protocolNumber, dict, sock):
        self.commandList[protocolNumber](dict, sock)

    # 接收客户端的登录请求
    def receiveLoginData(self, dict, sock):
        countData = self.dataBase.dataSelectUser(dict[globaldef.userName], dict[globaldef.passWord])

        if(countData != None):
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

    # 接收客户端的个人信息请求
    def receivePersonInfoRequest(self, dict, sock):
        personData = self.dataBase.dataSelectPersonData(dict[globaldef.userName])

        if(personData != None):
            for item in personData:
                itemData = item

            data = {}
            data[globaldef.personUserName] = itemData[PERSONINFO.USERNAME]
            data[globaldef.name] = itemData[PERSONINFO.NAME]
            data[globaldef.sex] = itemData[PERSONINFO.SEX]
            data[globaldef.address] = itemData[PERSONINFO.ADDRESS]
            data[globaldef.personInfo] = itemData[PERSONINFO.PERSONINFO]
            data[globaldef.realName] = itemData[PERSONINFO.REALNAME]
            data[globaldef.email] = itemData[PERSONINFO.EMAIL]
            data[globaldef.phone] = itemData[PERSONINFO.PHONE]
            data[globaldef.photo] = itemData[PERSONINFO.PHOTO]

            sock.netSend(PROTOCOL.PERSONINFO, data)

    # 保存个人信息请求
    def receiveSavePersonRequest(self, dict, sock):
        self.dataBase.updatePersonData(dict)








