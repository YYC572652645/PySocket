#include "mainwindow/mainwindow.h"
#include "logindialog/logindialog.h"
#include <QApplication>
#include "client/client.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFont font("ZYSong20");
    a.setFont(font);
    MainWindow w;
    CLIENT->connectServer();

    if(LOGIN->exec()==QDialog::Accepted)
    {
        w.show();
        return a.exec();

    }
    else
    {
        return 0;
    }
}
