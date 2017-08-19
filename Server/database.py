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
        #self.cursor.execute("select count(*) from ? where username = ? and password = ?", globaldef.TABLEUSER, userName, passWord)
        #self.cursor.fetchall()

        for item in self.cursor.fetchall():
            for element in item:
                print(element)

    # 插入数据
    def insertData(self):
        pass

    # 更新数据
    def updateData(self):
        pass

    # 删除数据
    def deleteData(self):
        pass