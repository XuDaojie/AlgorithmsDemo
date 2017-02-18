/**
 * 二叉查找树
 */
#include <stdio.h>

struct Node;
struct BinaryTree;
typedef struct Node *BinaryTree;
typedef int Value;
void printError(char *msg);
struct BinaryTree* createBinaryTree();
void add(struct BinaryTree *tree, Value value);

struct Node
{
    Value value;
    struct Node *leftChild;
    struct Node *rightChild;
};

struct BinaryTree
{
    struct Node *rootNode;
};

struct BinaryTree* createBinaryTree() {
    struct BinaryTree *tree;
    return tree;
}

void add(struct BinaryTree *tree, Value value) {
    if (tree == NULL)
    {
        printError("tree is NULL");
    } else
    {
        struct Node *nodeTmp = tree -> rootNode;
        if (nodeTmp == NULL)
        {
            // 空树
        } else 
        {

        }
    }
}

/**
 * 比较值的大小
 */
int compare(Value val1, Value val2) {
    if (val1 == val2)
    {
        return 0;
    } else if (val1 > val2)
    {
        return 1;
    } else
    {
        return -1;
    }
}

void test() {
    struct BinaryTree *tree = createBinaryTree();   
}

int main(int argc, char const *argv[])
{
    test();
    return 0;
}