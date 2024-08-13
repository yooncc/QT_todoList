#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QWidget>

class mainView : public QWidget
{
    Q_OBJECT

public:
    mainView(QWidget *parent = nullptr);
    ~mainView();
};
#endif // MAINVIEW_H
