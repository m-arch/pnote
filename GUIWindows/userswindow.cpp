#include "userswindow.h"
#include "ui_userswindow.h"
#include "../initialize.h"
#include <tr1/unordered_map>

using namespace std::tr1;
UsersWindow::UsersWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UsersWindow)
{
    ui->setupUi(this);
    ui->treeWidget->setColumnCount(3); //number of columns 1 for users and one for users cars
    populateTree();

}

UsersWindow::~UsersWindow()
{
    delete ui;
}

void UsersWindow::populateTree()
{
    unordered_map<QString, User> usersHash = initialize::Instance()->getUsersHash();
    unordered_map<QString, User>::iterator itr;
    for ( itr = usersHash.begin(); itr != usersHash.end(); itr++)
    {
        User tmpUser = (*itr).second;
        QTreeWidgetItem *treeItem = new QTreeWidgetItem(ui->treeWidget);
        treeItem->setText(0, tmpUser.firstName);
        treeItem->setText(1, tmpUser.lastName);
        treeItem->setText(2, tmpUser.phone);
    }
}
