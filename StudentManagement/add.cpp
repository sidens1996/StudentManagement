#include "add.h"
#include "ui_add.h"
#include "student.h"
#include <QFile>
#include <QMessageBox>
#include "display.h"
#include <fstream>
#include <iostream>

using namespace std;

Add::Add(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Add)
{
    ui->setupUi(this);
}

Add::~Add()
{
    delete ui;
}

void Add::setZero()
{
    ui->lineEdit_number->setText(QString::number(0));
    ui->lineEdit_name->setText(QString::number(0));
    ui->lineEdit_chinese->setText(QString::number(0));
    ui->lineEdit_math->setText(QString::number(0));
    ui->lineEdit_english->setText(QString::number(0));
}

void Add::on_pushButton_clicked()
{
    Student stu;

    //读取QString类型数据并存入对象的成员变量
    strcpy(stu.data[0],ui->lineEdit_number->text().toLocal8Bit().data());
    strcpy(stu.data[1],ui->lineEdit_name->text().toLocal8Bit().data());

    stu.chinese = ui->lineEdit_chinese->text().toInt();
    stu.math = ui->lineEdit_math->text().toInt();
    stu.english = ui->lineEdit_english->text().toInt();
    stu.sum = stu.chinese + stu.math + stu.english;

    //对输入做简单判断
    if(stu.data[0][0] == '0' && stu.data[1][0] == '0')
    {
        QMessageBox::information(NULL, "提示", "输入不合法！", QMessageBox::Yes);
        return;
    }

    //存入文件,使用C++方式
    ofstream filePath("D:/stuData.txt",ios::app);
    while(filePath.is_open())
    {
        filePath << stu.data[0] << " " << stu.data[1] << " " << stu.chinese << " "
                                << stu.math << " " << stu.english << " " << stu.sum << " " << endl;
        filePath.close();
        QMessageBox::information(NULL, "提示", "添加成功！", QMessageBox::Yes);
        Add::setZero();
        return;
    }

//QT方式写入文件
//    QFile file("D:/stuData.txt");//相对路径
//    if(file.open(QIODevice::WriteOnly | QIODevice::Append |QIODevice::Text))//WriteOnly:只写，Aappend:追加方式
//        //Text:支持换行写入
//    {
//        QByteArray byte_number(stu.data[0]),byte_name(stu.data[1]),byte_space(" "),
//                byte_enter("\r\n");
//        file.write(byte_number + byte_space + byte_name + byte_space
//                   + QString::number(stu.chinese).toLatin1() + byte_space
//                   + QString::number(stu.math).toLatin1() + byte_space
//                   + QString::number(stu.english).toLatin1() + byte_space
//                   + QString::number(stu.sum).toLatin1() + byte_enter);
//        QMessageBox::information(NULL, "提示", "添加成功！", QMessageBox::Yes);
//        Add::setZero();
//        return;
//    }

}
