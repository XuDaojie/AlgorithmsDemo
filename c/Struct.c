// 结构体
#include <stdio.h>

int main(int argc, char const *argv[])
{
    struct stu
    {
        int id;
        char *name;
        float score;
    };
    struct stu stu1 = {3, "王小二", 22};
    printf("id: %d, name: %s\n", stu1.id, stu1.name);
    printf("%lu\n", sizeof(stu1.name));

    printf("----- 结构体数组 ---\n");
    // 结构体数组
    struct stu class[5] = {
        {1, "王小1", 13},
        {2, "王小2", 55},
        {3, "王小3", 30},
        {4, "王小4", 76},
        {5, "王小5", 20}
    };
    int count = sizeof(class) / sizeof(struct stu);
    printf("class count: %d\n", count);
    float average, sum = 0;
    for (int i = 0; i < count; ++i)
    {
        sum += class[i].score;
    }
    average = sum / count;
    printf("average is %f\n", average);

    printf("----- 结构体和指针\n");
    struct stu *pStu = &stu1;
    printf("%s\n", pStu -> name);

    printf("stu %x, &stu %x\n", stu1, &stu1);

    return 0;
}