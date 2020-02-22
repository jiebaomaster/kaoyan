#include <stdio.h>
#include <stdlib.h>

/**
 * 递归进行逆序对的计算
 * 逆序对数 = 左子数组逆序对数 + 右子数组逆序对数 + 左右组间逆序对数
 * @param data
 * @param copy
 * @param start
 * @param end
 */
int inversePairsCore(int *data, int *copy, int start, int end) {
    if (start == end) {
        *(copy + start) = *(data + start);
        return 0;
    }

    int mid = (start + end) / 2;
    // 子数组先进行归并排序，使左右两数组各自有序
    // 本题最终不需要排好序，故可以交替使用 data 和 copy 数组，避免了算法最后把辅助数组中排好序的序列复制回原数组
    int left = inversePairsCore(copy, data, start, mid); // 左子数组逆序对数
    int right = inversePairsCore(copy, data, mid + 1, end); // 右子数组逆序对数

    // 从左右两边数组的最后一个元素出发，依次遍历，每次取小的那个数放到辅助数组中，直到任一数组遍历完
    int *pL = data + mid;
    int *pR = data + end;
    int *pCopy = copy + end;
    int count = 0; // 左右组间逆序对数
    for (; pL >= data + start && pR >= data + mid + 1; --pCopy) {
        if (*pL < *pR) { *pCopy = *(pR--); }
        else { // 左大于右，即存在逆序对，且左元素与右元素以及右数组中所以未遍历的元素都构成逆序对
            *pCopy = *(pL--);
            count += (int) (pR - (data + mid + 1) + 1);
        }
    }
    // 将未超出界限的另一个数组中的数复制到辅助数组中
    while (pL >= data + start) { *pCopy = *(pL--); }
    while (pR >= data + mid + 1) { *pCopy = *(pR--); }

    return left + right + count;
}

/**
 * P249 利用归并排序进行数组中逆序对的计算，数组中前一个数字大于后一个数字，则这两个数字构成一个逆序对
 * @param data
 * @param length
 */
int inversePairs(int *data, int length) {
    if (data == NULL || length <= 0) { return -1; }

    // 预分配一个和原数组大小相等的辅助数组
    int *copyData = (int *) malloc(sizeof(int) * length);
    for (int i = 0; i < length; ++i) {
        *(copyData + i) = *(data + i);
    }
    int result = inversePairsCore(data, copyData, 0, length - 1);
    free(copyData);
    return result;
}

int main() {
    int data[] = {7, 5, 6, 4};
    int result = inversePairs(data, 4);
    printf("%d\n", result);
    for (int i = 0; i < 4; ++i) {
        printf("%d ", data[i]);
    }

    return 0;
}