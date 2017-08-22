#include "mainwindow/mainwindow.h"
#include "logindialog/logindialog.h"
#include <QApplication>
#include "client/client.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFont font("ZYSong20");
    a.setFont(font);

    //连接服务器
    CLIENT->connectServer();

    if(LOGIN->exec()==QDialog::Accepted)
    {
        MAINWINDOW->showMaximized();
        return a.exec();
    }

    return 0;
}