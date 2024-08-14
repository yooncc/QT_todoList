#pragma once
#ifndef USER_H
#define USER_H

#include <QFile>
#include <QFrame>
#include <QGridLayout>
#include <QGroupBox>
#include <QInputDialog>
#include <QLineEdit>
#include <QList>
#include <QMouseEvent>
#include <QObject>
#include <QVBoxLayout>
#include <QWidget>
#include <QtWidgets>
#include "clickablelabel.h"
#include "userlistedit.h"
#include "util.h"

class User : public QWidget
{
    Q_OBJECT
public:
    explicit User(QWidget *parent = nullptr);
    ~User();
    userListEdit *userlist;
    ClickableLabel *label;
    ClickableLabel *currentL;
    void modListLabel();
    void delListLabel();
    void doneListLabel();
    Util util;
    QString id;
    void readList(QString filename, QList<ClickableLabel *> &list, bool clear = false);

signals:
    void clicked();

public slots:
    void addNewlist();
    void loadList();
    void saveList();
    void onLabelClicked(ClickableLabel *label);
    void logoutUser();

private:
    QPushButton *addButton;
    QPushButton *loadButton;
    QPushButton *saveButton;
    QPushButton *logoutB;
    QFrame *userview;
    QVBoxLayout *boxLayout;
    QGroupBox *labelbox;
    QList<ClickableLabel *> labels;
    QList<ClickableLabel *> doneLabels;
};

#endif // USER_H
