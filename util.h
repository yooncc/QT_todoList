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
    QString readFile(QString filename);
    void writeFile(QString filename,QString input);
    bool deleteFile(QString filename,QString input);
    bool findID(QString filename,QString search);
    QString findIDPW(QString filename,QString search);
    QAction *makeAction(QString icon,QString text,QString shortCut,\
                        QString toolTip,QObject* recv,const char* slot);

signals:
};

#endif // UTIL_H
