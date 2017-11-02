#****************************************************
# 作者：YYC
# 功能：数据库简单工厂模式
# 日期：2017-11-02
#****************************************************

from db.frienddata import FriendData
from db.persondata import PersonData

from globaldef import DATABASETYPE

class DataBaseFactory():

    def createDataBase(self, type):
        dataBase = None

        # 个人信息数据库
        if(DATABASETYPE.PERSONDATA == type):
            dataBase =  PersonData()

        # 好友信息数据库
        elif(DATABASETYPE.FRIENDDATA == type):
            dataBase = FriendData()

        return dataBase