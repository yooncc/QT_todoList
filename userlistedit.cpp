#include "user.h"
#include "userlistedit.h"

userListEdit::userListEdit(QWidget *parent)
    : QWidget{parent}
{
    grid = new QGridLayout(this);

    QPushButton* delButton = new QPushButton("Delete");
    QPushButton* modButton = new QPushButton("Modify");
    QPushButton* doneButton = new QPushButton("Done!");

    grid->addWidget(delButton);
    grid->addWidget(modButton);
    grid->addWidget(doneButton);
}
void userListEdit::deleteList(){ //리스트 삭제

}
void userListEdit::modifyList(){ //리스트 수정
//    bool ok;
//    QString modiList = QInputDialog::getText(this, "Modify", "Modify your work", QLineEdit::Normal, NULL, &ok);
//    listLabel = new QLabel();
//    listLabel->setText(modiList);
    //return ?
}
void userListEdit::isDone(){ //할일 완료
    //hash 사용
}
