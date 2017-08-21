#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "personinfodialog/personinfodialog.h"

namespace Ui {
class MainWindow;
}

#define MAINWINDOW MainWindow::getInstance()

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    static MainWindow * getInstance()
    {
        if(NULL == instance)
        {
            instance = new MainWindow();
        }

        return instance;
    }

    PersonInfoDialog *getPersonInfoDialog() const;

private slots:
    void on_actionPersonInfo_triggered();

private:
    static MainWindow * instance;
    Ui::MainWindow *ui;
    PersonInfoDialog * personInfoDialog;


private:
    void closeEvent(QCloseEvent* event);
    void setPersonInfo(QMap<QString, QString> &mapData);
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

};

#endif // MAINWINDOW_H
