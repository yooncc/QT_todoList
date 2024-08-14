#include "user.h"
#include "mainwindow.h"

User::User(QWidget *parent)
    : QWidget(parent)
{
    userview = new QFrame(this);
    userview->setGeometry(QRect(0, 0, 600, 600));

    labelbox = new QGroupBox("&Today's list to do", this);
    boxLayout = new QVBoxLayout;
    labelbox->setLayout(boxLayout);
    labelbox->setGeometry(QRect(0, 0, 400, 590));

    int margin = 5;
    int w = (userview->width()-(margin*3))/2;
    loadButton = util.makePushButton(this, "Load", "", 7, false, "");
    connect(loadButton, SIGNAL(clicked()), SLOT(loadList()));
    loadButton->setGeometry(QRect(labelbox->width()+margin, margin, w, 20));

    addButton = util.makePushButton(this, "Add", "", 7, false, "");
    connect(addButton, SIGNAL(clicked()), SLOT(addNewlist()));
    addButton->setGeometry(QRect(labelbox->width()+w+margin, margin, w+margin, 20));

    saveButton = util.makePushButton(this, "Save", "", 7, false, "");
    connect(saveButton, SIGNAL(clicked()), SLOT(saveList()));
    saveButton->setGeometry(QRect(userview->width(), userview->height()-30, 50, 20));

    logoutB = util.makePushButton(this, "Logout", "", 7, false, "");
    connect(logoutB, SIGNAL(clicked()), SLOT(logoutUser()));
    logoutB->setGeometry(QRect(userview->width()+80, userview->height()-30, 50, 20));
}
void User::addNewlist()
{ //새로운 리스트 추가하기 위해 lineedit 생성
    bool ok;
    QString addList
        = QInputDialog::getText(this, "Add", "Add your work", QLineEdit::Normal, NULL, &ok);
    if (ok && !addList.isEmpty()) {
        label = new ClickableLabel(this);
        label->setText(addList);
        boxLayout->addWidget(label);
        connect(label, &ClickableLabel::clicked, this, &User::onLabelClicked);
        labels.append(label);
    }
}
void User::loadList()
{
    qDebug("Load");
    qDebug()<<labels.count();
    readList(id+".txt", labels, false); //일반 list
    readList(id+"_done.txt", doneLabels, true); //done list
}
void User::saveList(){
    qDebug("Save");
    util.writeList(id+".txt", labels);
    util.writeList(id+"_done.txt", doneLabels);
}
void User::onLabelClicked(ClickableLabel *label)
{
    this->currentL = label;
    userlist = new userListEdit(this);
    userlist->show();
}
void User::modListLabel()
{
    currentL->setText(userlist->mod);
}
void User::delListLabel()
{
    labels.removeOne(currentL);
    boxLayout->removeWidget(currentL);
    currentL->deleteLater();
    currentL = nullptr;
}
void User::doneListLabel()
{
    doneLabels.append(currentL);
    labels.removeOne(currentL); //doneLabel로 옮김
    currentL->setText("<span style='text-decoration: line-through;'>" + currentL->text()+ "</span>");
    currentL->setStyleSheet("QLabel { color : gray; }");
}
void User::readList(QString filename, QList<ClickableLabel*>& list, bool clear){
    QFile file(filename);
    if (!file.open(QIODevice::ReadWrite)) {
        qDebug() << "파일 생성 실패";
        return;
    }
    QTextStream in(&file);
    QString line;
    while (!in.atEnd()) {
        line = in.readLine();
        label = new ClickableLabel(this);
        label->setText(line);
        connect(label, &ClickableLabel::clicked, this, &User::onLabelClicked);
        if(clear==true)
            label->setStyleSheet("QLabel { color : gray; }");
        list.append(label);
        boxLayout->addWidget(label);
    }
    file.close();
}
void User::logoutUser(){
    this->close();
    ((MainWindow*)this->parent())->logout();
}
User::~User() {}
