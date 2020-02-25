#include <stdio.h>
#include <stdbool.h>

/**
 * 二分查找
 * @param data
 * @param target
 * @param targetIndex
 * @return
 */
bool binarySearch(int data[], int length, int target, int *targetIndex) {
    int start = 0, end = length - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (data[mid] == target) {
            *targetIndex = mid;
            return true;
        } else if (data[mid] < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return false;
}

int main() {
    int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int index = -1;
    int target = 32;
    bool result = binarySearch(data, 9, target, &index);

    printf("%d %d", result, index);

    return 0;
}