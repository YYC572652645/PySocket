import sqlite3


class DataBase():
    def __init__(self):
        pass

    # 连接数据库
    def dataConn(self):
        conn = sqlite3.connect("student.db")

    # 查询数据
    def dataSelect(self):
        pass

    # 插入数据
    def insertData(self):
        pass

    # 更新数据
    def updateData(self):
        pass

    # 删除数据
    def deleteData(self):
        pass