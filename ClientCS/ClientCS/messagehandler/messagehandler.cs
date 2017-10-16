using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Client.protocol;
using Client;
using System.Threading;

namespace Client.messagehandler
{
    class MessageHandler
    {
        private int MSGSIZE = 100;

        //delegate可看作为函数指针
        public delegate void CommandFunc(Dictionary<String, String> mapData);

        CommandFunc[] dataMessageList;

        /*************************      构造函数          ********************/
        public MessageHandler()
        {
            dataMessageList = new CommandFunc[MSGSIZE];

            dataMessageList[(int)TCPPROTOCOL.LOGININFO] = receiveLoginData;
        }

        /*************************      根据协议号调用相对函数          ********************/
        public void onCommand(Dictionary<String, String> mapData, int protocolNumber)
        {
            if (null == dataMessageList[protocolNumber]) return;

            if (protocolNumber != (int)TCPPROTOCOL.INVALID && protocolNumber < MSGSIZE)
            {
                dataMessageList[protocolNumber](mapData);
            }
        }

        /*************************   接收到客户端登录消息    *********************/
        public void receiveLoginData(Dictionary<String, String> mapData)
        {
            int count = 0;
            foreach (string key in mapData.Keys)
            {
                Console.WriteLine( mapData[key]);

                count = Convert.ToInt32(mapData[key]);
            }

            if (count != 0)
            {
                Console.WriteLine(Thread.CurrentThread);
            }
        }
    }
}
