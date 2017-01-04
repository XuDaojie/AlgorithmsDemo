// C语言局部变量和全局变量
#include <stdio.h>

int x = 20;

int main(int argc, char const *argv[])
{
    int x = 10;
    printf("%d\n", x);
    // 要用全局变量，需要使用'::'，gcc不支持,需要使用g++
    // printf("%d\n", ::x);
    return 0;
}