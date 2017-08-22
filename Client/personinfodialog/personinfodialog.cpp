#include "personinfodialog.h"
#include "ui_personinfodialog.h"
#include <QFileDialog>
#include <QBuffer>
#include <QDebug>
#include "globaldef.h"
#include "client/client.h"
#include "protocol.h"

/************************   构造函数    ************************/
PersonInfoDialog::PersonInfoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::personinfodialog)
{
    ui->setupUi(this);
    this->setWindowTitle("个人信息");
    this->setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint);

    QPalette palette = ui->lineFirst->palette();
    palette.setColor(QPalette::Dark, Qt::darkCyan);
    ui->lineFirst->setPalette(palette);
    ui->lineSecond->setPalette(palette);
    ui->lineThird->setPalette(palette);
    ui->lineFourth->setPalette(palette);

    ui->labelPhoto->setScaledContents(true);
}

/************************   析构函数    ************************/
PersonInfoDialog::~PersonInfoDialog()
{
    delete ui;
}

/************************   设置个人信息    ************************/
void PersonInfoDialog::setPersonData(const PersonData &value)
{
    personData = value;
}

/************************   显示窗口    ************************/
void PersonInfoDialog::showDialog()
{
    ui->lineEditName->setText(personData.name);
    ui->lineEditAddress->setText(personData.address);
    ui->lineEditEmail->setText(personData.email);
    ui->lineEditSex->setText(personData.sex);
    ui->lineEditPhone->setText(personData.phone);
    ui->lineEditRealName->setText(personData.realName);
    ui->textEditPersonInfo->setText(personData.personInfo);
    photoImage = QImage::fromData(QByteArray::fromHex(personData.photo.toLatin1()));
    ui->labelPhoto->setPixmap(QPixmap::fromImage(photoImage));

    this->exec();
}

/************************   更换头像    ************************/
void PersonInfoDialog::on_pushButtonPhoto_clicked()
{
    photoImage = QImage();

    fileName = QFileDialog::getOpenFileName(this,"更换头像", ".", "Image(*.png *.jpg *.tif *.bmp *.ico)");

    if(fileName.isEmpty()) return;

    photoImage.load(fileName);

    ui->labelPhoto->setPixmap(QPixmap::fromImage(photoImage));
}

/************************   保存信息    ************************/
void PersonInfoDialog::on_pushButtonSave_clicked()
{
    if(photoImage.isNull()) return;

    QByteArray byteArray;
    if(!fileName.isEmpty())
    {
        photoImage = photoImage.scaled(200, 200, Qt::KeepAspectRatio, Qt::FastTransformation);
        fileName.clear();
    }

    QBuffer buffer(&byteArray);
    photoImage.save(&buffer, "png");
    buffer.close();

    QMap<QString, QString> mapData;

    mapData[Protocol::personUserName] = personData.personUserName;
    mapData[Protocol::name]           = ui->lineEditName->text();
    mapData[Protocol::sex]            = ui->lineEditSex->text();
    mapData[Protocol::address]        = ui->lineEditAddress->text();
    mapData[Protocol::personInfo]     = ui->textEditPersonInfo->toPlainText();
    mapData[Protocol::realName]       = ui->lineEditRealName->text();
    mapData[Protocol::email]          = ui->lineEditEmail->text();
    mapData[Protocol::phone]          = ui->lineEditPhone->text();
    mapData[Protocol::photo]          = byteArray.toHex();

    CLIENT->netSend(Protocol::SAVEPERSONREQ, mapData);
}

/************************   取消按钮    ************************/
void PersonInfoDialog::on_pushButtonCancel_clicked()
{
    this->close();
}
