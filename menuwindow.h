#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QMainWindow>

namespace Ui {
class MenuWindow;
}

class MenuWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MenuWindow(QWidget *parent = 0);
    ~MenuWindow();
    void showMenuWindow();

private slots:
    void on_addUserButton_clicked();

    void on_addNoteButton_clicked();

private:
    Ui::MenuWindow *ui;
    //Ui::MainWindow *mainWin;
};

#endif // MENUWINDOW_H
