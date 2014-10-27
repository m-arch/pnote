#ifndef NOTEWINDOW_H
#define NOTEWINDOW_H

#include <QMainWindow>
#include "../extensions.h"

namespace Ui {
class NoteWindow;
}

class NoteWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit NoteWindow(QWidget *parent = 0);
    ~NoteWindow();
    void setUserIdLabel(QString);

private slots:
    void on_browseButton_clicked();

    void on_CancelButton_clicked();

    void on_saveButton_clicked();

private:
    Ui::NoteWindow *ui;
    bool checkFormFields();

};

#endif // NOTEWINDOW_H
