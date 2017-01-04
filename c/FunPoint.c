// 函数指针 指向函数的指针
#include <stdio.h>

int max(int a, int b);

int main(int argc, char const *argv[])
{
    // returnType (*pointerName)(param list);
    int (*pmax)(int, int) = max;
    int maxVal = (*pmax)(1, 2);
    printf("max value : %d\n", maxVal);
    return 0;
}

int max(int a, int b)
{
    if (a > b)
        return a;

    return b;
}