#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDockWidget>
#include <QToolBar>
#include <QFormLayout>
#include <QDialogButtonBox>
#include "login.h"
#include "manager.h"
#include "util.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Login* login;
    Manager* manager;
    QToolBar *managerToolBar;
public:
    explicit MainWindow(QWidget *parent = nullptr);
    void successedLogin(QString id);
    Util util;
public slots:
    void managerAdd();
    void managerDelete();
    void managerChange();
    void managerFind();


signals:
};

#endif // MAINWINDOW_H
