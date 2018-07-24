#include "display.h"
#include "ui_display.h"
#include <QTableView>
#include <QStandardItemModel>
#include <QFile>
#include "add.h"
#include "student.h"

Display::Display(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Display)
{
    ui->setupUi(this);
}

Display::~Display()
{
    delete ui;
}


void Display::on_pushButton_clicked()
{
    Student stuD[1000];//建立一个大小为1000的对象数组

    //设置table属性
    QStandardItemModel* model = new QStandardItemModel(this);
    model->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("学号")));
    model->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("姓名")));
    model->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("语文")));
    model->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("数学")));
    model->setHorizontalHeaderItem(4, new QStandardItem(QObject::tr("英语")));
    model->setHorizontalHeaderItem(5, new QStandardItem(QObject::tr("总分")));

    int index = ui->comboBox->currentIndex();//得到排序要求

    //QT方式读取文件
    QFile file("D:/stuData.txt");//相对路径
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    int i = 0,length = 0;
    //提取文件数据到对象数组中，算出文件中存储的学生数目
    while(!file.atEnd())
    {
        QString line = file.readLine();
        QStringList lst = line.split(" ");//读取以空格分开的字符串

        //将数组存入对象数组成员，lst[0]是QString类型，stuD[i].data[0]是字符型数组
        strcpy(stuD[length].data[0],((QString)lst[0]).toLocal8Bit().data());
        strcpy(stuD[length].data[1],((QString)lst[1]).toLocal8Bit().data());

        stuD[length].chinese = ((QString)lst[2]).toInt();
        stuD[length].math = ((QString)lst[3]).toInt();
        stuD[length].english = ((QString)lst[4]).toInt();
        stuD[length].sum = ((QString)lst[5]).toInt();

        length++;
    }

    //分四种情况排序，实质上是对对象数组排序
    Student temp;//作为交换中介
    switch(index)
    {
    case 0://以默认方式排序
        break;
    case 1://以语文成绩排序
        for(int x = 0;x < length - 1;x++)
        {
            for(int y = x + 1;y < length;y++)
            {
                if(stuD[x].chinese < stuD[y].chinese)
                {
                    temp = stuD[x];
                    stuD[x] = stuD[y];
                    stuD[y] = temp;
                }
            }
        }
        break;
    case 2://以数学成绩排序
        for(int x = 0;x < length - 1;x++)
        {
            for(int y = x + 1;y < length;y++)
            {
                if(stuD[x].math < stuD[y].math)
                {
                    temp = stuD[x];
                    stuD[x] = stuD[y];
                    stuD[y] = temp;
                }
            }
        }
        break;
    case 3://以英语成绩排序
        for(int x = 0;x < length - 1;x++)
        {
            for(int y = x + 1;y < length;y++)
            {
                if(stuD[x].english < stuD[y].english)
                {
                    temp = stuD[x];
                    stuD[x] = stuD[y];
                    stuD[y] = temp;
                }
            }
        }
        break;
    case 4://以总分成绩排序
        for(int x = 0;x < length - 1;x++)
        {
            for(int y = x + 1;y < length;y++)
            {
                if(stuD[x].sum < stuD[y].sum)
                {
                    temp = stuD[x];
                    stuD[x] = stuD[y];
                    stuD[y] = temp;
                }
            }
        }
        break;
    }
    //显示
    while(i < length)
    {
        model->setItem(i, 0, new QStandardItem(QString("%1").arg(stuD[i].data[0])));
        model->setItem(i, 1, new QStandardItem(QString("%1").arg(stuD[i].data[1])));

        model->setItem(i, 2, new QStandardItem(QString::number(stuD[i].chinese)));
        model->setItem(i, 3, new QStandardItem(QString::number(stuD[i].math)));
        model->setItem(i, 4, new QStandardItem(QString::number(stuD[i].english)));
        model->setItem(i, 5, new QStandardItem(QString::number(stuD[i].sum)));
        i++;
    }
    ui->tableView->setModel(model);
}
