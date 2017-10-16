using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using Config.ReadWrite;
using MySocket.Connect;
using System.Threading;
using Client.protocol;

namespace Client
{
    public partial class MainWindow : Window
    {
        private ReadConfig readConfig;
        private Thread thread;

        /*****************************    主函数                 *************************/
        public MainWindow()
        {
            InitializeComponent();

            //创建一个线程运行客户端接收数据
            thread = new Thread(new ThreadStart(ClientCS.GetInstance().readData));

            //启动线程
            thread.Start();

            //将配置文件中的信息加载进来
            readConfig = new ReadConfig();

            for (int i = 0; i < readConfig.dataUser.Count; i++)
            {
                ComboBoxItem item = new ComboBoxItem();

                item.Content = readConfig.dataUser[i].userName;

                userNameComboBox.Items.Add(item);
            }

            userNameComboBox.SelectedIndex = 0;

            if (readConfig.dataUser.Count != 0)
            {
                passWordBox.Password = readConfig.dataUser[0].passWord;
            }
        }

        /*****************************    鼠标点击事件           *************************/
        private void Window_MouseLeftButtonDown(object sender, MouseButtonEventArgs e)
        {
            base.DragMove();
        }

        /*****************************    关闭按钮               *************************/
        private void closeButtonClick(object sender, RoutedEventArgs e)
        {
            base.Close();
            thread.Abort();
        }

        /*****************************    登录按钮               *************************/
        private void loginButtonClick(object sender, RoutedEventArgs e)
        {
            ReadConfig.UserData userData = new ReadConfig.UserData();

            userData.userName = userNameComboBox.Text;
            userData.passWord = passWordBox.Password;
            userData.remember = rememberPassWordBox.IsChecked == true ? "1" : "0";
            userData.autoLogin = autoLoginBox.IsChecked == true ? "1" : "0";

            bool flage = true;

            for (int i = 0; i < readConfig.dataUser.Count; i++)
            {
                if (readConfig.dataUser[i].userName == userNameComboBox.Text)
                {
                    flage = false;
                }

                if (userNameComboBox.Text == readConfig.dataUser[i].userName)
                {
                    if (userData.remember != readConfig.dataUser[i].remember || userData.autoLogin != readConfig.dataUser[i].passWord || userData.passWord != readConfig.dataUser[i].passWord)
                    {
                        readConfig.updateConfig(readConfig.dataId[i], userData.passWord, userData.remember, userData.autoLogin);
                    }
                }
            }

            if (flage)
            {
                readConfig.writeConfig(userData);
            }

            Dictionary<String, String> mapData = new Dictionary<String, String>();

            mapData["username"] = userNameComboBox.Text;
            mapData["password"] = passWordBox.Password;

            ClientCS.GetInstance().netSend((int)TCPPROTOCOL.LOGINREQ, mapData);
        }

        /*****************************    下拉框改变              *************************/
        private void itemChange(object sender, SelectionChangedEventArgs e)
        {
            if (userNameComboBox.SelectedIndex < 0 || userNameComboBox.SelectedIndex >= readConfig.dataUser.Count) return;

            passWordBox.Password = readConfig.dataUser[userNameComboBox.SelectedIndex].passWord;

            userNameComboBox.Focus();
        }
    }
}
