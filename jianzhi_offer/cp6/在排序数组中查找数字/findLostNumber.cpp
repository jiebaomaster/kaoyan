/*
 * P266 一个长度为 n-1 的递增数组中每个数字都是唯一的，并且每个数字都在 0～n-1 范围内，
 * 在 0～n-1 内的 n 个数字中有且只有一个数字不在该数组中，找出这个数字
 * 这个问题可以表示为寻找第一个下标与其值不相等的数
 * 寻找排序数组中第一个满足条件的数（之后的数都满足条件），可以用二分法解决
 */

#include <cstdio>

/**
 * 寻找第一个下标与其值不相等的数
 * @param data
 * @param length
 * @return
 */
int find(int data[], int length) {
    int start = 0, end = length - 1;
    int mid;
    while (start < end) { // start == end 时找到目标值
        mid = (start + end) / 2;
        if (data[mid] != mid) {
            end = mid;
        } else {
            start = mid + 1;
        }
    }
    return start;
}

int main() {
    int testData[] = {0, 1, 2, 3, 5, 6, 7};
    printf("%d", find(testData, 7));

    return -1;
}