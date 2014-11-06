#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QMainWindow>
#include "../extensions.h"
#include "../logic/user.h"
#include <tr1/unordered_map>
using namespace std::tr1;

namespace Ui {
class MenuWindow;
}

class MenuWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MenuWindow(QWidget *parent = 0, User *user = 0);
    ~MenuWindow();
    void showMenuWindow();


private slots:
    void on_addUserButton_clicked();
    void on_addNoteButton_clicked();
    void loadFirstUser();
    void setUserFields(User);
    void loadUser(User);
    void on_nextUser_clicked();
    void on_previousUser_clicked();

    void on_printVinButton_clicked();

private:
    Ui::MenuWindow *ui;
    //Ui::MainWindow *mainWin;
};

void fillCarWidget(QWidget *, userCar);
void drawCar(QWidget *, QPixmap, QString, QString, QString, int, int, int);
void fillCarsWidget(QWidget *, unordered_map<int, userCar>);
void setCarsFields(QWidget *, unordered_map<int, userCar>);
#endif // MENUWINDOW_H
