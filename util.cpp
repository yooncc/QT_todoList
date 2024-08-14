#include "util.h"

Util::Util(QObject *parent)
    : QObject{parent}
{}

QPushButton *Util::makePushButton(QWidget *parent = nullptr,
                                  QString name = "",
                                  QString fontName = "",
                                  int fontSize = 12,
                                  bool isBold = false,
                                  QString icon = "")
{
    QPushButton *newPushBtn = new QPushButton(name, parent);
    // newPushBtn->setText(name);
    newPushBtn->setIcon(QIcon(icon));
    QFont font;
    font.setFamily(fontName);
    font.setPointSize(fontSize);
    font.setBold(isBold);
    newPushBtn->setFont(font);

    return newPushBtn;
}

void Util::showErrorMsg(QWidget *parent, QString errMsg)
{
    QMessageBox::question(parent, "에러 발생", errMsg, QMessageBox::Yes);
}

void Util::readFile(QString filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::ReadWrite)) {
        qDebug() << "파일 생성 실패";
        return;
    }
    QTextStream in(&file);
    QString line = in.readLine();

    while (!line.isNull()) {
        qDebug() << line;
    }
    file.close();
}
bool Util::findID(QString filename, QString search)
{
    QFile file(filename);
    if (!file.open(QIODevice::ReadWrite)) {
        qDebug() << "파일 생성 실패";
        exit(0);
    }

    QTextStream in(&file);
    QString line;
    bool isFind = false;
    while (!in.atEnd()) {
        line = in.readLine();
        qDebug() << line;
        qDebug() << line.split(";")[0];
        if (line.split(";")[0] == search) {
            isFind = true;
            break;
        }
    }
    file.close();
    return isFind;
}

QString Util::findIDPW(QString filename, QString search)
{
    QFile file(filename);
    if (!file.open(QIODevice::ReadWrite)) {
        qDebug() << "파일 생성 실패";
        exit(0);
    }

    QTextStream in(&file);
    QString line;
    while (!in.atEnd()) {
        line = in.readLine();
        qDebug() << line;
        qDebug() << line.split(";")[0];
        if (line.split(";")[0] == search) {
            file.close();
            return line;
        }
    }
    file.close();
    return "";
}

void Util::writeFile(QString filename, QString input)
{
    QFile file(filename);
    if (!file.open(QIODevice::ReadWrite | QIODevice::Append)) {
        qDebug() << "파일 생성 실패";
        return;
    }
    QByteArray msg = input.toUtf8();
    file.write(msg);
    file.close();
}
void Util::writeList(QString filename, QList<ClickableLabel*> list)
{
    QFile file(filename);
    if (!file.open(QIODevice::ReadWrite | QIODevice::Truncate)) {
        qDebug() << "파일 생성 실패";
        return;
    }
    for(int i=0;i<list.size();i++){
    //    QByteArray msg = input.toUtf8();
        QString line = list[i]->text()+"\n";
        QByteArray msg = line.toUtf8();
        file.write(msg);
    }
    file.close();
}
