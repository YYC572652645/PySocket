#****************************************************
# 作者：YYC
# 功能：主函数
# 日期：2017-10-28
#****************************************************

import globaldef
import socketserver
from server import DataHandler


# 主函数入口
if __name__ == '__main__':

   servers = socketserver.ThreadingTCPServer((globaldef.IP, globaldef.PORT), DataHandler)
   print("服务器已启动...")
   servers.serve_forever()
