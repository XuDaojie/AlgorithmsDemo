#include <stdio.h>
// 输入10个数字 输出最大值及最小值
int main(int argc, char const *argv[])
{
    int a[10] = {0};
    int max, min;
    for (int i = 0; i < 10; ++i)
    {
        // 可以将多个输入值以空格分隔，也可以回车确认输入
        // 2 123 45 100 575 240 799 710 10 90
        scanf("%d", &a[i]);
    }
    max = a[0];
    min = a[0];
    for (int i = 0; i < 10; i++) {
        if (a[i] > max) {
            max = a[i];
        }
        if (a[i] > max) {
            min = a[i];
        }
    }
    printf("max:%d min:%d\n", max, min);
    
    return 0;
}