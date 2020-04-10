/*
 * P267 一个单调递增的数组，其中任意元素不想等，寻找任意一个数值与索引相等的元素
 */

#include <cstdio>

/**
 * 寻找任意一个数值与索引相等的元素
 * @param data
 * @param length
 * @return
 */
int find(int data[], int length) {
    int start = 0, end = length - 1;
    int mid;
    while (start <= end) {
        mid = (start + end) / 2;
        if (data[mid] == mid) {
            return mid;
        } else if (data[mid] < mid) { // 若下标大于数值，则其左边的数的下标都大于数值
            start = mid + 1;
        } else { // 若下标小于数值，则其右边的数的下标都小于数值
            end = mid - 1;
        }
    }
    return -1;
}

int main() {
    int testData[] = {-3, -1, 1, 3, 5};
    printf("%d", find(testData, 5));

    return -1;
}