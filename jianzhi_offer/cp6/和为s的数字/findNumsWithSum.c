/*
 * P280 又一个递增排序的数，在数组中查找两个数，使得它们的和正好等于指定的值
 * 数组已经排序，一般是给了一个方向
 */

#include <stdio.h>
#include <stdbool.h>

/**
 * 双指针法，在数组中查找两个数，使得它们的和正好等于指定的值
 * @param data
 * @param length
 * @param sum
 * @param num1
 * @param num2
 * @return
 */
bool findNumsWithSum(int data[], int length, int sum, int *num1, int *num2) {
    if (data == NULL || length <= 0) { return false; }

    int left = 0, right = length - 1; // 双指针法，分别指向头尾
    while (left < right) {
        int tmp = data[left] + data[right];
        if (tmp == sum) {
            *num1 = data[left];
            *num2 = data[right];
            return true;
        } else if (tmp > sum) { // 临时和大于指定值，需要缩小和，右指针向前
            right--;
        } else { // 临时和小于指定值，需要扩大和，左指针向后
            left++;
        }
    }
    return false;
}

int main() {
    int testData[] = {1, 2, 4, 7, 11, 15};
    int num1, num2;
    bool flag = findNumsWithSum(testData, 6, 15, &num1, &num2);
    printf("%d %d %d", flag, num1, num2);

    return 0;
}