// C语言指针变量作为函数参数
#include <stdio.h>

int max(int numArray[], int numLength);
int min(int numArray[], int numLength);

int main(int argc, char const *argv[])
{
    int numArray[] = {12, 55, 30, 8, 93, 27};
    int numLength = sizeof(numArray) / sizeof(int);

    // 传递的实际不是整个数组，而是数组的指针
    int maxVal = max(numArray, numLength);
    int minVal = min(numArray, numLength);

    printf("max: %d\n", maxVal);
    printf("min: %d\n", minVal);

    return 0;
}

int max(int numArray[], int numLength) {
    int max = numArray[0];
    for (int i = 0; i < numLength; ++i)
    {
        if (numArray[i] > max)
        {
            max = numArray[i];
        }
    }
    return max;
}

int min(int numArray[], int numLength) {
    int min = numArray[0];
    for (int i = 0; i < numLength; ++i)
    {
        printf("%d ", numArray[i]);
        if (numArray[i] < min)
        {
            min = numArray[i];
        }
    }
    return min;
}