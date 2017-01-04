#include <stdio.h>
#include <time.h>

// clock_t 是clock()函数返回的类型
clock_t start,stop;
double duration;

int main()
{
    start = clock();
    printf("%s\n", "xx");
    stop = clock();
    duration = ((double) (stop - start)) / CLK_TCK;
    printf("%d\n", (double) (start - stop));
    return 0;
}