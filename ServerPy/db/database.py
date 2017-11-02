#****************************************************
# 作者：YYC
# 功能：所有数据库的父类
# 日期：2017-11-02
#****************************************************

import sqlite3

class DataBase():
    # 连接数据库
    def dataConn(self):
        try:
            self.conn = sqlite3.connect("student.db")
            self.cursor = self.conn.cursor()
        except Exception as e:
            print(e.args)