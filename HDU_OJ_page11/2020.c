#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 输入n(n<=100)个整数，按照绝对值从大到小排序后输出。题目保证对于每一个测试实例，所有的数的绝对值都不相等。
// http://acm.hdu.edu.cn/showproblem.php?pid=2020

/**
 * 可自定义排序规则的冒泡排序
 * @param data
 * @param length
 * @param compare 确定排序规则的函数
 */
void bubbleSort(int *data, int length, bool (*compare)(int, int)) {
    int tmp;
    bool hasChange;
    for (int i = 0; i < length - 1; ++i) {
        hasChange = false;
        for (int j = 0; j < length - i - 1; ++j) {
            if (compare(*(data + j), *(data + j + 1))) {
                tmp = *(data + j + 1);
                *(data + j + 1) = *(data + j);
                *(data + j) = tmp;
                hasChange = true;
            }
        }
        if (!hasChange) { break; } // 本次冒泡没有发生交换，则数组已经有序
    }
}

/**
 * 绝对值比较函数
 * @param cur
 * @param next
 * @return
 */
bool compare(int cur, int next) {
    if (cur < 0) { cur = -cur; }
    if (next < 0) { next = -next; }
    return cur < next;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        if (n == 0) { break; }

        int *data = (int *) malloc(sizeof(int) * n);
        for (int i = 0; i < n; ++i) { // input
            scanf("%d", data + i);
        }
        bubbleSort(data, n, compare); // sort
        for (int j = 0; j < n; ++j) { // output
            if (j == 0) {
                printf("%d", *(data + j));
            } else {
                printf(" %d", *(data + j));
            }
        }
        printf("\n");
    }

    return 0;
}