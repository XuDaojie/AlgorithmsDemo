#include <stdio.h>

int main()
{
    int a, b;
    // EOF相当于输入Ctrl+Z
    while(scanf("%d%d", &a, &b) != EOF)
    {
        printf("%d\n", a + b);
    }
    return 0;
}
