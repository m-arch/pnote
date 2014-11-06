#include "vinlookup.h"
#include "ui_vinlookup.h"
#include "logic/dbsearch.h"
#include <QToolTip>
#include "logic/dbconnect.h"
#include "logic/generatepdf.h"

vinlookup::vinlookup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::vinlookup)
{
    ui->setupUi(this);
}

vinlookup::~vinlookup()
{
    delete ui;
}


void vinlookup::on_printButton_clicked()
{
    User *user = new User();
    userCar *car = new userCar();
    QString inputVin = ui->lineEdit->text();
    QRegExp re("^[A-Z0-9]{17}$");
    if(re.exactMatch(inputVin))
    {
        createConnection();
        getUserandCarFromVIN(ui->lineEdit->text(),user,car);
        closeConnection();
        new generatePdf(user,car);
    }
    else {
        QToolTip::showText(ui->lineEdit->mapToGlobal(QPoint()),"invalid input");
    }
}


void vinlookup::on_CancelButton_clicked()
{
     this->close();
}
