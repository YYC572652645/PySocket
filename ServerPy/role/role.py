#****************************************************
# 作者：YYC
# 功能：用户管理
# 日期：2017-11-02
#****************************************************

import threading

lock = threading.Lock()

class Role(object):
    
    __instance = None
    roleDict = {}

    # 单例模式
    def __new__(cls, *args, **kwargs):
        if (None == cls.__instance):
            try:
                lock.acquire()
                cls.__instance = super(Role, cls).__new__(cls, *args, **kwargs)
            finally:
                lock.release()

        return cls.__instance

    # 添加用户
    def addRole(self, userName, sock):
        self.roleDict[userName] = sock

    # 删除用户
    def deleteRole(self, userName):
        if(userName in self.roleDict):
            del self.roleDict[userName]

    # 获取用户
    def getRole(self, userName):
        if (userName in self.roleDict):
            return self.roleDict.get(userName)
        else:
            return None

    # 获取所有用户
    def getAllRole(self):
        return self.roleDict