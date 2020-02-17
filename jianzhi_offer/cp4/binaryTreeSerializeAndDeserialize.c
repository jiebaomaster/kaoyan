#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../lib/binaryTree/binaryTree.h"

// P194 二叉树的序列化和反序列化

/**
 * 用先序遍历序列化二叉树，NUll 指针输出 $
 * @param T
 * @param serializeString
 */
void serialize(BinaryTree T, char *serializeString) {
    if (T == NULL) {
        strcat(serializeString, "$,");
    } else {
        char tmp[] = {T->value + '0', ',', '\0'};
        strcat(serializeString, tmp);
        serialize(T->lChild, serializeString);
        serialize(T->rChild, serializeString);
    }
}

/**
 * 反序列化二叉树，序列为带 NULL 输出的先序遍历的
 * 根据中序遍历和先序遍历可以反序列化二叉树，但是有两个缺点：
 * 1. 二叉树节点的值不能相等
 * 2. 不支持流式输入，只能全部接受完输入之后才开始建立节点
 * @param serializeString
 * @return
 */
BinaryTree deserialize(char **serializeString) {
    if (serializeString == NULL) { return NULL; }
    if (**serializeString == ',') {
        *serializeString = *serializeString + 1;
    }
    if (**serializeString == '$') {
        *serializeString = *serializeString + 1;
        return NULL;
    } else {
        BinaryTreeNode *pNode = (BinaryTreeNode *) malloc(sizeof(BinaryTreeNode));
        pNode->value = **serializeString - '0';
        *serializeString = *serializeString + 1;
        pNode->lChild = deserialize(serializeString);
        *serializeString = *serializeString + 1;
        pNode->rChild = deserialize(serializeString);
        return pNode;
    }
}

int main() {
    char serializeString[] = "1,2,4,$,$,$,3,5,$,$,6,$,$,";
    char *pSerializeString = serializeString;
    BinaryTree T = deserialize(&pSerializeString);
    preOrder(T);
    printf("\n");
    /**
     * 字符串的长度不确定，需要在堆上动态分配内存空间，在栈上分配的大小不定的数组其元素值不确定，会导致判断'\0'的库函数（如strcat）出错
     * 在堆上动态分配的和在栈上定长分配的字符串，会被初始化为 '\0'
     * 加一是为了容纳字符串终结符 '\0'
     */
    char *serializeStringResult = (char *) malloc(sizeof(char) * (strlen(serializeString) + 1));
    serialize(T, serializeStringResult);
    for (int i = 0; serializeStringResult[i] != '\0'; ++i) {
        printf("%c", serializeStringResult[i]);
    }
    free(serializeStringResult);

    return 0;
}