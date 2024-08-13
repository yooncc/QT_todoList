#include "manager.h"

Manager::Manager(QWidget *parent)
    : QWidget{parent}
{
    managerView = new QFrame(this);
    managerView->setGeometry(QRect(0,0,1000,600));

    scrollArea = new QScrollArea(this);
    scrollArea->setGeometry(QRect(800,30,200,570));
    scrollArea->setBackgroundRole(QPalette::Dark);
    scrollSlider = scrollArea->verticalScrollBar();
    scrollSlider->setValue(scrollSlider->maximum());

    memberListLabel = new QLabel(this);
    memberListLabel->setGeometry(QRect(800,0,200,30));
    memberListLabel->setAlignment(Qt::AlignCenter);
    memberListLabel->setText("회원 목록");

    this->getUserInfo();

    // QString userInfo = util.readFile("user_info.txt");
    // QStringList memberList = userInfo.split(":");
    // for (int i=0;i<memberList.size()-1;i++) {
    //     QPushButton* memberBtn = new QPushButton(this);
    //     memberBtn->setText(memberList[i].split(";")[0]);
    //     memberBtn->resize(200,30);
    //     memberGridLayout->addWidget(memberBtn,i,0);
    // }
    // containerWidget->resize(195,30*(memberList.size()-1));
    // scrollArea->setWidget(containerWidget);

    memberFindField = new QLineEdit(this);
    memberFindField->setGeometry(QRect(810,550,120,40));
    memberFindField->setPlaceholderText("회원검색");

    memberFindBtn = util.makePushButton(this,"검색","",11,true,"");
    memberFindBtn->setGeometry(QRect(940,550,50,40));

    memberToDoArea = new QScrollArea(this);
    memberToDoArea->setGeometry(QRect(600,0,200,600));
    memberToDoArea->setBackgroundRole(QPalette::Light);
    // scrollArea->setWidget();
    memberToDoSlider = memberToDoArea->verticalScrollBar();
    memberToDoSlider->setValue(memberToDoSlider->maximum());

    managerCalendar = new QCalendarWidget(this);
    managerCalendar->setGeometry(QRect(0,0,600,600));

}

void Manager::getUserInfo() {
    qDebug("test - 1");
    // if (memberGridLayout != NULL) {
    //     containerWidget->close();
    // }

    containerWidget = new QWidget;
    memberGridLayout = new QGridLayout(containerWidget);
    memberGridLayout->setHorizontalSpacing(0);
    memberGridLayout->setVerticalSpacing(0);
    memberGridLayout->setContentsMargins(0, 0, 0, 0);

    QString userInfo = util.readFile("user_info.txt");
    QStringList memberList = userInfo.split(":");
    for (int i=0;i<memberList.size()-1;i++) {
        QPushButton* memberBtn = new QPushButton(this);
        memberBtn->setText(memberList[i].split(";")[0]);
        connect(memberBtn,SIGNAL(clicked()),this,SLOT(memberBtnPressed()));
        memberBtn->setStyleSheet("QPushButton {border-style: outset; border-width: 0px;}");
        memberBtn->resize(200,30);
        memberGridLayout->addWidget(memberBtn,i,0);
    }
    containerWidget->resize(198,30*(memberList.size()-1));
    scrollArea->setWidget(containerWidget);

    // setLayout(memberGridLayout);

}

void Manager::memberBtnPressed() {

    qDebug() << ((QPushButton*)sender())->text();

}
