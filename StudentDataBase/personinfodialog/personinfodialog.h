#ifndef PERSONINFODIALOG_H
#define PERSONINFODIALOG_H

#include <QDialog>

namespace Ui {
class personinfodialog;
}

typedef struct PersonData
{
    QString personUserName;
    QString name;
    QString sex;
    QString address;
    QString personInfo;
    QString realName;
    QString email;
    QString phone;
    QString photo;
}PersonData;

class PersonInfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PersonInfoDialog(QWidget *parent = 0);
    ~PersonInfoDialog();

    void showDialog();
    void setPersonData(const PersonData &value);

private slots:
    void on_pushButtonPhoto_clicked();

    void on_pushButtonSave_clicked();

    void on_pushButtonCancel_clicked();

private:
    Ui::personinfodialog *ui;

    PersonData personData;
    QImage photoImage;


};

#endif // PERSONINFODIALOG_H
