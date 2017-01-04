#include <iostream>

class Student
{
private:
    std::string m_name;
    int m_age;
    float m_score;
public:
    // 必须要初始化后才能使用，并且只能在类外部初始化
    static int s_total;

    Student(std::string name, int age, float score): m_name(name), m_age(age), m_score(score) {
        // TODO
    }
    
    std::string getName() {
        return m_name;
    }
    int getAge() {
        return m_age;
    }
    float getScore() {
        return m_score;
    }
    void showInfo() {
        std::cout<<"成员函数 "<<m_name<<"今年"<<m_age<<"岁,考了"<<m_score<<"分\n";
    }
};

// 初始化静态变量
int Student::s_total = 20;

int main(int argc, char const *argv[])
{
    using namespace std;

    Student::s_total = 10;
    Student stu("王小二", 1, 12.5f);
    cout<<Student::s_total<<endl;
    return 0;
}