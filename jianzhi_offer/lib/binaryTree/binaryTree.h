typedef struct BinaryTreeNode {
    int value; // 节点元素值
    struct BinaryTreeNode *lChild; // 指向左孩子的指针
    struct BinaryTreeNode *rChild; // 指向右孩子的指针
} BinaryTreeNode, *BinaryTree;

/**
 * 先序遍历二叉树
 * @param T
 */
void preOrder(BinaryTree T);

/**
 * 中序遍历二叉树
 * @param T
 */
void inOrder(BinaryTree T);

/**
 * 后序遍历二叉树
 * @param T
 */
void postOrder(BinaryTree T);

/**
 * 通过先序遍历序列的中序遍历序列重建二叉树
 * @param preOrder
 * @param inOrder
 * @param length
 * @return
 */
BinaryTree constructByPreOrderAndInOrder(int *preOrder, int *inOrder, int length);