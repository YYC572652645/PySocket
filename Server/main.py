import sys
sys.path.append("protocol")
sys.path.append("server")

import globaldef
import socketserver
from server import DataHandler

# 主函数入口
if __name__ == '__main__':
   servers = socketserver.ThreadingTCPServer((globaldef.IP, globaldef.PORT), DataHandler)
   print("服务器已启动...")
   servers.serve_forever()