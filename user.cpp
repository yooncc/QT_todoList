#include "user.h"

User::User(QWidget *parent)
    : QWidget(parent)
{

    //로그인하면 파일 불러오도록 함 -> txt파일 읽어서 등록
    //list에 등록해서 전부 나오도록
    //add버튼은 그대로 맨 위
    this->setGeometry(QRect(0, 0, 500, 600));
    grid = new QGridLayout(this);

    loadButton = new QPushButton("Load");
    connect(loadButton, SIGNAL(clicked()), SLOT(loadList()));

    addButton = new QPushButton("Add");
    connect(addButton, SIGNAL(clicked()), SLOT(addNewlist()));

//    labelbox = new QGroupBox("&Today's list to do", this);
//    formLayout = new QFormLayout;
//    labelbox->move(5, 70);
//    labelbox->setLayout(formLayout);

    QLabel* labelList = new QLabel("test");
 //   formLayout->addWidget(labelList);
 //   formLayout->addRow(labelList);
 //   formLayout->addRow(labelList);
    grid->addWidget(loadButton, 0, 0, 1, 2);
    grid->addWidget(addButton, 1, 0, 1, 2);
//    grid->addWidget(labelList, 2, 0);

    //기존 창 -> to do list, add버튼만 보이도록함
    //label 클릭하면 수정, 삭제, 완료 버튼 보임
}
void User::addNewlist(){ //새로운 리스트 추가하기 위해 lineedit 생성
    bool ok;
    QString addList = QInputDialog::getText(this, "Add", "Add your work", QLineEdit::Normal, NULL, &ok);
//    listLabel = new QLabel();
//    listLabel->setText(addList);
//    grid->addWidget(listLabel, count+2, 0);
//    count++;

    label = new ClickableLabel(this);
    label->setText(addList);
    grid->addWidget(label, count+2, 0);
    connect(label, &ClickableLabel::clicked, this, &User::onLabelClicked);
/*    connect(label, &ClickableLabel::clicked, this, [label](){
        onLabelClicked();
    });*/
    count++;

//    formLayout->addRow(listLabel);
 //   formLayout->addWidget(listLabel);

    //쓰지 않고 끄는 경우도 생각
}
void User::loadList(){
    qDebug("Load");
}
void User::onLabelClicked(ClickableLabel* label){
    this->currentL = label;
    userlist = new userListEdit(this);
    userlist->show();
}
void User::modListLabel(){
    currentL->setText(userlist->mod);
    qDebug()<<userlist->mod;
}
void User::delListLabel(){
    qDebug()<<currentL->text()+" DELETE";
    grid->removeWidget(currentL);
    currentL->deleteLater();
//    count--;
}
void User::doneListLabel(){
    currentL->setText("<span style='text-decoration: line-through;'>" + currentL->text() + "</span>");
    currentL->setStyleSheet("QLabel { color : gray; }");
}
User::~User(){}
