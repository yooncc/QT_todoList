#pragma once
#ifndef USERLISTEDIT_H
#define USERLISTEDIT_H

#include "user.h"

class userListEdit : public QWidget
{
    Q_OBJECT
public:
    explicit userListEdit(QWidget *parent = nullptr);
    QLabel *listLabel;
    QLineEdit *line;
    QString mod;

public slots:
    void deleteList();
    void modifyList();
    void isDone();
    void modLabel();
signals:

private:
    int count = 0;

    QGridLayout *grid;
    QGroupBox *labelbox;
    QFormLayout *formLayout;
    ClickableLabel *label;
    //   QLineEdit* line;
};

#endif // USERLISTEDIT_H
