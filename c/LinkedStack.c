#include <stdio.h>
#include <stdlib.h>

struct Node;
struct Stack;
typedef char *ElementType; // 栈每个节点中包含的数据

struct Stack* makeEmpty(struct Stack* stack); // 创建空栈
struct Node* top(); // 栈顶节点
void push(struct Stack *stack, ElementType element); // 入栈
void pop(struct Stack *stack); // 出栈
void popAll(struct Stack *stack); // 清空
// 栈内元素数量
int size();

struct Stack
{
    struct Node *topNode;
};

struct Node
{
    ElementType element;
    struct Node *downNode;
};

struct Stack* makeEmpty(struct Stack* stack) {
    stack = (struct Stack *)malloc(sizeof(struct Stack));
    return stack;
}

void popAll(struct Stack *stack) {
    struct Node *topNode = stack -> topNode;
    while(topNode != NULL) {
        pop(stack);
        topNode = stack -> topNode;
    }
}

struct Node* top(struct Stack* stack) {
    if (stack != NULL)
    {
        return stack -> topNode;
    }
    printf("%s\n", "stack is null");
    return NULL;
}

void push(struct Stack *stack, ElementType element) {
    struct Node *topNode = top(stack);
    
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode -> element = element;
    newNode -> downNode = topNode;
    stack -> topNode = newNode;
}

void pop(struct Stack *stack) {
    struct Node *topNode = stack -> topNode;
    if (topNode != NULL)
    {
        struct Node *node = topNode -> downNode;
        stack -> topNode = node;
        free(topNode);
    }
    else
    {
        printf("%s\n", "stack is empty");
    }
}

int size(struct Stack *stack) {
    struct Node *topNode = stack -> topNode;
    int size = 0;
    while (topNode != NULL) {
        ++size;
        topNode = topNode -> downNode;
    }
    return size;
}

void start() {
    printf("%s\n", "LinkedStack start");
    struct Stack *stack = NULL;
    stack = makeEmpty(stack);
    push(stack, "节点 1");
    push(stack, "节点 2");
//    struct Node *node = top(stack);
    // printf("push %s\n", node -> element);
    // pop(stack);
//    popAll(stack);
//     struct Node *node1 = top(stack);
//     printf("pop %s\n", node1 -> element);
//     if (node1 == NULL)
//     {
//         printf("clear \n");
//     }
    printf("size %d\n", size(stack));
    pop(stack);
    printf("size %d\n", size(stack));
}

int main(int argc, char const *argv[])
{
    /* code */
    start();
    return 0;
}