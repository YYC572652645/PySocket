import sqlite3
import globaldef

class DataBase():
    # 构造函数
    def __init__(self):
        self.dataConn()

    # 连接数据库
    def dataConn(self):
        try:
            conn = sqlite3.connect("student.db")
            self.cursor = conn.cursor()
        except Exception as e:
            print(e.args)

    # 查询登录数据
    def dataSelectUser(self, userName, passWord):
        try:
            str = "select count(*) from " + globaldef.TABLEUSER + " where username = '" + userName + "' and password = '" + passWord + "';"
            return self.cursor.execute(str)
        except Exception as e:
            print(e.args)
            return None

    # 查询个人信息数据
    def dataSelectPersonData(self, userName):
        try:
            str = "select * from " + globaldef.TABLEPERSONDATA + "  where username = '" + userName + "';"
            return self.cursor.execute(str)
        except Exception as e:
            print(e.args)
            return None

    # 插入数据
    def insertData(self):
        pass

    # 更新个人信息数据
    def updatePersonData(self, dict):
        try:
            str = "update " + globaldef.TABLEPERSONDATA + " set name = '" + dict[globaldef.personUserName] + "', sex = '" + dict[globaldef.sex] +"', "
            str += "address = '" + dict[globaldef.address] + "'," + "personinfo = '" + dict[globaldef.personInfo] + "', "
            str += "realname = '" + dict[globaldef.realName] + "'," + "email = '" + dict[globaldef.email] + "', "
            str += "phone = '" + dict[globaldef.phone] + "'," + "photo = '" + dict[globaldef.photo] + "' "
            str += "where username = '" + dict[globaldef.personUserName] + "';"

            print(str)
            self.cursor.execute(str)
        except Exception as e:
            print(e.args)
            return None

    # 删除数据
    def deleteData(self):
        pass