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

    # 查询数据
    def dataSelect(self, userName, passWord):
        try:
            str = "select count(*) from " + globaldef.TABLEUSER + " where username = '" + userName + "' and password = '" + passWord + "';"

            return self.cursor.execute(str)
        except Exception as e:
            print(e.args)
            return None

    # 插入数据
    def insertData(self):
        pass

    # 更新数据
    def updateData(self):
        pass

    # 删除数据
    def deleteData(self):
        pass