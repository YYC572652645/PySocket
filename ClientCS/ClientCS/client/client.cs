using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net.Sockets;
using System.Net;
using com.force.json;
using Client.protocol;
using Client.messagehandler;
using System.Threading;

namespace MySocket.Connect
{
    class ClientCS
    {
        private String recvStr;
        private Socket socket;
        private int protocolNumber;
        MessageHandler messageHandler;
        Dictionary<String, String> dictData;

        private static ClientCS instance;

        static Mutex mutex;

        /*****************************    单例模式                 *************************/
        public static ClientCS GetInstance()
        {
            if (null == mutex)
            {
                mutex = new Mutex();
            }

            mutex.WaitOne();

            if (instance == null)
            {
                instance = new ClientCS();
            }

            mutex.ReleaseMutex();
            return instance;
        }

        /*****************************    私有构造函数                 *************************/
        private ClientCS()
        {
            dictData = new Dictionary<String, String>();

            connectServer();

            messageHandler = new MessageHandler();
        }

        /*****************************    连接服务器               *************************/
        public void connectServer()
        {
            try
            {
                socket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);

                int port = 8080;

                string host = "127.0.0.1";

                IPAddress ip = IPAddress.Parse(host);

                IPEndPoint ipEndPoint = new IPEndPoint(ip, port);

                socket.Connect(ipEndPoint);
            }
            catch (Exception e)
            {
                Console.WriteLine("出现异常", e.Message);
            }
        }

        /*****************************    读取服务端数据           *************************/
        public void readData()
        {
            try
            {
                while (true)
                {
                    if (socket.Available > 0)
                    {
                        byte[] recvBytes = new byte[1024];

                        int bytes;

                        bytes = socket.Receive(recvBytes, recvBytes.Length, 0);

                        recvStr += Encoding.ASCII.GetString(recvBytes, 0, bytes);

                        if (0 != recvStr.Length)
                        {
                            if (readJson(recvStr))
                            {
                                recvStr = "";

                                if (protocolNumber == (int)TCPPROTOCOL.INVALID) continue;

                                messageHandler.onCommand(dictData, protocolNumber);
                            }
                        }
                    }
                }
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }
        }

        /*****************************    读取Json数据             *************************/
        private bool readJson(String arrayData)
        {
            try
            {
                dictData.Clear();

                protocolNumber = (int)TCPPROTOCOL.INVALID;

                JSONObject jsonObject = new JSONObject(arrayData);

                JSONObject jsonData = jsonObject.GetJSONObject("data");

                foreach (String key in jsonData.GetKeys())
                {
                    dictData[key] = jsonData.GetString(key);
                }

                protocolNumber = Convert.ToInt32(dictData["protocol"]);

                dictData.Remove("protocol");

                return true;
            }
            catch (JSONException e)
            {
                return false;
            }
        }

        /*****************************    发送数据                 *************************/
        public void netSend(int protocol, Dictionary<String, String> dictData)
        {
            try
            {
                JSONObject jsonTotal = new JSONObject();
                JSONObject jsonData = new JSONObject();

                jsonData.Put("protocol", Convert.ToString(protocol));

                foreach (String key in dictData.Keys)
                {
                    jsonData.Put(key, dictData[key]);
                }

                jsonTotal.Put("data", jsonData);

                String arrayData = jsonTotal.ToString();

                byte[] byteArray = Encoding.ASCII.GetBytes(arrayData);

                Console.WriteLine(arrayData);

                socket.Send(byteArray);
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }
        }

    }
}
