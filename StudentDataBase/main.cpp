#include "mainwindow.h"
#include "logindialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFont font("ZYSong20");
    a.setFont(font);
    MainWindow w;
    LoginDialog login;
    if(login.exec()==QDialog::Accepted)
    {
        w.show();
        return a.exec();

    }
    else
    {
        return 0;
    }


}
