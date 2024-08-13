#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow{parent}
{
    this->setGeometry(QRect(0,0,200,200));
    login = new Login();
    setCentralWidget(login);


}

void MainWindow::successedLogin(QString id) {
    qDebug() << "로그인 성공 -2";
    if (id == "admin") { // 매니저 로그인
        manager = new Manager();
        login->close();
        setCentralWidget(manager);
        this->setGeometry(QRect(100,100,1000,600));
        QLabel *label = new QLabel("admin");
        label->setAlignment(Qt::AlignRight);
        QDockWidget *dock = new QDockWidget(this);
        dock->setTitleBarWidget(label);

        // dock->setAllowedAreas(Qt::BottomDockWidgetArea);
        addDockWidget(Qt::BottomDockWidgetArea,dock);

        // dock->setWidget(this);
    }
    else {  // 일반회원 로그인
        user = new User();
        login->close();
        setCentralWidget(user);
        this->setGeometry(QRect(100, 100, 1000, 600));
        QLabel* label = new QLabel(id);
        label->setAlignment(Qt::AlignRight);
    }
}
