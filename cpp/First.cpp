#include <stdio.h>

namespace School {
    class Student
    {
    public:
        char *name;
        int age;
        float score;

        void say() {
            printf("%s的年龄是%d 期末考试得了%f\n", name, age, score);
        }
    };
   
}

int main(int argc, char const *argv[])
{
    /* code */
    class School :: Student stu1; // class可忽略
    stu1.name = "小明";
    stu1.age = 13;
    stu1.score = 59.5f;
    stu1.say();
    return 0;
}