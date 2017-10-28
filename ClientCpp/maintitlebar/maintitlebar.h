#ifndef MAINTITLEBAR_H
#define MAINTITLEBAR_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QMouseEvent>
#include <QComboBox>


class MainTitleBar : public QWidget
{
    Q_OBJECT
public:
    explicit MainTitleBar(QWidget *parentWidget = 0);

    QLabel *getImgLabel() const;

signals:
    void sendIndex(int);

public slots:
    void showMax();
    void showMin();
    void showClose();
    void receiveIndex(int index);

private:
    bool mousePress;             //按钮点击标志位
    QPoint movePoint;            //鼠标移动
    QPushButton *maxButton;      //最大化按钮
    QPushButton *minButton;      //最小化按钮
    QPushButton *closeButton;    //关闭按钮
    QComboBox *titleCombox;      //标题框
    QLabel *imgLabel;            //图片框
    QWidget *parentWidget;       //父窗口
    QPushButton *nodeButton;     //云笔记
    QPushButton *teamButton;     //云协作
    QPushButton *vipButton;      //会员
    QLabel *spaceLabel;          //用来占位
    QAction * action;

private:
    void initValue();
    void mousePressEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent * event);
};

#endif // TITLEBAR_H
