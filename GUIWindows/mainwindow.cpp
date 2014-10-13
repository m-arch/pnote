#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "../logic/dbsetup.h"
#include "../dbconnect.h"
#include "../logic/utilities.h"
#include <QFileDialog>
#include <QtSql>
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
    QString queryStr;
    char* ID = new char[64];
    QSqlQuery query ;
    if (checkFormFields() == true)
    {

        generateString(ID, 64);
        QString idValue = QString::fromStdString(ID);
        queryStr = "INSERT INTO pnote.user (ID, First_Name, Last_Name, Contact_Number, Other_Contact, notes) VALUES ('"
                        + idValue + "', '"
                        + ui->FirstName->text() + "', '"
                        + ui->LastName->text() + "', '"
                        + ui->Phone->text() + "', '"
                        + ui->OtherContact->text() + "', '"
                        + ui->userNote->toPlainText() +"');";
        qDebug() << queryStr;
        query.exec(queryStr);
        initialize().addUserToHash(idValue.toStdString(), ui->FirstName->text().toStdString(), ui->LastName->text().toStdString(),
                          ui->Phone->text().toStdString(), ui->OtherContact->text().toStdString(), ui->userNote->toPlainText().toStdString());

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
