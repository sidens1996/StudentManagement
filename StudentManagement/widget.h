#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "add.h"
#include "display.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Widget *ui;
    Add add;//不能用指针
    Display display;

};

#endif // WIDGET_H
