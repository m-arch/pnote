#include "notewindow.h"
#include "ui_notewindow.h"

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
