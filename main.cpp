#include "mainview.h"
#include "user.h"
#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    User u;
    u.show();
 //   w.show();
    return a.exec();
}
