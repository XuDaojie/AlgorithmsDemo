#include <iostream>

// 成员函数的调用
// http://c.biancheng.net/cpp/biancheng/view/2996.html
class Student
{

public:
    std::string name;
    int age;
    float score;

    void info(Student stu) {
        std::cout<<"成员函数 "<<stu.name<<"今年"<<stu.age<<"岁,考了"<<stu.score<<"分\n";
    }

    void info() {
        std::cout<<"成员函数 "<<name<<"今年"<<age<<"岁,考了"<<score<<"分\n";
    }
};

int main(int argc, char const *argv[])
{
    using namespace std;

    Student stu;
    stu.name = "王小二";
    stu.age = 12;
    stu.score = 22.5f;

    cout<<stu.name<<"今年"<<stu.age<<"岁,考了"<<stu.score<<"分"<<endl;
    stu.info(stu);
    stu.info();

    return 0;
}