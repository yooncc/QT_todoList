#include "sign.h"

sign::sign(QWidget *parent)
    : QWidget{parent}
{
    Util util;

    signView = new QFrame(this);
    signView->setGeometry(QRect(0, 0, 200, 160));

    int viewWidth = signView->width();
    int margin = 8;
    idField = new QLineEdit(this);
    idField->setPlaceholderText("아이디를 입력해주세요.");
    idField->setGeometry(QRect(margin, margin, viewWidth - (margin * 2), 30));
    // idField->setFrameRect();

    pwField = new QLineEdit(this);
    pwField->setPlaceholderText("비밀번호를 입력해주세요.");
    pwField->setGeometry(
        QRect(margin, (idField->y()) + (idField->height()) + margin, viewWidth - (margin * 2), 30));

    repwField = new QLineEdit(this);
    repwField->setPlaceholderText("비밀번호를 다시 입력해주세요.");
    repwField->setGeometry(
        QRect(margin, (pwField->y()) + (pwField->height()) + margin, viewWidth - (margin * 2), 30));

    signUpBtn = util.makePushButton(this, "회원가입 완료", "", 8, false, "");
    signUpBtn->setGeometry(
        QRect(margin, repwField->y() + repwField->height() + margin, viewWidth - (margin * 2), 30));
    connect(signUpBtn, SIGNAL(clicked()), this, SLOT(signUpProcess()));
}

void sign::signComplete()
{
    QMessageBox::StandardButton reply
        = QMessageBox::information(this,
                                   "회원가입 성공!",
                                   "회원가입한 아이디로 다시 로그인해주세요!",
                                   QMessageBox::Yes);
    if (reply == QMessageBox::Yes) {
        qDebug() << "확인 클릭함";
        this->close();
    }
}

void sign::signUpProcess()
{
    // 빈칸 체크
    if (idField->text() == "" || pwField->text() == "" || repwField->text() == "") {
        util.showErrorMsg(this, "모든 항목을 채워주세요!");
        return;
    }
    // 중복 아이디체크
    if (idField->text() == "admin") {
        util.showErrorMsg(this, "사용할 수 없는 아이디입니다.");
        return;
    }
    bool isExistID = util.findID("user_info.txt", idField->text());

    if (isExistID) {
        util.showErrorMsg(this, "이미 존재하는 아이디입니다.");
        return;
    }
    // 비밀번호 확인 체크
    if (pwField->text() == repwField->text()) {
        util.writeFile("user_info.txt", idField->text() + ";" + pwField->text() + ":\n");
    } else {
        util.showErrorMsg(this, "비밀번호를 확인해주세요.");
        return;
    }
    // 회원가입 성공
    signComplete();
}
