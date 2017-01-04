#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node; // 函数无法识别结构体的不完整声明，但另一个结构体中可识别
typedef char *ElementType;
typedef struct Node *List; // 将Node的指针重命名为List

List makeEmpty(List list);
struct Node* getLast(List list);
struct Node* get(int position, List);
int indexOf(ElementType x, List list);
//struct Node* find(ElementType x, List list);
void add(ElementType x, List list);
void insert(ElementType x, List list, int position);
void delete(ElementType x, List list);
void deleteAll(List list);
int size(List list);

struct Node {
    ElementType element;
    struct Node *next;
};

int main(int argc, char const *argv[])
{
    List list = NULL;
    list = makeEmpty(list);
    // (&list) -> element  == list.element
    // 1.如果变量表示结构体本身则使用 `.` 获取成员
    // 2.如果变量表示结构体指针则使用 `->`获取成员
    printf("List.firstNode.element = %s\n", list -> element);
//    printf("List.firstNode.element = %s\n", list.element);
//    printf("List.firstNode.element = %p\n", list.next);
    printf("实参地址 %p\n", list);
    printf("LinkedList.size()=%d\n", size(list));
    add("poistion: 0", list);
    add("poistion: 1", list);
    add("position: 2", list);
    struct Node *node0 = get(0, list);
    struct Node *node2 = get(2, list);
    struct Node *node3 = get(3, list);
    printf("kth0:%s\n", node0 -> element);
    printf("kth2:%s\n", node2 -> element);
    // struct Node *node3 为NULL，抛出异常
//    printf("kth3:%s\n", node3 -> element);
    insert("insert position:0", list, 0);
//    struct Node *node1 = find("poistion: 1", list);
//    printf("find:%s\n", node1 -> element);
    delete("insert position:0", list);
    deleteAll(list);
    return 0;
}

List makeEmpty(List list) {
    // 由于是局部变量，函数结构后内存就回收了，所以不能使用 ``
//    struct Node header = {"Header", NULL};
//    list = &header;
    
//    list->element = "Header";
//    list->next = NULL;
    
    // 结构体指针需要初始化
    list = (List)malloc(sizeof(struct Node));
    list -> element = "Header";
    list -> next = NULL;
    return list;
}

struct Node* getLast(List list) {
    struct Node *pNodeTemp = list;
    while(pNodeTemp -> next != NULL) {
        pNodeTemp = pNodeTemp -> next;
    }
    
    return pNodeTemp;
}

struct Node* get(int k, List list) {
    struct Node *pNodeTemp = list;
    if (k < size(list)) {
        for (int i = 0; i <= k; i++) {
            pNodeTemp = pNodeTemp -> next;
        }
        return pNodeTemp;
    }
    return NULL;
}

int size(List list) {
    int count = 0;
    struct Node *pNodeTemp = list -> next;
    while (pNodeTemp != NULL) {
        ++count;
        pNodeTemp = pNodeTemp -> next;
    }
    return count;
}

/**
 * 在末位添加
 */
void add(ElementType x, List list) {
    printf("行参地址 %p\n", list);
    struct Node * pNextNode = malloc(sizeof(struct Node));
    pNextNode -> element = x;
    pNextNode -> next = NULL;
    if (size(list) == 0) {
        list -> next = pNextNode;
    } else {
        struct Node* pLastNode = getLast(list);
        (pLastNode -> next) = pNextNode;
    }
}

void insert(ElementType x, List list, int position) {
    // 3种情况
    // 1. 插入到首位
    // 2. 加入到中间
    // 3. 添加到末位(可直接调用`add`)
    if (position >= size(list)) {
        // 末尾
        add(x, list);
    } else {
        struct Node *newNode = malloc(sizeof(struct Node));
        newNode -> element = x;
        if (position == 0) {
            // 首位
            struct Node *oldNode = get(0, list);
            newNode -> next = oldNode;
            list -> next = newNode;
        } else {
            // 中间
            struct Node *preNode = get(position - 1, list);
            struct Node *oldNode = preNode -> next;
            newNode -> next = oldNode;
            preNode -> next = newNode;
        }
    }
}

//struct Node* find(ElementType x, List list) {
//    if (size(list) != 0) {
//        struct Node *tempNode = list;
//        while (tempNode -> next != NULL) {
//            tempNode = tempNode -> next;
//            // strcmp() 判断字符串是否相等，需要引入 string.h
//            if (strcmp(tempNode -> element, x) == 0) {
//                return tempNode;
//            }
//        }
//    }
//    return NULL;
//}

int indexOf(ElementType x, List list) {
    if (size(list) != 0) {
        int position = -1;
        struct Node *tempNode = list;
        
        while (tempNode -> next != NULL) {
            ++position;
            tempNode = tempNode -> next;
            // strcmp() 判断字符串是否相等，需要引入 string.h
            if (strcmp(tempNode -> element, x) == 0) {
                return position;
            }
        }
    }
    return -1;
}

void delete(ElementType x, List list) {
    int position = indexOf(x, list);
    if (position == -1) {
        printf("not found %s", x);
        return;
    } else {
        struct Node *preNode = NULL;
        struct Node *delNode = NULL;
        struct Node *nextNode = NULL;
        if (position == 0) {
            preNode = list;
        } else {
            preNode = get(position - 1, list);
        }
        delNode = preNode -> next;
        nextNode = delNode -> next;
        preNode -> next = nextNode;
        
        if (delNode != NULL) {
            // 释放内存
            free(delNode);
        }
    }
}

void deleteAll(List list) {
    struct Node *tempNode = list -> next;
    struct Node *nextNode = NULL;
    list -> next = NULL;
    while (tempNode != NULL) {
        nextNode = tempNode -> next;
        free(tempNode);
        tempNode = nextNode;
    }
}