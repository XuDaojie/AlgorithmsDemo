// 指向字符串的指针
#include <stdio.h>

int main(int argc, char const *argv[])
{
    // 字符数组存储在全局数据区或栈区，第二种形式的字符串存储在常量区。
    // 全局数据区和栈区的字符串（也包括其他数据）有读取和写入的权限，
    // 而常量区的字符串（也包括其他数据）只有读取权限，没有写入权限。
    char *str = "Hello World!";
    char str2[20] = "Hello World!";
    
    str[2] = '2'; // 错误 编译不报错，但运行时报错
    str2[2] = '2';


    return 0;
}