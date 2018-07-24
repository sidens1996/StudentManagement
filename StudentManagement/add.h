#ifndef ADD_H
#define ADD_H

#include <QWidget>
#include "student.h"

namespace Ui {
class Add;
}

class Add : public QWidget
{
    Q_OBJECT

public:
    explicit Add(QWidget *parent = 0);
    ~Add();

    void setZero();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Add *ui;
};

#endif // ADD_H
