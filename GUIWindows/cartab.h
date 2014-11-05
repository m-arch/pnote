#ifndef CARTAB_H
#define CARTAB_H

#include <QWidget>
#include "logic/usercar.h"

namespace Ui {
class carTab;
}

class carTab : public QWidget
{
    Q_OBJECT

public:
    explicit carTab(userCar *car = 0,QWidget *parent = 0);
    ~carTab();

private:
    Ui::carTab *ui;
};

#endif // CARTAB_H
