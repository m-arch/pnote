#include "cartab.h"
#include "ui_cartab.h"

carTab::carTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::carTab)
{
    ui->setupUi(this);
}

carTab::~carTab()
{
    delete ui;
}
