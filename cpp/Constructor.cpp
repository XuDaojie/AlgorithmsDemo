#include <iostream>

class Student
{
private:
    const std::string m_type;

    std::string m_name;
    int m_age;
    float m_score;
public:
    // 普通函数初始化
    // Student(std::string name, int age, float score) {
    //     m_name = name;
    //     m_age = age;
    //     m_score = score;
    // }

    // 函数初始化表
    // Student(std::string name, int age, float score): m_name(name), m_age(age), m_score(score) {
    //     // TODO
    // }
    // 函数初始化表 部分参数使用
    Student(std::string name, int age, float score): m_age(age), m_score(score) {
        m_name = name;
        // TODO
    }

    // 初始化const
    Student(std::string type, std::string name, int age, float score)
        : m_type(type), m_name(name), m_age(age), m_score(score) {
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
    void showType() {
        std::cout<<"初始化const "<<m_type<<m_name<<"今年"<<m_age<<"岁,考了"<<m_score<<"分\n";
    }
};

int main(int argc, char const *argv[])
{
    Student stu("王小二", 12, 59.5f);
    stu.showInfo();
    // print 成员函数 王小二今年12岁,考了59.5分

    Student stu1("小学生", "王小二", 12, 59.5f);
    stu1.showType();
    return 0;
}