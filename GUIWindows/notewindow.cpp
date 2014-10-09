#include "notewindow.h"
#include "ui_notewindow.h"
#include <QFileDialog>
#include "../logic/utilities.h"
#include "menuwindow.h"

NoteWindow::NoteWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NoteWindow)
{
    ui->setupUi(this);
}

NoteWindow::~NoteWindow()
{
    delete ui;
}

void NoteWindow::on_browseButton_clicked()
{
    //do not forget to save home location as a global variable that depends on the os arch
    QString fileName = QFileDialog::getOpenFileName(this,
            tr("Open Image"), "/home/marc", tr("Image Files (*.png *.jpg *.bmp)"));
    ui->fileLocation->setProperty("text", fileName);
}


void NoteWindow::on_pushButton_clicked()
{
    utilities util;
    QString imagePath = ui->fileLocation->text();
    if (imagePath != "")
        std::string savedImagePath = util.saveImage(imagePath);
}

void NoteWindow::on_CancelButton_clicked()
{
    this->hide();
    MenuWindow *mw = new MenuWindow(this);
    mw->show();
}
