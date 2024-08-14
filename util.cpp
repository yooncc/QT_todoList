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

QString Util::readFile(QString filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::ReadWrite)) {
        qDebug() << "파일 생성 실패";
        exit(0);
    }
    QTextStream in(&file);
    QString line = "";
    while (!in.atEnd()) {
        line.append(in.readLine());
    }
    file.close();
    return line;
}

QString Util::searchToDoInFile(QString filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::ReadWrite)) {
        qDebug() << "파일 생성 실패";
        exit(0);
    }
    QTextStream in(&file);
    QString line = "";
    while (!in.atEnd()) {
        line.append(in.readLine() + ";");
    }
    file.close();
    return line;
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
QString Util::findPW(QString filename, QString search)
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
            return line.split(";")[1];
            break;
        }
    }
    file.close();
    return "";
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
void Util::writeList(QString filename, QList<ClickableLabel *> list)
{
    QFile file(filename);
    if (!file.open(QIODevice::ReadWrite | QIODevice::Truncate)) {
        qDebug() << "파일 생성 실패";
        return;
    }
    for (int i = 0; i < list.size(); i++) {
        //    QByteArray msg = input.toUtf8();
        QString line = list[i]->text() + "\n";
        QByteArray msg = line.toUtf8();
        file.write(msg);
    }
    file.close();
}

bool Util::deleteFile(QString filename, QString input)
{
    QFile file(filename);
    if (!file.open(QIODevice::ReadWrite)) {
        qDebug() << "파일 생성 실패";
        exit(0);
    }
    QTextStream in(&file);
    QString line;
    QString newInfo = "";
    bool isFind = false;
    while (!in.atEnd()) {
        line = in.readLine();
        if (line.split(";")[0] == input) {
            isFind = true;
        } else {
            newInfo.append(line + "\n");
        }
    }
    qDebug() << newInfo;
    file.close();
    if (isFind) {
        if (!file.open(QIODevice::ReadWrite | QIODevice::Truncate)) {
            qDebug() << "파일 생성 실패";
            exit(0);
        }
        QByteArray msg = newInfo.toUtf8();
        file.write(msg);
        file.close();
        return true;
    } else {
        return false;
    }
}

QAction *Util::makeAction(
    QString icon, QString text, QString shortCut, QString toolTip, QObject *recv, const char *slot)
{
    QAction *act = new QAction(text, this);
    if (icon.length())
        act->setIcon(QIcon(icon));
    act->setShortcut(shortCut);
    act->setStatusTip(toolTip);
    connect(act, SIGNAL(triggered(bool)), recv, slot);
    return act;
}
