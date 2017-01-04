#include <iostream>

class People
{
private:
    std::string m_name;
    int m_age;   

public:
    People(std::string name, int age): m_name(name), m_age(age) {
        // TODO
    }
    std::string getName() {
        return m_name;
    }
    void setName(std::string name) {
        m_name = name;
    }
    int getAge() {
        return m_age;
    }
    void setAge(int age) {
        m_age = age;
    }
    void info() {
        std::cout<<m_name<<"今年"<<m_age<<"岁了\n";
    }
    People() {
    }
};

// std::string getName() {
//     return m_name;
// }
// void setName(std::string name) {
//     m_name = name;
// }
// int getAge() {
//     return m_age;
// }
// void setAge(int age) {
//     m_age = age;
// }
// void info() {
//     std::cout<<m_name<<"今年"<<m_age<<"岁了\n";
// }

class Student: public People
{
private:
    float m_score;
public:
    void setScore(float score) {
        m_score = score;
    }
    float getScore() { 
        return m_score;
    }

    void info() {
        std::cout<<getName()<<"今年"<<getAge()<<"岁,考了"<<m_score<<"分\n";
    }
    Student() {
    }
};

int main(int argc, char const *argv[])
{
    People people("王小二", 11);
    people.info();

    Student stu;
    stu.setName("王小三");
    stu.setAge(3);
    stu.setScore(59.5f);
    stu.info();

    return 0;
}