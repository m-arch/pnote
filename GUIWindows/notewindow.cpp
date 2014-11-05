#include "notewindow.h"
#include "ui_notewindow.h"
#include <QFileDialog>
#include "../logic/utilities.h"
#include "menuwindow.h"
#include "../logic/usercar.h"
#include "../logic/dbconnect.h"

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
}


void NoteWindow::on_CancelButton_clicked()
{
    this->close();
    MenuWindow *mw = new MenuWindow(this);
    mw->show();
}

void NoteWindow::on_saveButton_clicked()
{
    if(this->checkFormFields()){
        userCar newCar;
        QString imagePath = ui->Color->text();
        if (imagePath != "")
        {
            std::string savedImagePath = saveImage(imagePath);
            newCar.setCar(ui->carVIN->text(), ui->Plate_Number->text(), ui->userId->text(), ui->Color->text(), ui->Brand->text(), ui->Model->text(),
                          ui->Motor->text(), ui->Year->text().toInt());
            createConnection();
            newCar.insertUserCar();
            closeConnection();

        }
        User user;
        user = getUserbyId(ui->userId->text());
        this->close();
        MenuWindow *mw = new MenuWindow(this,&user);
        mw->show();
    }
}

bool NoteWindow::checkFormFields()
{
    return true;
}

void NoteWindow::setUserIdLabel(QString userId)
{
    ui->userId->setText(userId);
}

