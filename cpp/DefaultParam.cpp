#include <iostream>
// 函数默认参数

void m1(int i = 0, float f = 1.2f, char c = '@') {
    using namespace std;
    cout<<"i="<<i<<" f="<<f<<" c="<<c<<endl;
}

// 错误 默认参数必须在形参后面
// 默认参数后面的参数必须都是默认参数
// void m2(int i = 0, float f, char c) {
//     using namespace std;
//     cout<<"i="<<i<<" f="<<f<<" c="<<c<<endl;
// }

int main(int argc, char const *argv[])
{
    //相当于调用 m1(0, 1.2f, '@');
    m1();
    //相当于调用 m1(1.2f, '@');
    m1(100);
    //相当于调用 m1('@');
    m1(100, 59.5f);

    return 0;
}