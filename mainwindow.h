#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "login.h"
#include "manager.h"
#include <QDockWidget>

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Login* login;
    Manager* manager;
public:
    explicit MainWindow(QWidget *parent = nullptr);
    void successedLogin(QString id);

signals:
};

#endif // MAINWINDOW_H
