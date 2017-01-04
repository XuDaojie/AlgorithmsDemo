#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    printf("%ld\n", strlen("Hello World!"));
    char str1[20] = "Hello";
    char str2[10] = "World";
    // strcat 将把 str1 连接到 str2 后面，
    // 并删去 str1 最后的结束标志 '\0'。这就意味着，str1 的长度要足够，必须能够同时容纳 str1 和 str2，否则会越界。
    printf("%s\n", strcat(str1, str2));

    char str3[20] = "Hello";
    // char *str4 = "World";
    // strcpy与strcat 类似,但是并不会删去结束标志'\0'
    printf("%s\n", strcpy(str3, str2));

    // strcom str compare 
    // 比较ascii值
    // 返回值：若 arrayName1 和 arrayName2 相同，则返回0；
    // 若 arrayName1 大于 arrayName2，则返回大于 0 的值；若 arrayName1 小于 arrayName2，则返回小于0 的值。
    printf("strcom:%d\n", strcmp("xdj", "xdj"));

    char a[30];
    // 会将空格当做结束符,
    // gets()读取不会将空格作为结束符
    scanf("%s", a);
    printf("%s\n", a);

    return 0;
}