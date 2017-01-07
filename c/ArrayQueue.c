/**
 * 队列
 * 利用循环数组实现
 */

#include <stdio.h>
#include <stdbool.h> // C99中加入的头文件，用于支持bool，但是实际还是用整形进行存储
#include <stdlib.h>

typedef char *ElementType;
struct Node;
struct Queue;

bool isEmpty(struct Queue *queue);
bool isFull(struct Queue *queue);
struct Queue createQueue(int capacity);
void disposeQueue(struct Queue *queue);
void clearQueue(struct Queue *queue);
void enqueue(struct Queue *queue, ElementType element);
void dequeue(struct Queue *queue);
struct Node* getFront(struct Queue *queue);
struct Node* getReal(struct Queue *queue);

void printError(char *msg);

struct Node
{
    ElementType element;
};

struct Queue
{
    int capacity;
    int frontPosition;
    int realPosition;
    int size;
    // C语言中数组必须要在声明时指定，我们只能通过数组的首地址获得声明
    struct Node *array;
};

/**
 * 创建一个新队列
 */
struct Queue createQueue(int capacity) {
    struct Queue queue;
    struct Node *array = (struct Node *)malloc(sizeof(struct Node) * capacity);
    
    queue.capacity = capacity;
    queue.frontPosition = capacity - 1;
    queue.realPosition = queue.frontPosition;
    queue.size = 0;
    queue.array = array;
    
    return queue;
}

bool isEmpty(struct Queue *queue) {
    if (queue -> size == 0)
    {
        return true;
    }
    return false;
}

bool isFull(struct Queue *queue) {
    if (queue -> size == queue -> capacity)
    {
        return true;
    }
    return false;
}

void disposeQueue(struct Queue *queue) {
    free(queue -> array);
    queue = NULL;
}

void enqueue(struct Queue* queue, ElementType element) {
    if (isFull(queue))
    {
        printError("Queue is full");
    }
    else
    {
        struct Node newNode = {element};
        struct Node *array = queue -> array;
        int *frontPosition = &(queue -> frontPosition);
        int *realPosition = &(queue -> realPosition);
        
        if (isEmpty(queue))
        {
            queue -> realPosition = *frontPosition;
            *(array + *realPosition) = newNode;
        }
        else
        {
            // 只要real到达数组的尾端，便重新回到开头
            if (*realPosition == queue -> capacity - 1) {
                *realPosition = -1;
            }
            *(array + ++*realPosition) = newNode;
        }
        queue -> size = queue -> size + 1;
    }
}

void dequeue(struct Queue* queue) {
    if (isEmpty(queue))
    {
        printError("queue is empty");
    } else {
        int capacity = queue -> capacity;
        int *frontPosition = &(queue -> frontPosition);
//        struct Node* frontNode = getFront(queue);
        // 只要front到达数组的尾端，便重新回到开头
        if (*frontPosition == capacity - 1)
        {
            *frontPosition = -1;
        }
        ++*frontPosition;
        queue -> size = queue -> size - 1;
    }
}

struct Node* getFront(struct Queue *queue) {
    struct Node *array = queue -> array;
    return array + queue -> frontPosition;
}

struct Node* getReal(struct Queue *queue) {
    struct Node *array = queue -> array;
    return array + queue -> realPosition;
}

void printError(char *msg) {
    printf("%s\n", msg);
}

void test() {
    int *test = malloc(sizeof(int));
    for (int i = 0; i < 5; ++i) {
        *(test + i) = i;
    }
    for (int i = 0; i < 5; ++i) {
        printf("%d\n", *(test + i));
    }
    
    struct Queue queue = createQueue(10);
    enqueue(&queue, "A");
    enqueue(&queue, "0");
    enqueue(&queue, "1");
    enqueue(&queue, "2");
    dequeue(&queue);
    enqueue(&queue, "B");
    dequeue(&queue);
    
    printf("%s\t%s\t%s\n", "type", "pos", "value");
    printf("front \t%d\t%s\n", queue.frontPosition, getFront(&queue) -> element);
    printf("real \t%d\t%s\n", queue.realPosition, getReal(&queue) -> element);
}

int main(int argc, char const *argv[])
{
    /* code */
    test();
    return 0;
}