#include <stdio.h>

// P41 长度为n+1的数组里，所有数组元素属于 1～n，故必有至少一个重复，找出任意一个
// 不能修改数组的内容，二分查找思想

/**
 * 计算长度为 length 的数组 numbers 中元素值在 min 和 max 之间的元素个数
 * @param numbers
 * @param length
 * @param min
 * @param max
 * @return
 */
int countRanger(int numbers[], int length, int min, int max) {
    if (numbers == NULL || length <= 0) {
        return -1;
    }

    int count = 0;
    for (int i = 1; i < length; ++i) {
        if (numbers[i] >= min && numbers[i] <= max) {
            count++;
        }
    }
    return count;
}

/**
 * 查找数组中重复的一个数
 * @param numbers
 * @param length
 * @return
 */
int getDuplicate(int numbers[], int length) {
    int start = 1;
    int end = length - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;
        int count = countRanger(numbers, length, start, mid);

        // 二分法，数组中值介于 start 和 mid 之间的数的个数大于 end-start+1，则重复的数在 start 和 mid 之间
        if (count > mid - start + 1) {
            if (start == end) {
                return start;
            } else {
                end = mid;
            }
        } else {
            start = mid + 1;
        }
    }
}

int main() {
    int test[] = {1, 2, 4, 3, 5, 5};
    int duplication = getDuplicate(test, 6);
    printf("%d", duplication);

    return 0;
}