#include "user.h"

userListEdit::userListEdit(QWidget *parent)
    : QWidget{parent}
{

    editview = new QFrame(this);
    editview->setGeometry(QRect(0, 0, 400, 400));

    buttonbox = new QGroupBox("&Edit", this);
    boxLayout = new QHBoxLayout;
    buttonbox->setLayout(boxLayout);
    buttonbox->setGeometry(QRect(500, 100, 400, 300));

    delButton = util.makePushButton(this, "Delete", "", 7, false, "");
    connect(delButton, SIGNAL(clicked()), SLOT(deleteList()));
    modButton = util.makePushButton(this, "Modify", "", 7, false, "");
    connect(modButton, SIGNAL(clicked()), SLOT(modifyList()));
    doneButton = util.makePushButton(this, "Done!", "", 7, false, "");
    connect(doneButton, SIGNAL(clicked()), SLOT(isDone()));
    cancle = util.makePushButton(this, "X", "", 7, false, "");
    connect(cancle, SIGNAL(clicked()), SLOT(close()));

    boxLayout->addWidget(delButton);
    boxLayout->addWidget(modButton);
    boxLayout->addWidget(doneButton);
    boxLayout->addWidget(cancle);

}
void userListEdit::deleteList()
{ //리스트 삭제
    ((User *) (this->parent()))->delListLabel();
    this->close();
}
void userListEdit::isDone()
{ //할일 완료
    ((User *) (this->parent()))->doneListLabel();
    this->close();
}
void userListEdit::modifyList()
{ //리스트 수정
    line = new QLineEdit();
    line->setPlaceholderText("modify your list (press enter)");
    boxLayout->addWidget(line);
    line->setGeometry(QRect(buttonbox->width(), 5, 10, 20));
    connect(line, SIGNAL(returnPressed()), this, SLOT(modLabel()));
}
void userListEdit::modLabel()
{
    mod = line->text();
    ((User *) (this->parent()))->modListLabel();
    this->close();
}
