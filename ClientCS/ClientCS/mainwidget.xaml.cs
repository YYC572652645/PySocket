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
using System.Windows.Shapes;

namespace Client
{
    public partial class MainWidget : Window
    {

        private static MainWidget instance;

        public static MainWidget GetInstance()
        {
            if (instance == null)
            {
                instance = new MainWidget();
            }
            return instance;
        }

        private MainWidget()
        {
            InitializeComponent();
        }

        public void showWidget()
        {
            this.Show();
        }
    }
}
