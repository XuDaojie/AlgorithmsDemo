#include <stdio.h>

void printN(int n)
{
    for (int i = 1; i < n; ++i)
    {
        printf("%d\n", i);
    }
}

int main(int argc, char const *argv[])
{
    // 默认情况下,函数声明对顺序是要求的
    // 一个函数内调用的其他函数必须在他之前声明
    printN(1000000);
    return 0;
}