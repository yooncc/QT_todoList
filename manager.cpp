#include "manager.h"

Manager::Manager(QWidget *parent)
    : QWidget{parent}
{

    managerView = new QFrame(this);
    managerView->setGeometry(QRect(0,0,400,600));

    scrollArea = new QScrollArea(this);
    scrollArea->setGeometry(QRect(200,30,200,570));
    scrollArea->setBackgroundRole(QPalette::Dark);
    scrollSlider = scrollArea->verticalScrollBar();
    scrollSlider->setValue(scrollSlider->maximum());

    memberListLabel = new QLabel(this);
    memberListLabel->setGeometry(QRect(200,0,200,30));
    memberListLabel->setAlignment(Qt::AlignCenter);
    memberListLabel->setText("회원 목록");
    memberListLabel->setStyleSheet("QLabel {border-style: outset; border-width: 1px; border-color: blue;}");
    // memberListLabel->show();

    qDebug() << memberListLabel->text();
    this->getUserInfo();

    memberFindField = new QLineEdit(this);
    memberFindField->setGeometry(QRect(210,550,120,40));
    memberFindField->setPlaceholderText("회원검색");

    memberFindBtn = util.makePushButton(this,"검색","",11,true,"");
    memberFindBtn->setGeometry(QRect(340,550,50,40));
    connect(memberFindBtn,SIGNAL(clicked()),this,SLOT(memberFindBtnPressed()));

    memberNameLabel = new QLabel(this);
    memberNameLabel->setGeometry(QRect(0,0,200,50));
    memberNameLabel->setAlignment(Qt::AlignCenter);
    memberNameLabel->setText("_ _ _ _");
    memberNameLabel->setStyleSheet("QLabel {border-style: outset; border-width: 1px; border-color: red;}");
    // memberNameLabel->show();

    memberToDoArea = new QScrollArea(this);
    memberToDoArea->setGeometry(QRect(0,50,200,550));
    memberToDoArea->setBackgroundRole(QPalette::Light);
    memberToDoSlider = memberToDoArea->verticalScrollBar();
    memberToDoSlider->setValue(memberToDoSlider->maximum());

}
void Manager::getUserToDo(QString todoInfo) {
    qDebug("test - 1");

    toDoContainerWidget = new QWidget;
    toDoGridLayout = new QGridLayout(toDoContainerWidget);
    toDoGridLayout->setHorizontalSpacing(0);
    toDoGridLayout->setVerticalSpacing(0);
    toDoGridLayout->setContentsMargins(0, 0, 0, 0);

    QStringList todoList = todoInfo.split(";");
    for (int i=0;i<todoList.size()-1;i++) {
        QPushButton* toDoBtn = new QPushButton(this);
        toDoBtn->setText(todoList[i].split(";")[0]);
        toDoBtn->setStyleSheet("QPushButton {border-style: outset; border-width: 0px;}");
        toDoBtn->resize(200,30);
        toDoGridLayout->addWidget(toDoBtn,i,0);
    }
    toDoContainerWidget->resize(198,30*(todoList.size()-1));
    memberToDoArea->setWidget(toDoContainerWidget);

}

void Manager::getUserInfo() {
    qDebug("test - 1");

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

}

void Manager::memberBtnPressed() {

    qDebug() << ((QPushButton*)sender())->text();
    memberNameLabel->setText(((QPushButton*)sender())->text());
    qDebug() << (((QPushButton*)sender())->text())+".txt";
    // util.searchToDoInFile((((QPushButton*)sender())->text())+".txt");
    qDebug() << util.searchToDoInFile((((QPushButton*)sender())->text())+".txt");
    getUserToDo(util.searchToDoInFile((((QPushButton*)sender())->text())+".txt"));

}

void Manager::memberFindBtnPressed() {
    if (memberFindField->text() != "") {
        bool isExistID = util.findID("user_info.txt",memberFindField->text());
        if (isExistID) {
            // 조회 성공
            memberNameLabel->setText(memberFindField->text());
            this->getUserToDo(util.searchToDoInFile(memberFindField->text()+".txt"));
        }
        else {
            util.showErrorMsg(this,"존재하지 않는 아이디입니다.");
        }
    }
}
