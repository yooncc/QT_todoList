#include "login.h"
#include "mainwindow.h"

Login::Login(QWidget *parent)
    : QWidget{parent}
{
    loginView = new QFrame(this);
    loginView->setGeometry(QRect(0, 0, 200, 200));

    int viewWidth = loginView->width();
    int margin = 8;
    idField = new QLineEdit(this);
    idField->setPlaceholderText("아이디를 입력해주세요.");
    idField->setGeometry(QRect(margin, margin, viewWidth - (margin * 2), 30));
    // idField->setFrameRect();

    pwField = new QLineEdit(this);
    pwField->setPlaceholderText("비밀번호를 입력해주세요.");
    pwField->setGeometry(
        QRect(margin, (idField->y()) + (idField->height()) + margin, viewWidth - (margin * 2), 30));

    loginBtn = util.makePushButton(this, "Log in", "", 8, false, "");
    loginBtn->setGeometry(QRect(margin,
                                pwField->y() + pwField->height() + margin,
                                (viewWidth - (margin * 3)) / 2,
                                30));
    connect(loginBtn, SIGNAL(clicked()), this, SLOT(startLogin()));

    signBtn = util.makePushButton(this, "Sign up", "", 8, false, "");
    signBtn->setGeometry(QRect(loginBtn->x() + loginBtn->width() + margin,
                               pwField->y() + pwField->height() + margin,
                               (viewWidth - (margin * 3)) / 2,
                               30));
    connect(signBtn, SIGNAL(clicked()), this, SLOT(startSignUp()));

    findPwBtn = util.makePushButton(this, "비밀번호 찾기", "", 8, false, "");
    findPwBtn->setGeometry(
        QRect(margin, loginBtn->y() + loginBtn->height() + margin, viewWidth - (margin * 2), 30));
    connect(findPwBtn, SIGNAL(clicked(bool)), this, SLOT(startFindPw()));

    helpBtn = util.makePushButton(this, "도움말", "", 8, false, "");
    helpBtn->setGeometry(
        QRect(margin, findPwBtn->y() + findPwBtn->height() + margin, viewWidth - (margin * 2), 30));
    connect(helpBtn, SIGNAL(clicked(bool)), this, SLOT(programHelp()));
}

void Login::startLogin()
{
    // 빈칸 체크
    if (idField->text() == "" || pwField->text() == "") {
        util.showErrorMsg(this, "모든 항목을 채워주세요!");
        return;
    }

    if (idField->text() == "admin" && pwField->text() == "123123") {
        ((MainWindow *) (this->parent()))->successedLogin(idField->text());
    } else {
        QString res = util.findIDPW("user_info.txt", idField->text());
        if (res != "") {
            if (pwField->text() == res.split(";")[1].removeLast()) {
                qDebug("로그인 성공!");
                ((MainWindow *) (this->parent()))->successedLogin(idField->text());
            } else {
                qDebug("비밀번호가 틀립니다!");
            }
        } else {
            util.showErrorMsg(this, "존재하지 않는 아이디입니다.");
        }
    }
}

void Login::startSignUp()
{
    s = new sign();
    s->show();
}

void Login::startFindPw()
{
    pwfind = new PwFind();
    pwfind->show();
}

void Login::programHelp()
{
    QMessageBox::information(
        this,
        "도움말",
        "admin 계정으로 로그인하면 매니저권한으로 접속합니다.\nID:admin, PW:123123",
        QMessageBox::Yes);
}
