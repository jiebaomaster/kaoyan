#include <stdio.h>
#include <stdbool.h>

/**
 * P21 调整数组顺序，将满足某一条件的数据排在前面，其余的排在后面
 * 可类比快速排序的 partition 函数
 * @param data
 * @param length
 * @param func 函数作为参数，一个判断是否满足某一条件的函数
 */
void reorder(int data[], int length, bool (*func)(int)) {
    if (data == NULL || length <= 0) {
        return;
    }

    int start = 0, end = length - 1;
    while (start < end) {
        while (start < end && func(data[start])) { start++; } // 从前往后找出一个不满足条件的数
        while (start < end && !func(data[end])) { end--; } // 从后往前找出一个满足条件的数
        if (start != end) { // 交换两个数的位置
            int tmp = data[start];
            data[start] = data[end];
            data[end] = tmp;
        }
    }
}

/**
 * 判断一个数是否是偶数
 * @param number
 * @return
 */
bool isEven(int number) {
    return (number & 1) == 0;
}

/**
 * 将一个数组按偶数在前奇数在后重新排列
 * @param data
 * @param length
 */
void reorderListEvenAndOdd(int data[], int length) {
    reorder(data, length, isEven);
}

int main() {
    int data[] = {1, 2, 3, 4, 5};
    reorderListEvenAndOdd(data, 5);
    for (int i = 0; i < 5; ++i) {
        printf("%d", data[i]);
    }

    return 0;
}