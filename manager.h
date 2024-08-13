#ifndef MANAGER_H
#define MANAGER_H

#include <QWidget>
#include <QFrame>
#include <QScrollArea>
#include <QScrollBar>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QCalendarWidget>
#include <QGridLayout>
#include "util.h"

class Manager : public QWidget
{
    Q_OBJECT
private:
    QFrame* managerView;
    QLabel* memberListLabel;
    QScrollArea* scrollArea;
    QScrollBar* scrollSlider;
    QLineEdit* memberFindField;
    QPushButton* memberFindBtn;
    QScrollArea* memberToDoArea;
    QScrollBar* memberToDoSlider;
    QCalendarWidget* managerCalendar;
    QGridLayout *memberGridLayout;
    QWidget *containerWidget;
public:
    explicit Manager(QWidget *parent = nullptr);
    Util util;
    void getUserInfo();
public slots:
    void memberBtnPressed();

signals:
};

#endif // MANAGER_H
