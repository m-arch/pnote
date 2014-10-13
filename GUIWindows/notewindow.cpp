#include "notewindow.h"
#include "ui_notewindow.h"
#include <QFileDialog>
#include "../logic/utilities.h"
#include "menuwindow.h"
#include "../logic/usercar.h"

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


void NoteWindow::on_CancelButton_clicked()
{
    this->hide();
    MenuWindow *mw = new MenuWindow(this);
    mw->show();
}

void NoteWindow::on_saveButton_clicked()
{
    if(this->checkFormFields()){
        char* ID = new char[64];
        generateString(ID, 64);
        QString idValue = QString::fromStdString(ID);

        QString imagePath = ui->fileLocation->text();
        if (imagePath != "")
        {
            std::string savedImagePath = saveImage(imagePath);
            userCar newCar;
            newCar.setCar(idValue.toStdString(), "userId", savedImagePath, ui->Brand->text().toStdString(), ui->Model->text().toStdString(),
                          ui->Motor->text().toStdString(), ui->Year->text().toInt());
            newCar.insertUserCar();

        }

    }
}

bool NoteWindow::checkFormFields()
{
    return true;
}
