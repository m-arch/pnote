#ifndef NOTEWINDOW_H
#define NOTEWINDOW_H

#include <QMainWindow>

namespace Ui {
class NoteWindow;
}

class NoteWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit NoteWindow(QWidget *parent = 0);
    ~NoteWindow();

private slots:
    void on_browseButton_clicked();

    void on_CancelButton_clicked();

    void on_saveButton_clicked();

private:
    Ui::NoteWindow *ui;
    bool checkFormFields();

};

#endif // NOTEWINDOW_H
