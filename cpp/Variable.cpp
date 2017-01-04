// C语言局部变量和全局变量
#include <stdio.h>

int x = 20;

int main(int argc, char const *argv[])
{
    int x = 10;
    printf("%d\n", x);
    // 变量重名时使用访问全局变量
    printf("%d\n", ::x);
    return 0;
}