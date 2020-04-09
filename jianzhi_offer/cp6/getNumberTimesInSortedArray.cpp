/*
 * P263
 * 统计一个数字在排序数组中出现的次数
 * 一般方法是遍历寻找目标数字，再统计次数，时间复杂度 O(n)
 * 上述方法在遍历时可用二分法，找到目标数字后向两边遍历统计，时间复杂度仍是 O(n)
 * 前面的算法中，时间主要消耗在确定重复出现的数字的第一个和最后一个位置上，
 * 故可用二分法再次优化，即用二分法分别找到第一个位置和最后一个位置，时间复杂度为 O(logn)
 */

#include <cstdio>

/**
 * 寻找第一次出现的位置
 * @param data
 * @param length
 * @param target
 * @return
 */
int getFirstPosition(int data[], int length, int target) {
    int start = 0, end = length - 1;
    int mid;
    while (start <= end) {
        mid = (start + end) / 2;
        if (data[mid] == target) {
            if (mid == 0 || data[mid - 1] != target) { // 当前位置为0或者前一个位置不等于目标值时，找到第一次出现的位置
                return mid;
            } else { // 前一位的值等于目标值，则还要继续向前寻找
                end = mid - 1;
            }
        } else if (data[mid] > target) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return -1;
}

/**
 * 寻找最后一次出现的位置
 * @param data
 * @param length
 * @param target
 * @return
 */
int getLastPosition(int data[], int length, int target) {
    int start = 0, end = length - 1;
    int mid;
    while (start <= end) {
        mid = (start + end) / 2;
        if (data[mid] == target) {
            if (mid == length - 1 || data[mid + 1] != target) { // 当前位置为最后一位或者后一个位置不等于目标值时，找到最后一次出现的位置
                return mid;
            } else { // 后一位的值等于目标值，则还要继续向后寻找
                start = mid + 1;
            }
        } else if (data[mid] > target) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return -1;
}

/**
 * 统计出现的次数
 * @param data
 * @param length
 * @param target
 * @return
 */
int getNumberTimesInSortedArray(int data[], int length, int target) {
    if (data == NULL || length <= 0) { return -1; }

    int first = getFirstPosition(data, length, target);
    if (first == -1) { // 不存在目标元素
        return 0;
    } else {
        return getLastPosition(data, length, target) - first + 1;
    }
}

int main() {
    int testData[] = {1, 1, 2, 3, 3, 3, 3, 4, 5};
    printf("%d", getNumberTimesInSortedArray(testData, 9, 1));

    return 0;
}