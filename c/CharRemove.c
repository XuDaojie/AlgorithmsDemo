// 字符消除
#include <stdio.h>
#include <string.h>

void input(char *str);

int main(int argc, char const *argv[])
{
    int count = 0;
    scanf(%d, &count);
    for (int i = 0; i < count; ++i)
    {
        input("xxxx");
    }
    return 0;
}

void input(char *str)
{
    int size = strlen(str);
    printf("%d\n", size);
}