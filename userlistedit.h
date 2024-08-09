#ifndef USERLISTEDIT_H
#define USERLISTEDIT_H

#include "user.h"

class userListEdit : public QWidget
{
    Q_OBJECT
public:
    explicit userListEdit(QWidget *parent = nullptr);

public slots:
    void deleteList();
    void modifyList();
    void isDone();
signals:

private:
    int count = 0;

    QGridLayout* grid;
    QLabel* listLabel;
    QGroupBox* labelbox;
    QFormLayout* formLayout;

    ClickableLabel* label;
};

#endif // USERLISTEDIT_H
