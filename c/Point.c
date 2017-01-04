// 指针
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int a = 10;
    printf("%d\n", a);
    int *point = &a;
    //*point = 20;
    a = 30;
    // point = 10;
    printf("%d\n", *point);
    *point = 40;
    printf("%d\n", a);

    // 利用指针输出字符串
    char *str = "Hello World!";
    int charLength = strlen(str);
    // 数组的变量名相当于第一个元素的指针
    char *strPoint = str;
    printf("Hello World!.length = %d\n", charLength);
    // 利用指针输出字符串
    printf("Pointer print: ");
    for (int i = 0; i < charLength; ++i)
    {
        printf("%c", *(strPoint + i));
    }
    printf("\n");
    printf("%s ", "char array");
    for (int i = 0; i < charLength; ++i)
    {
        printf("%c", str[i]);
    }
    printf("\n");

    return 0;
}