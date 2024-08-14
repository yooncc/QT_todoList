#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialogButtonBox>
#include <QDockWidget>
#include <QFormLayout>
#include <QMainWindow>
#include <QToolBar>
#include "login.h"
#include "manager.h"
#include "user.h"
#include "util.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Login *login;
    User *user;
    Manager *manager;
    QToolBar *managerToolBar;
    QDockWidget *dock;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void successedLogin(QString id);
    void logout();
    Util util;
public slots:
    void managerAdd();
    void managerDelete();
    void managerChange();
    void managerFind();
    void managerLogout();

signals:
};

#endif // MAINWINDOW_H
