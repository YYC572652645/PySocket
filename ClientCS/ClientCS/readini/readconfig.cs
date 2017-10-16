using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;

namespace Config.ReadWrite
{
    class ReadConfig
    {
        public enum USER
        {
            USERNAME = 0,
            PASSWORD = 1,
            REMEMBER = 2,
            AUTOLOGIN = 3
        }

        //用户信息列表
        private List<UserData> userList;
        private List<String> idList;

        //用户信息结构体
        public struct UserData
        {
            public String userName;
            public String passWord;
            public String remember;
            public String autoLogin;
        }

        /*************************      构造函数          ********************/
        public ReadConfig()
        {
            userList = new List<UserData>();

            idList = new List<String>();

            readConfig();
        }

        /************************       获取Id             ********************/
        public List<String> dataId
        {
            get { return idList; }
        }

        /************************       获取用户信息       ********************/
        public List<UserData> dataUser
        {
            get { return userList; }

            set { userList = value; }
        }

        /************************       读取配置文件       ********************/
        public void readConfig()
        {
            try
            {
                userList.Clear();
                idList.Clear();

                //定义Document
                XmlDocument xmlDoc = new XmlDocument();

                //加载xml文件
                xmlDoc.Load("login.xml");

                //获取data下的user的所有节点
                XmlNodeList nodeList = xmlDoc.SelectNodes("/data/user");

                if (nodeList != null)
                {
                    foreach (XmlNode node in nodeList)
                    {
                        idList.Add(node.Attributes["id"].Value);

                        //赋值第一个子节点
                        XmlNode tempNode = node.FirstChild;

                        int count = 0;

                        UserData userData = new UserData();

                        while (null != tempNode)
                        {
                            switch (count)
                            {
                                case (int)USER.USERNAME: userData.userName = tempNode.InnerText.Trim(); break;
                                case (int)USER.PASSWORD: userData.passWord = tempNode.InnerText.Trim(); break;
                                case (int)USER.REMEMBER: userData.remember = tempNode.InnerText.Trim(); break;
                                case (int)USER.AUTOLOGIN: userData.autoLogin = tempNode.InnerText.Trim(); break;
                            }

                            //指向下一个节点
                            tempNode = tempNode.NextSibling;

                            count++;
                        }

                        //存储到列表
                        userList.Add(userData);
                    }
                }
            }
            catch (Exception e)
            {
                Console.WriteLine("出现异常", e.Message);
            }
        }

        /************************       写入配置文件       ********************/
        public void writeConfig(UserData data)
        {
            try
            {
                XmlDocument xmlDoc = new XmlDocument();

                //加载xml文件
                xmlDoc.Load("login.xml");

                //创建根节点
                XmlNode rootNode = xmlDoc.DocumentElement;

                //创建一个新的用户
                XmlNode user = xmlDoc.CreateElement("user");
                XmlAttribute id = xmlDoc.CreateAttribute("id");
                XmlNode userName = xmlDoc.CreateElement("username");
                XmlNode passWord = xmlDoc.CreateElement("password");
                XmlNode remember = xmlDoc.CreateElement("remember");
                XmlNode autoLogin = xmlDoc.CreateElement("autologin");

                if (null != rootNode.LastChild)
                {
                    String strId = rootNode.LastChild.Attributes["id"].Value;

                    int count = Convert.ToInt32(strId) + 1;
                    id.Value = Convert.ToString(count);
                }
                else
                {
                    id.Value = "1";
                }

                //节点赋值
                userName.InnerText = data.userName;
                passWord.InnerText = data.passWord;
                remember.InnerText = data.remember;
                autoLogin.InnerText = data.autoLogin;

                //添加节点
                user.Attributes.Append(id);
                rootNode.AppendChild(user);
                user.AppendChild(userName);
                user.AppendChild(passWord);
                user.AppendChild(remember);
                user.AppendChild(autoLogin);

                //保存Xml文档
                xmlDoc.Save("login.xml");
            }
            catch (Exception e)
            {
                Console.WriteLine("出现异常", e.Message);
            }
        }

        /************************       更新配置文件       ********************/
        public void updateConfig(String id, String passWord, String remember, String autoLogin)
        {
            //定义Document
            XmlDocument xmlDoc = new XmlDocument();

            //加载xml文件
            xmlDoc.Load("login.xml");

            //获取data下的user的所有节点
            XmlNodeList nodeList = xmlDoc.SelectNodes("/data/user");

            if (nodeList != null)
            {
                foreach (XmlNode node in nodeList)
                {
                    if (node.Attributes["id"].Value == id)
                    {
                        //赋值第一个子节点
                        XmlNode tempNode = node.FirstChild;

                        int count = 0;

                        while (null != tempNode)
                        {
                            switch (count)
                            {
                                case (int)USER.PASSWORD: tempNode.InnerText = passWord; break;
                                case (int)USER.REMEMBER: tempNode.InnerText = remember; break;
                                case (int)USER.AUTOLOGIN: tempNode.InnerText = autoLogin; break;
                            }

                            //指向下一个节点
                            tempNode = tempNode.NextSibling;

                            count++;
                        }
                    }
                }
            }

            xmlDoc.Save("login.xml");
        }

    }
}
