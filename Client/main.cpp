#include "mainwindow/mainwindow.h"
#include "logindialog/logindialog.h"
#include <QApplication>
#include "client/client.h"
#include "globaldef.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFont font("ZYSong20");
    a.setFont(font);

    //加载qss
    LOADQSS(":/qss/qss/style.qss");

    //连接服务器
    CLIENT->connectServer();

    if(LOGIN->exec() == QDialog::Accepted)
    {
        MAINWINDOW->show();
        return a.exec();
    }

    return 0;
}



