#ifndef LOGIN_H
#define LOGIN_H


#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QFrame>
#include <QStackedLayout>
#include "sign.h"
#include "pwfind.h"
#include "util.h"

class Login : public QWidget
{
    Q_OBJECT
private:
    QLineEdit* idField;
    QLineEdit* pwField;
    QPushButton* loginBtn;
    QPushButton* signBtn;
    QPushButton* findPwBtn;
    QPushButton* helpBtn;
    QFrame* loginView;
    QStackedLayout* stackedLayout;
    sign* s;
    PwFind* pwfind;
    Util util;
public:
    explicit Login(QWidget *parent = nullptr);

public slots:
    void startLogin();
    void startSignUp();
    void startFindPw();
    void programHelp();

signals:

};

#endif // LOGIN_H
