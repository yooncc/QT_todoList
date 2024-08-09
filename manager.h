#ifndef MANAGER_H
#define MANAGER_H

#include <QWidget>
#include <QFrame>

class Manager : public QWidget
{
    Q_OBJECT
private:
    QFrame* managerView;

public:
    explicit Manager(QWidget *parent = nullptr);


signals:
};

#endif // MANAGER_H
