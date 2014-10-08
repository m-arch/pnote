#ifndef USERSWINDOW_H
#define USERSWINDOW_H
#include <QTreeWidget>
#include <QMainWindow>
#include "user.h"
#include "usercar.h"

namespace Ui {
class UsersWindow;
}

class UsersWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit UsersWindow(QWidget *parent = 0);
    ~UsersWindow();

private:
    Ui::UsersWindow *ui;
    void populateTree ();
    void addCarToUser (userCar);
};

#endif // USERSWINDOW_H
