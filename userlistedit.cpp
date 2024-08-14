#include "user.h"

userListEdit::userListEdit(QWidget *parent)
    : QWidget{parent}
{
    this->setGeometry(QRect(0, 0, 500, 600));
    grid = new QGridLayout(this);

    QPushButton *delButton = new QPushButton("Delete");
    QPushButton *modButton = new QPushButton("Modify");
    QPushButton *doneButton = new QPushButton("Done!");
    QPushButton *cancle = new QPushButton("X");

    connect(modButton, SIGNAL(clicked()), SLOT(modifyList()));
    connect(doneButton, SIGNAL(clicked()), SLOT(isDone()));
    connect(delButton, SIGNAL(clicked()), SLOT(deleteList()));
    connect(cancle, SIGNAL(clicked()), SLOT(close()));

    grid->addWidget(delButton, 0, 0);
    grid->addWidget(modButton, 0, 5);
    grid->addWidget(doneButton, 0, 10); //높이조정하기 (맨 위로)
    grid->addWidget(cancle, 0, 15);
}
void userListEdit::deleteList()
{ //리스트 삭제
    ((User *) (this->parent()))->delListLabel();
    this->close();
    //count--;
}
void userListEdit::isDone()
{ //할일 완료
    //hash 사용
    ((User *) (this->parent()))->doneListLabel();
    this->close();
}
void userListEdit::modifyList()
{ //리스트 수정
    line = new QLineEdit();
    line->setPlaceholderText("modify your list (press enter)");
    grid->addWidget(line);
    connect(line, SIGNAL(returnPressed()), this, SLOT(modLabel()));
}
void userListEdit::modLabel()
{
    qDebug("enter pressed");
    qDebug() << line->text(); //lineEdit 굳이 매개변수로 넣어주지않아도됨
    mod = line->text();
    ((User *) (this->parent()))->modListLabel();
    this->close();
}
