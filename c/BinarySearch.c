/**
 * 二分查找
 * 前提 数据有序存放
 */
#include <stdio.h>
void printError(char *msg);

int binarySearch(int sourceArray[], int arrayLength, int key) {
    int keyIndex = -1;
    int left = 0;
    int right = arrayLength - 1;
    int min = sourceArray[0];
    int max = sourceArray[arrayLength - 1];
    if (key < min && key > max)
    {
        printError("not found");
        return -1;
    }
    
    int middle = (left + right) / 2;
    while(sourceArray[middle] != key) {
        int middleValue = sourceArray[middle];
        if (key < middleValue)
        {
            right = middle - 1;
        } else {
            left = middle + 1;
        }
        middle = (left + right) / 2;
    }
    if (sourceArray[middle] == key)
    {
        keyIndex = middle;
    }
    
    return keyIndex;
}

void printError(char *msg) {
    printf("%s\n", msg);
}

void test() {
    int sourceArray[] = {1, 4, 5, 6, 8, 11, 13};
    int sourceLength = sizeof(sourceArray) / sizeof(sourceLength);
    int index = binarySearch(sourceArray, sourceLength, 8);
    printf("index %d\n", index);
}

int main(int argc, char const *argv[])
{
    test();
    return 0;
}