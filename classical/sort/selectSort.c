#include <stdio.h>

/**
 * 简单选择排序
 * @param data
 * @param length
 */
void selectSort(int data[], int length) {
    for (int i = 0; i < length - 1; ++i) { // 进行 n-1 趟排序
        int minIndex = i;
        for (int j = i + 1; j < length; ++j) { // 在剩余数组中找出最小的
            if (data[minIndex] > data[j]) {
                minIndex = j;
            }
        }
        // 当前将最小值放到指定位置，每一趟排序都会有一个数落在最终位置
        int tmp = data[minIndex];
        data[minIndex] = data[i];
        data[i] = tmp;
    }
}

int main() {
    int data[] = {2, 1, 4, 2, 4, 6, 9};
    selectSort(data, 7);
    for (int i = 0; i < 7; ++i) {
        printf("%d ", data[i]);
    }

    return 0;
}