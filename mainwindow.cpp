#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dbsetup.h"
#include "dbconnect.h"
#include "utilities.h"
#include <QFileDialog>
#include <QtSql>

using namespace std;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    dbSetup();
    ui->setupUi(this);
    loadTextFile();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_browseButton_clicked()
{
    //do not forget to save home location as a global variable that depends on the os arch
    QString fileName = QFileDialog::getOpenFileName(this,
            tr("Open Image"), "/home/marc", tr("Image Files (*.png *.jpg *.bmp)"));
    ui->fileLocation->setProperty("text", fileName);
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
    if (checkFormFields() == true)
    {
        utilities util;
        QString queryString;
        char* ID = new char[64];
        QSqlQuery query ;
        util.generateString(ID, 64);
        QString idValue = QString::fromStdString(ID);
        QString imagePath = ui->fileLocation->text();
        if (imagePath != "")
            std::string savedImagePath = util.saveImage(imagePath);
        queryString = "INSERT INTO pnote.user (ID, First_Name, Last_Name, Contact_Number, Other_Contact) VALUES ('"
                        + idValue + "', '"
                        + ui->FirstName->text() + "', '"
                        + ui->LastName->text() + "', '"
                        + ui->Phone->text() + "', '"
                        + ui->OtherContact->text() + "');";
        createConnection();
        query.exec(queryString);
        closeConnection();
    }
}

bool MainWindow::checkFormFields()
{
    return true;
}
