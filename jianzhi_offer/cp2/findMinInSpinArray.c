#include <stdio.h>

/**
 * P82 在一个旋转数组中找出最小数，如{3, 4, 5, 1, 2}中 1 是最小数
 * 在一个部分有序的数组中查找，可以考虑二分法
 * @param data
 * @param length
 * @return 最小数的索引
 */
int findMinInSpinArray(int data[], int length) {
    int start = 0, end = length - 1;
    int mid = start; // 第一个元素小于最后一个元素时，数组正序，直接返回第一个元素
    while (data[start] >= data[end]) {
        if (end - start == 1) {
            mid = end;
            break;
        }
        mid = start + (end - start) / 2;
        if (data[start] == data[mid] && data[end] == data[mid]) { // 三个元素都相等，只能顺序比较:10111/11101
            for (int i = start + 1; i <= end; ++i) {
                if (data[i] < data[start]) {
                    return i;
                }
            }

        }
        if (data[start] <= data[mid]) { // 当第一个元素小于等于中间元素时，说明左边正序，则部分旋转数组在右边
            start = mid;
        } else {
            end = mid;
        }
    }
    return mid;
}

int main() {
    int test1[] = {3, 4, 5, 1, 2};
    int test2[] = {1, 0, 1, 1, 1};
    int test3[] = {1, 1, 1, 0, 1};
    int test4[] = {1, 2, 3, 4, 5};

    printf("%d %d %d %d",
           findMinInSpinArray(test1, 5),
           findMinInSpinArray(test2, 5),
           findMinInSpinArray(test3, 5),
           findMinInSpinArray(test4, 5));
    return 0;
}