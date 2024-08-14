#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDockWidget>
#include <QMainWindow>
#include <QDockWidget>
#include <QToolBar>
#include <QFormLayout>
#include <QDialogButtonBox>
#include "login.h"
#include "manager.h"
#include "util.h"
#include "user.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Login* login;
    User* user;
    Manager* manager;
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
