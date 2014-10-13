#ifndef USERCARSWINDOW_H
#define USERCARSWINDOW_H
#include "../logic/user.h"
#include "../logic/usercar.h"
#include <QMainWindow>
#include <stddef.h>  // defines NULL
#include "../extensions.h"

namespace Ui {
class UserCarsWindow;
}

class UserCarsWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit UserCarsWindow(QWidget *parent = 0, User *user = new User());
    ~UserCarsWindow();

private:
    Ui::UserCarsWindow *ui;
    void addUserCars(User *);
    void generateCarwidget(QPixmap, QString, QString, QString, int, int, int);

};

#endif // USERCARSWINDOW_H
