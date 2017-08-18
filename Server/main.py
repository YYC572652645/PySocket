import sys
import globaldef
from  protocol import PROTOCOL
import socketserver
from server import DataHandler

from myjson import MyJson

# 主函数入口
if __name__ == '__main__':
   myjson = MyJson()

   myjson.dataDictionary["test1"] = "嘻嘻"
   myjson.dataDictionary["test2"] = "哈哈"
   myjson.dataDictionary["test3"] = "呵呵"
   myjson.dataDictionary["test4"] = "哦哦"

   myjson.writeJson(PROTOCOL.LOGIN)

   servers = socketserver.ThreadingTCPServer((globaldef.IP, globaldef.PORT), DataHandler)
   print("服务器已启动...")
   servers.serve_forever()
