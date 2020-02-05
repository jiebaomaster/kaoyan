#include <stdio.h>

/**
 * 选择第一个数作为中轴，将比中轴值小的放在左边，比中轴值大的放在右边
 * @param data
 * @param start
 * @param end
 * @return
 */
int partition(int data[], int start, int end) {
    int pivot = data[start]; // 第一个数为中轴
    while (start < end) {
        while (start < end && pivot <= data[end]) { // 从后往前找到一个比中轴小的
            end--;
        }
        data[start] = data[end];
        while (start < end && pivot >= data[start]) { // 从前往后找到一个比中轴大的
            start++;
        }
        data[end] = data[start];
    }
    data[start] = pivot; // 最终 end=start，指向中轴元素所在位置
    return start;
}

/**
 *
 * @param data
 * @param start
 * @param end
 */
void quickSort_recursive(int data[], int start, int end) {
    if (start == end) { return; }

    int index = partition(data, start, end);
    if (index > start) {
        quickSort_recursive(data, start, index - 1);
    }
    if (index < end) {
        quickSort_recursive(data, index + 1, end);
    }
}

/**
 *
 * @param data
 * @param length
 */
void quickSort(int data[], int length) {
    quickSort_recursive(data, 0, length - 1);
}

int main() {
    int data[] = {2, 4, 1, 2, 7, 3, 9, 7, 0, 5};
    quickSort(data, 10);
    for (int i = 0; i < 10; ++i) {
        printf("%d", data[i]);
    }
    return 0;
}