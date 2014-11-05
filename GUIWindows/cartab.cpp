#include "cartab.h"
#include "ui_cartab.h"

carTab::carTab(userCar *car, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::carTab)
{
    ui->setupUi(this);
    ui->brand->setText(car->brand);
    ui->color->setText(car->color);
    ui->id->setText(QString::number(car->id));
    ui->VIN->setText(car->VIN);
    ui->model->setText(car->model);
    ui->motor->setText(car->motor);
    ui->year->setText(QString::number(car->year));
}

carTab::~carTab()
{
    delete ui;
}
