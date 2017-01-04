// C语言入门教程 http://c.biancheng.net/cpp/html/3093.html
// standard io
#include <stdio.h>

int main(int argc, char const *argv[])
{
    puts("Hello World!");
    // 16进制ASCII码打印 Hello World!
    puts("\x48\x65\x6c\x6c\x6f \x57\x6f\x72\x6c\x64\x21");
    printf("%f\n", 1.33);

    float a = 0.33;
    int b = 3;
    long c = 3;
    short d = 3;
    char e = '3';
    
    // printf("%d %d %d %d %d/n", sizeof(a), sizeof(b), sizeof(c), sizeof(d), sizeof(e));
    // sizeof 的返回值 在64位下为long unsigned int, 所有要用%lu、 %zu
    printf("%lu %lu %lu %lu %lu %lu\n", sizeof(a), sizeof(b), sizeof(c), sizeof(d), sizeof(e), sizeof(int));
    printf("%zu\n", sizeof(b));

    unsigned long f = 133;
    printf("%lu\n", f);

    double g = 78.429;
    // 输出 float 使用 %f 控制符，输出 double 使用 %lf 控制符, int 和 long 类似
    // %f 默认保留六位小数，不足六位以 0 补齐，超过六位按四舍五入截断
    printf("%lf\n", g);
    printf("%ld\n", c);
    printf("%f\n", 128.101);
    // 字符串实际上就是一个char数组，只是末尾值为 '\0'
    char charArray[] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '!', '\0'};
    printf("%s\n", charArray);

    int h = -3;
    printf("%u\n", (unsigned)h);

    char[] strArray = {"Hello World!"};

    return 0;
}