#****************************************************
# 作者：YYC
# 功能：个人信息数据库
# 日期：2017-10-28
#****************************************************

import sqlite3
import globaldef
from db.database import DataBase

class PersonData(DataBase):
    # 构造函数
    def __init__(self):
        self.dataConn()

    # 查询登录数据
    def dataSelectUser(self, userName, passWord):
        try:
            self.dataConn()

            str = "select count(*) from " + globaldef.TABLEUSER + " where username = '" + userName + "' and password = '" + passWord + "';"
            data = self.cursor.execute(str)
            self.conn.commit()
            return data
        except Exception as e:
            print(e.args)
            return None

    # 查询个人信息数据
    def dataSelectPersonData(self, userName):
        try:
            self.dataConn()

            str = "select * from " + globaldef.TABLEPERSONDATA + "  where username = '" + userName + "';"
            data = self.cursor.execute(str)
            self.conn.commit()
            return data
        except Exception as e:
            print(e.args)
        return None

    # 插入数据
    def insertData(self):
        pass

    # 更新个人信息数据
    def updatePersonData(self, dict):
        try:
            self.dataConn()

            str  = "update "             + globaldef.TABLEPERSONDATA       + " set "
            str += "name = '"            + dict[globaldef.name]  + "', "
            str += "sex = '"             + dict[globaldef.sex]             + "', "
            str += "address = '"         + dict[globaldef.address]         + "', "
            str += "personinfo = '"      + dict[globaldef.personInfo]      + "', "
            str += "realname = '"        + dict[globaldef.realName]        + "', "
            str += "email = '"           + dict[globaldef.email]           + "', "
            str += "phone = '"           + dict[globaldef.phone]           + "', "
            str += "photo = '"           + dict[globaldef.photo]           + "' "
            str += "where username = '"  + dict[globaldef.personUserName]  + "';"

            self.cursor.execute(str)
            self.conn.commit()
            self.cursor.close()
            self.conn.close()
        except Exception as e:
            print(e.args)
            return None
