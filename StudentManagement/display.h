#ifndef DISPLAY_H
#define DISPLAY_H

#include <QWidget>
#include <QTableView>

namespace Ui {
class Display;
}

class Display : public QWidget
{
    Q_OBJECT

public:
    explicit Display(QWidget *parent = 0);
    ~Display();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Display *ui;

};

#endif // DISPLAY_H
