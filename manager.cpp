#include "manager.h"

Manager::Manager(QWidget *parent)
    : QWidget{parent}
{

    managerView = new QFrame;
    managerView->setGeometry(QRect(0,0,1000,600));


}
