#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dbsetup.h"
#include "dbconnect.h"
#include "utilities.h"
#include <QFileDialog>

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
    //do not forget to make the home location in a global variable that depends on the os arch
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
        char* newPath = new char[64];

        QString imagePath = ui->fileLocation->text();
        util.generateString(newPath, 64);
        QFile::copy(imagePath, QString::fromStdString(newPath));
    }
}

bool MainWindow::checkFormFields()
{
    return true;
}
