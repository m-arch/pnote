#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "../logic/dbsetup.h"
#include "../dbconnect.h"
#include "../logic/utilities.h"
#include "menuwindow.h"
#include "../initialize.h"

using namespace std;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    loadTextFile();
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::loadTextFile()
{

    QFile inputFile(":/input.txt");
    inputFile.open(QIODevice::ReadOnly);
    QTextStream in(&inputFile);
    QString line = in.readAll();
    inputFile.close();

    ui->userNote->setPlainText(line);
    QTextCursor cursor = ui->userNote->textCursor();
    cursor.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor, 1);
}

void MainWindow::on_SaveButton_clicked()
{
    createConnection();
    char* ID = new char[64];

    if (checkFormFields() == true)
    {
        generateString(ID, 64);
        QString idValue = QString::fromStdString(ID);
        User tmpUser;
        User lastUser = initialize::Instance()->lastUser;
        tmpUser.setUser(idValue, lastUser.id, ui->FirstName->text(), ui->LastName->text(), ui->Phone->text(), ui->OtherContact->text(), ui->userNote->toPlainText());
        tmpUser.insertUser();
        lastUser.nextId = idValue;
        initialize::Instance()->updateHashEntry(lastUser);
        this->close();
        MenuWindow *mw = new MenuWindow(this,&tmpUser);
        mw->show();
    }
    closeConnection();

}

bool MainWindow::checkFormFields()
{
    return true;
}

void MainWindow::on_CancelButton_clicked()
{
    this->hide();
    MenuWindow *mw = new MenuWindow(this);
    mw->show();
}
