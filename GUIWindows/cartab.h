#ifndef CARTAB_H
#define CARTAB_H

#include <QWidget>

namespace Ui {
class carTab;
}

class carTab : public QWidget
{
    Q_OBJECT

public:
    explicit carTab(QWidget *parent = 0);
    ~carTab();

private:
    Ui::carTab *ui;
};

#endif // CARTAB_H
