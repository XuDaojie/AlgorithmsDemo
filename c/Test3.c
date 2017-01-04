// 共用体
#include <stdio.h>

int main(int argc, char const *argv[])
{
    // 共同体
    union asss {
        int i;
        char ch;
    };
    union asss data;
    data.i = 0x00000001;
    printf("%d\n", data.ch);

    printf("%s\n", "C语言域");
    struct test1 {
        unsigned i : 20;
        unsigned j : 22;
        unsigned k;
    } data1;
    printf("%lu\n", sizeof(struct test1));

    return 0;
}