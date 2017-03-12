/**
 * 二叉查找树 后序
 */
#include <stdio.h>
#include <stdlib.h> // free()

struct Node;
struct BinaryTree;
typedef struct Node *BinaryTree;
typedef int Value;
void printError(char *msg);
struct BinaryTree* createBinaryTree();
void add(struct BinaryTree *tree, Value value);
int compare(Value val1, Value val2);
void addNode(struct Node *pMayParent, struct Node* pNewNode); // 通过递归增加子节点

struct Node
{
    Value value;
    struct Node *pLeftChild;
    struct Node *pRightChild;
};

struct BinaryTree
{
    struct Node *pRootNode;
};

struct BinaryTree* createBinaryTree() {
    struct BinaryTree *tree = (struct BinaryTree *) malloc(sizeof(struct BinaryTree));
    tree -> pRootNode = NULL;
    return tree;
}

void add(struct BinaryTree *tree, Value value) {
    if (tree == NULL)
    {
        printError("tree is NULL");
    } else
    {
        struct Node *pRootNode = tree -> pRootNode;
        struct Node *pNewNode = (struct Node *) malloc(sizeof(struct Node));
        pNewNode -> value = value;
        pNewNode -> pLeftChild = NULL;
        pNewNode -> pRightChild = NULL;
        if (pRootNode == NULL)
        {
            // 空树
            tree -> pRootNode = pNewNode;
        } else
        {
            addNode(pRootNode, pNewNode);
        }
    }
}

void addNode(struct Node *pMayParent, struct Node* pNewNode) {
    int result = compare(pMayParent -> value, pNewNode -> value);
    if (result > 0)
    {
        // left
        if (pMayParent -> pLeftChild == NULL) {
            pMayParent -> pLeftChild = pNewNode;
        } else {
            addNode(pMayParent -> pLeftChild, pNewNode);
        }
    } else if (result < 0)
    {
        // right
        if (pMayParent -> pRightChild == NULL) {
            pMayParent -> pRightChild = pNewNode;
        } else {
            addNode(pMayParent -> pRightChild, pNewNode);
        }
    } else {
        // 相等
        free(pNewNode);
        printError("value is exited");
    }
}

/**
 * 比较值的大小
 * val1 > val2 > 0; val1 == val2 = 0; val1 < val2 < 0;
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

void printError(char *msg) {
    printf("%s\n", msg);
}

void test() {
    struct BinaryTree *tree = createBinaryTree();
    add(tree, 2);
    add(tree, 5);
    add(tree, 1);
    add(tree, 4);
    add(tree, 6);
}

int main(int argc, char const *argv[])
{
    test();
    return 0;
}