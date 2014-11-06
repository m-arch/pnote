#ifndef VINLOOKUP_H
#define VINLOOKUP_H

#include <QDialog>

namespace Ui {
class vinlookup;
}

class vinlookup : public QDialog
{
    Q_OBJECT

public:
    explicit vinlookup(QWidget *parent = 0);
    ~vinlookup();

private slots:
    void on_printButton_clicked();

    void on_CancelButton_clicked();

private:
    Ui::vinlookup *ui;
};

#endif // VINLOOKUP_H
