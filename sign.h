#ifndef SIGN_H
#define SIGN_H

#include <QFrame>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>
#include "util.h"

class sign : public QWidget
{
    Q_OBJECT
private:
    QFrame *signView;
    QLineEdit *idField;
    QLineEdit *pwField;
    QLineEdit *repwField;
    QPushButton *signUpBtn;

public:
    explicit sign(QWidget *parent = nullptr);
    Util util;
    void signComplete();

public slots:
    void signUpProcess();

signals:
};

#endif // SIGN_H
