#ifndef PWFIND_H
#define PWFIND_H

#include <QFrame>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>
#include "util.h"

class PwFind : public QWidget
{
    Q_OBJECT
private:
    QFrame *pwFindView;
    QLabel *explainLabel;
    QLineEdit *idField;
    QPushButton *findBtn;
    QLabel *pwFindLabel;
    Util util;

public:
    explicit PwFind(QWidget *parent = nullptr);
public slots:
    void findPw();

signals:
};

#endif // PWFIND_H
