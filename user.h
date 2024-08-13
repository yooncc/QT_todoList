#pragma once
#ifndef USER_H
#define USER_H

#include <QFrame>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QInputDialog>
#include <QLineEdit>
#include <QMouseEvent>
#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include <QList>
#include "util.h"
#include "clickablelabel.h"
#include "userlistedit.h"


class User : public QWidget
{
    Q_OBJECT
public:
    explicit User(QWidget *parent = nullptr);
    ~User();
    userListEdit* userlist;
    ClickableLabel *label;
    void modListLabel();
    void delListLabel();
    void doneListLabel();
    ClickableLabel *currentL;
    Util util;

signals:
    void clicked();

public slots:
    void addNewlist();
    void loadList();
    void saveList();
    void onLabelClicked(ClickableLabel *label);

private:
    int count = 0;
    QPushButton *addButton;
    QPushButton *loadButton;
    QPushButton* saveButton;
    QFrame* userview;
    QVBoxLayout* boxLayout;
    QGroupBox *labelbox;
    QList<ClickableLabel*> labels;
};

#endif // USER_H
