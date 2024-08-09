#ifndef UTIL_H
#define UTIL_H

#include <QObject>
#include <QPushButton>
#include <QMessageBox>
#include <QFile>
#include <QDir>

class Util : public QObject
{
    Q_OBJECT
private:
    QDir* directory;
public:
    explicit Util(QObject *parent = nullptr);
    QPushButton* makePushButton(QWidget *parent,QString name,QString fontName,int fontSize,bool isBold,QString icon);
    void showErrorMsg(QWidget *parent,QString errMsg);
    void readFile(QString filename);
    void writeFile(QString filename,QString input);
    bool findID(QString filename,QString search);
    QString findIDPW(QString filename,QString search);

signals:
};

#endif // UTIL_H
