#include "mainwindow.h"
#include "mainview.h"
#include "login.h"

#include <QStackedLayout>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow m;
    m.show();

    // Login login;
    // login.show();




    // mainView w;



    // w.show();
    return a.exec();
}
