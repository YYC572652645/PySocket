import sys
import globaldef
from  protocol import PROTOCOL
import socketserver
from server import DataHandler
from messagehandler import MessageHandler
from database import DataBase
# 主函数入口
if __name__ == '__main__':

   dataBase = DataBase()
   dataBase.dataSelect("1305120114", "1305120114")

   servers = socketserver.ThreadingTCPServer((globaldef.IP, globaldef.PORT), DataHandler)
   print("服务器已启动...")
   servers.serve_forever()
