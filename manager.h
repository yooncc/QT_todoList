#ifndef MANAGER_H
#define MANAGER_H

#include <QCalendarWidget>
#include <QFrame>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QScrollArea>
#include <QScrollBar>
#include "util.h"

class Manager : public QWidget
{
    Q_OBJECT
private:
    QFrame *managerView;
    QLabel *memberListLabel;
    QScrollArea *scrollArea;
    QScrollBar *scrollSlider;
    QLineEdit *memberFindField;
    QPushButton *memberFindBtn;
    QScrollArea *memberToDoArea;
    QScrollBar *memberToDoSlider;
    QCalendarWidget *managerCalendar;
    QGridLayout *memberGridLayout;
    QWidget *containerWidget;
    QGridLayout *toDoGridLayout;
    QWidget *toDoContainerWidget;

public:
    explicit Manager(QWidget *parent = nullptr);
    Util util;
    QLabel *memberNameLabel;
    void getUserInfo();
    void getUserToDo(QString);
public slots:
    void memberBtnPressed();
    void memberFindBtnPressed();

signals:
};

#endif // MANAGER_H
