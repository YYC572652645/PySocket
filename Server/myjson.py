#json数据格式如下
# {
#     "protocol": "1",
#     "data": {
#         "test1": "哈哈",
#         "test2": "嘻嘻",
#         "test3": "呵呵",
#         "test4": "哦哦"
#     }
# }

import json
import  globaldef

class MyJson():
    def __init__(self):
        self.dataTotal = {}         # 总的json数据
        self.dataDictionary = {}    # json中的data区

    # 读取json数据
    def readJson(self):
        data = json.loads(json_str)

        print(data)

    # 写json数据
    def writeJson(self, protocol):
        # json组包
        self.dataTotal[globaldef.PROTOCOLNAME] = protocol
        self.dataTotal[globaldef.DATANAME] =  self.dataDictionary

        # 编码成json格式的数据
        self.encodejson = json.dumps(self.dataTotal, ensure_ascii = False)

        # 清空字典
        self.dataDictionary.clear()
        self.dataTotal.clear()

        print(self.encodejson)
