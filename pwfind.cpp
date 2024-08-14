#include "pwfind.h"

PwFind::PwFind(QWidget *parent)
    : QWidget{parent}
{
    pwFindView = new QFrame(this);
    pwFindView->setGeometry(QRect(0, 0, 260, 100));

    int viewWidth = pwFindView->width();
    int margin = 8;

    explainLabel = new QLabel("비밀번호를 찾고 싶은 아이디를 입력하세요.", this);
    explainLabel->setGeometry(QRect(margin, margin, viewWidth - (margin * 2), 30));

    idField = new QLineEdit(this);
    idField->setPlaceholderText("아이디를 입력해주세요.");
    idField->setGeometry(QRect(margin,
                               explainLabel->y() + explainLabel->height() + margin,
                               viewWidth - (margin * 2) - 66,
                               30));

    findBtn = util.makePushButton(this, "찾기", "", 12, true, "");
    findBtn->setGeometry(QRect(idField->x() + idField->width() + margin, idField->y(), 50, 30));
    connect(findBtn, SIGNAL(clicked(bool)), this, SLOT(findPw()));
}

void PwFind::findPw()
{
    if (idField->text() == "") {
        util.showErrorMsg(this, "아이디를 입력해주세요!");
        return;
    }

    bool res = util.findID("user_info.txt", idField->text());
    if (res) {
        qDebug() << "찾을 아이디 있음";
    } else {
        util.showErrorMsg(this, "존재하는 아이디가 없습니다.");
    }
}
