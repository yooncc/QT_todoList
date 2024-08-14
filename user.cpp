#include "user.h"

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
    loadButton = new QPushButton(this);
    loadButton = util.makePushButton(this, "Load", "", 7, false, "");
    connect(loadButton, SIGNAL(clicked()), SLOT(loadList()));
    loadButton->setGeometry(QRect(labelbox->width()+margin, margin, w, 20));

    addButton = new QPushButton(this);
    addButton = util.makePushButton(this, "Add", "", 7, false, "");
    connect(addButton, SIGNAL(clicked()), SLOT(addNewlist()));
    addButton->setGeometry(QRect(labelbox->width()+w+margin, margin, w+margin, 20));

    saveButton = new QPushButton(this);
    saveButton = util.makePushButton(this, "Save", "", 7, false, "");
    connect(saveButton, SIGNAL(clicked()), SLOT(saveList()));
    saveButton->setGeometry(QRect(userview->width(), userview->height()-30, 50, 20));
}
void User::addNewlist()
{ //새로운 리스트 추가하기 위해 lineedit 생성
    bool ok;
    QString addList
        = QInputDialog::getText(this, "Add", "Add your work", QLineEdit::Normal, NULL, &ok);
    if (ok && !addList.isEmpty()) {
        label = new ClickableLabel(this);
        label->setText(addList);
        boxLayout->addWidget(label, count + 2);
        connect(label, &ClickableLabel::clicked, this, &User::onLabelClicked);
        labels.append(label);
        count++;
    }
    //위에서부터 차례대로 추가하는 방법(위치)
}
void User::loadList()
{
    qDebug("Load");
    //done list도 파악해서 거기에 포함되어잇으면 줄그어두기...
}
void User::saveList(){
    qDebug("Save");
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
    qDebug() << userlist->mod;
}
void User::delListLabel()
{
    qDebug() << currentL->text() + " DELETE";
    labels.removeOne(currentL);
    boxLayout->removeWidget(currentL);
    currentL->deleteLater();
    count--;
    currentL = nullptr;
}
void User::doneListLabel()
{
    currentL->setText("<span style='text-decoration: line-through;'>" + currentL->text()
                      + "</span>");
    currentL->setStyleSheet("QLabel { color : gray; }");
    //done QList 추가해서 거기에도 추가해두기
}
User::~User() {}
