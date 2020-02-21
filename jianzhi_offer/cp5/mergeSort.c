#include <stdio.h>
#include <stdlib.h>

/**
 * 递归进行归并排序
 * @param data
 * @param copy
 * @param start
 * @param end
 */
void mergeSortCore(int *data, int *copy, int start, int end) {
    if (start == end) { return; }

    int mid = (start + end) / 2;
    // 子数组先进行归并排序，使左右两数组各自有序
    mergeSortCore(data, copy, start, mid);
    mergeSortCore(data, copy, mid + 1, end);

    // 从左右两边数组的第一个元素出发，依次遍历，每次取小的那个数放到辅助数组中，直到任一数组遍历完
    int *pL = data + start;
    int *pR = data + mid + 1;
    int *pCopy = copy + start;
    for (; pL <= data + mid && pR <= data + end; ++pCopy) {
        if (*pL < *pR) { *pCopy = *(pL++); }
        else { *pCopy = *(pR++); }
    }
    // 将未超出界限的另一个数组中的数复制到辅助数组中
    while (pL <= data + mid) { *pCopy = *(pL++); }
    while (pR <= data + end) { *pCopy = *(pR++); }
    // 把辅助数组中排好序的序列复制回原数组
    for (int i = 0; i <= end - start; ++i) {
        *(data + start + i) = *(copy + start + i);
    }
}

/**
 * 归并排序
 * @param data
 * @param length
 */
void mergeSort(int *data, int length) {
    if (data == NULL || length <= 0) { return; }

    // 预分配一个和原数组大小相等的辅助数组
    int *copyData = (int *) malloc(sizeof(int) * length);

    mergeSortCore(data, copyData, 0, length - 1);
    free(copyData);
}

int main() {
    int data[] = {9, 2, 4, 1, 5, 3, 6};
    mergeSort(data, 7);
    for (int i = 0; i < 7; ++i) {
        printf("%d ", data[i]);
    }

    return 0;
}