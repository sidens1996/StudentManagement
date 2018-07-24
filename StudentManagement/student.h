#ifndef STUDENT_H
#define STUDENT_H

class Student{
public:
    char data[2][20];
    int chinese;
    int math;
    int english;
    int sum;
    //使用二维字符数组存储学生信息
    //data[0]:学号
    //data[1]:姓名
};

#endif // STUDENT_H
