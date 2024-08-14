#include "login.h"
#include "mainview.h"
#include "mainwindow.h"
#include "user.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow m;
    m.show();

    return a.exec();
}
