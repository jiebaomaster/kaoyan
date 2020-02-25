#include <stdio.h>

/**
 * 冒泡排序
 * @param data
 * @param length
 */
void bubbleSort(int data[], int length) {
    for (int i = 0; i < length - 1; ++i) { // 进行 n-1 趟排序
        int flag = 1;
        for (int j = i; j < length - i - 1; ++j) { // 最大值冒泡到 length-i-1 位置
            if (data[j] > data[j + 1]) {
                int tmp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = tmp;
                flag = 0;
            }
        }
        if (flag) { break; } // 本次未发生冒泡，则数组已经有序
    }
}


int main() {
    int data[] = {2, 1, 4, 2, 4, 6, 9};
    bubbleSort(data, 7);
    for (int i = 0; i < 7; ++i) {
        printf("%d ", data[i]);
    }

    return 0;
}