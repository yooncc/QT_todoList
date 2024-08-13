#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDockWidget>
#include <QMainWindow>
#include "login.h"
#include "manager.h"
#include "user.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Login *login;
    Manager *manager;
    User *user;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void successedLogin(QString id);

signals:
};

#endif // MAINWINDOW_H
