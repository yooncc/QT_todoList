#ifndef USER_H
#define USER_H

#include <QObject>
#include <QWidget>
#include <QFrame>
#include <QFormLayout>
#include <QtWidgets>
#include <QMenuBar>
#include <QGridLayout>
#include <QInputDialog>
#include <QGroupBox>
#include <QFormLayout>
#include <QMouseEvent>
#include <QMessageBox>
#include <QLineEdit>
#include "clickablelabel.h"
#include "userlistedit.h"

class User :public QWidget
{
    Q_OBJECT
public:
    explicit User(QWidget *parent = nullptr);
    ~User();
    userListEdit* userlist;
    ClickableLabel* label;
    void modListLabel();
    void delListLabel();
    void doneListLabel();
    ClickableLabel* currentL;

signals:
    void clicked();

public slots:
    void addNewlist();
    void loadList();
    void onLabelClicked(ClickableLabel* label);

private:
    int count = 0;

    QPushButton* addButton;
    QPushButton* loadButton;
    QGridLayout* grid;
    QLabel* listLabel;
    QGroupBox* labelbox;
    QFormLayout* formLayout;

//    ClickableLabel* label;
};

#endif // USER_H
