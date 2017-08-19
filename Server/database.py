import sqlite3
import globaldef

class DataBase():
    # 构造函数
    def __init__(self):
        self.dataConn()

    # 连接数据库
    def dataConn(self):
        conn = sqlite3.connect("student.db")
        self.cursor = conn.cursor()

    # 查询数据
    def dataSelect(self, userName, passWord):
        str = "select count(*) from " + globaldef.TABLEUSER + " where username = '" + userName + "' and password = '" + passWord + "';"

        return self.cursor.execute(str)

    # 插入数据
    def insertData(self):
        pass

    # 更新数据
    def updateData(self):
        pass

    # 删除数据
    def deleteData(self):
        pass