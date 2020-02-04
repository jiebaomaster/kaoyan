#include <stdbool.h>

#define STACK_INIT_SIZE 5
#define STACK_INCREMENT_SIZE 2

#define ElemType int

typedef struct {
    ElemType* data; // 数据元素数组
    ElemType* top; // 栈顶指针，指向最后一个元素的下一个单元
    int stack_size;
} Stack;

/**
 *
 * @param S
 */
void InitStack(Stack *S);

/**
 * 判断栈是否为空
 * @param S
 * @return
 */
bool isStackEmpty(Stack S);

/**
 * 将一个元素压栈
 * @param S
 * @param value
 * @return
 */
bool push(Stack *S, ElemType value);

/**
 * 栈顶元素出栈
 * @param S
 * @param value
 * @return
 */
bool pop(Stack *S, ElemType *value);

/**
 * 获取栈顶元素的值
 * @param S
 * @param value
 * @return
 */
bool getTop(Stack S, ElemType *value);