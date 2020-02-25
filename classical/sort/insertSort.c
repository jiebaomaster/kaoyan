#include <stdio.h>

/**
 * 简单插入排序
 * @param data
 * @param length
 */
void insertSort(int data[], int length) {
    for (int i = 1; i < length; ++i) { // 进行 n-1 趟排序
        int tmp = data[i];
        int j = i;
        while (j > 0 && data[j - 1] > tmp) { // 有序部分元素后移
            data[j] = data[j - 1];
            j--;
        }
        data[j] = tmp; // 插入到指定位置
    }
}


int main() {
    int data[] = {2, 1, 4, 2, 4, 6, 9};
    insertSort(data, 7);
    for (int i = 0; i < 7; ++i) {
        printf("%d ", data[i]);
    }

    return 0;
}