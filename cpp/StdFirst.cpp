#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
    using namespace std;

    string name;
    int age;

    // console in 从控制台输入
    cin>>name>>age;
    // 将数据输出到控制台
    cout<<name<<"已经"<<age<<"岁了"<<endl;

    return 0;
}