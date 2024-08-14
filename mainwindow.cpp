#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow{parent}
{
    this->setGeometry(QRect(50,50,200,200));
    login = new Login();
    setCentralWidget(login);
}

void MainWindow::successedLogin(QString id)
{
    qDebug() << "로그인 성공 -2";
    if (id == "admin") { // 매니저 로그인
        manager = new Manager();
        login->close();
        setCentralWidget(manager);

        QLabel *label = new QLabel("admin");
        label->setAlignment(Qt::AlignRight);
        dock = new QDockWidget(this);
        dock->setTitleBarWidget(label);

        addDockWidget(Qt::BottomDockWidgetArea,dock);
        managerToolBar = new QToolBar("Manager",this);
        addToolBar(managerToolBar);
        managerToolBar->setToolButtonStyle(Qt::ToolButtonTextOnly);

        managerToolBar->addSeparator();
        QAction* addMember = util.makeAction("","추가(Q)","Ctrl+Q","회원을 새롭게 추가합니다.",this,SLOT(managerAdd()));
        QAction* deleteMember =util.makeAction("","삭제(W)","Ctrl+W","선택한 회원 정보를 삭제합니다.",this,SLOT(managerDelete()));
        QAction* changeMember =util.makeAction("","변경(E)","Ctrl+E","회원의 정보를 변경합니다.",this,SLOT(managerChange()));
        QAction* findMember =util.makeAction("","조회(R)","Ctrl+R","회원의 정보를 조회합니다.",this,SLOT(managerFind()));
        QAction* logoutForManager =util.makeAction("","로그아웃(T)","Ctrl+T","로그아웃 합니다.",this,SLOT(managerLogout()));
        managerToolBar->addAction(addMember);
        managerToolBar->addSeparator();
        managerToolBar->addAction(deleteMember);
        managerToolBar->addSeparator();
        managerToolBar->addAction(changeMember);
        managerToolBar->addSeparator();
        managerToolBar->addAction(findMember);
        managerToolBar->addSeparator();
        managerToolBar->addAction(logoutForManager);
        managerToolBar->addSeparator();

        this->setGeometry(QRect(100,100,400,600+50));
    } 
    else { // 일반회원 로그인
        user = new User();
        user->id = id;
        login->close();
        setCentralWidget(user);
        this->setGeometry(QRect(100, 100, 1000, 600));
    }
}

void MainWindow::logout(){
    this->setGeometry(QRect(50, 50, 200, 200));
    login = new Login();
    setCentralWidget(login);
}

void MainWindow::managerAdd() {
    qDebug("add");

    QDialog dialog(this);
    // Use a layout allowing to have a label next to each field
    QFormLayout form(&dialog);

    // Add some text above the fields
    form.addRow(new QLabel("새로 등록할 회원정보를 입력해주세요."));

    // Add the lineEdits with their respective labels
    QList<QLineEdit *> fields;
    QLineEdit *idField = new QLineEdit(&dialog);
    form.addRow("ID", idField);
    QLineEdit *pwField = new QLineEdit(&dialog);
    form.addRow("PW", pwField);
    QLineEdit *repwField = new QLineEdit(&dialog);
    form.addRow("rePW", repwField);
    fields << idField << pwField << repwField;

    // Add some standard buttons (Cancel/Ok) at the bottom of the dialog
    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
                               Qt::Horizontal, &dialog);
    form.addRow(&buttonBox);
    QObject::connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));
    QObject::connect(&buttonBox, SIGNAL(rejected()), &dialog, SLOT(reject()));

    // Show the dialog as modal
    if (dialog.exec() == QDialog::Accepted) {
        // If the user didn't dismiss the dialog, do something with the fields
        QLineEdit* idField = fields[0];
        QLineEdit* pwField = fields[1];
        QLineEdit* repwField = fields[2];

        if (idField->text() == "" || pwField->text() == "" || repwField->text() == "") {
            util.showErrorMsg(this,"모든 항목을 채워주세요!");
            return;
        }
        // 중복 아이디체크
        bool isExistID = util.findID("user_info.txt",idField->text());
        if (isExistID) {
            util.showErrorMsg(this,"이미 존재하는 아이디입니다.");
            return;
        }
        // 비밀번호 확인 체크
        if (pwField->text() == repwField->text()) {
            util.writeFile("user_info.txt",idField->text()+";"+pwField->text()+":\n");
        }
        else {
            util.showErrorMsg(this,"비밀번호를 확인해주세요.");
            return;
        }
        // 회원가입 성공
        manager->getUserInfo();
    }

}
void MainWindow::managerDelete() {
    qDebug("delete");
    QDialog dialog(this);
    // Use a layout allowing to have a label next to each field
    QFormLayout form(&dialog);

    // Add some text above the fields
    form.addRow(new QLabel("탈퇴시킬 회원 아이디를 입력해주세요."));

    // Add the lineEdits with their respective labels
    QList<QLineEdit *> fields;
    QLineEdit *idField = new QLineEdit(&dialog);
    form.addRow("ID", idField);
    fields << idField;

    // Add some standard buttons (Cancel/Ok) at the bottom of the dialog
    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
                               Qt::Horizontal, &dialog);
    form.addRow(&buttonBox);
    QObject::connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));
    QObject::connect(&buttonBox, SIGNAL(rejected()), &dialog, SLOT(reject()));

    // Show the dialog as modal
    if (dialog.exec() == QDialog::Accepted) {
        // If the user didn't dismiss the dialog, do something with the fields
        QLineEdit* idField = fields[0];

        if (idField->text() == "") {
            util.showErrorMsg(this,"모든 항목을 채워주세요!");
            return;
        }
        // 아이디체크
        bool isExistID = util.deleteFile("user_info.txt",idField->text());
        if (isExistID) {
            // 삭제 성공
        }
        else {
            util.showErrorMsg(this,"존재하지 않는 아이디입니다.");
        }
        // 맴버그리드뷰 갱신
        manager->getUserInfo();
    }
}
void MainWindow::managerChange() {
    qDebug("change");

    QDialog dialog(this);
    // Use a layout allowing to have a label next to each field
    QFormLayout form(&dialog);

    // Add some text above the fields
    form.addRow(new QLabel("변경할 회원정보를 입력해주세요."));

    // Add the lineEdits with their respective labels
    QList<QLineEdit *> fields;
    QLineEdit *idField = new QLineEdit(&dialog);
    form.addRow("ID", idField);
    QLineEdit *pwField = new QLineEdit(&dialog);
    form.addRow("PW", pwField);
    QLineEdit *repwField = new QLineEdit(&dialog);
    form.addRow("rePW", repwField);
    fields << idField << pwField << repwField;

    // Add some standard buttons (Cancel/Ok) at the bottom of the dialog
    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
                               Qt::Horizontal, &dialog);
    form.addRow(&buttonBox);
    QObject::connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));
    QObject::connect(&buttonBox, SIGNAL(rejected()), &dialog, SLOT(reject()));

    // Show the dialog as modal
    if (dialog.exec() == QDialog::Accepted) {
        // If the user didn't dismiss the dialog, do something with the fields
        QLineEdit* idField = fields[0];
        QLineEdit* pwField = fields[1];
        QLineEdit* repwField = fields[2];

        if (idField->text() == "" || pwField->text() == "" || repwField->text() == "") {
            util.showErrorMsg(this,"모든 항목을 채워주세요!");
            return;
        }
        // 아이디체크
        bool isExistID = util.findID("user_info.txt",idField->text());
        if (!isExistID) {
            util.showErrorMsg(this,"존재하지 않는 아이디입니다.");
            return;
        }
        // 비밀번호 확인 체크
        if (pwField->text() == repwField->text()) {
            if ( util.deleteFile("user_info.txt",idField->text()) ) {
                util.writeFile("user_info.txt",idField->text()+";"+pwField->text()+":\n");
            }
        }
        else {
            util.showErrorMsg(this,"비밀번호를 확인해주세요.");
            return;
        }
        // 비밀번호 변경 성공
        manager->getUserInfo();
    }
}
void MainWindow::managerFind() {
    qDebug("find");
    QDialog dialog(this);
    // Use a layout allowing to have a label next to each field
    QFormLayout form(&dialog);

    // Add some text above the fields
    form.addRow(new QLabel("검색할 회원 아이디를 입력해주세요."));

    // Add the lineEdits with their respective labels
    QList<QLineEdit *> fields;
    QLineEdit *idField = new QLineEdit(&dialog);
    form.addRow("ID", idField);
    fields << idField;

    // Add some standard buttons (Cancel/Ok) at the bottom of the dialog
    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
                               Qt::Horizontal, &dialog);
    form.addRow(&buttonBox);
    QObject::connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));
    QObject::connect(&buttonBox, SIGNAL(rejected()), &dialog, SLOT(reject()));

    // Show the dialog as modal
    if (dialog.exec() == QDialog::Accepted) {
        // If the user didn't dismiss the dialog, do something with the fields
        QLineEdit* idField = fields[0];

        if (idField->text() == "") {
            util.showErrorMsg(this,"모든 항목을 채워주세요!");
            return;
        }
        // 아이디체크
        bool isExistID = util.findID("user_info.txt",idField->text());
        if (isExistID) {
            // 조회 성공
            manager->memberNameLabel->setText(idField->text());
            manager->getUserToDo(util.searchToDoInFile(idField->text()+".txt"));
        }
        else {
            util.showErrorMsg(this,"존재하지 않는 아이디입니다.");
        }
    }
}

void MainWindow::managerLogout() {
    manager->close();
    this->removeDockWidget(dock);
    this->removeToolBar(managerToolBar);
    this->setGeometry(QRect(50,50,200,200));
    login = new Login();
    setCentralWidget(login);
}
    
