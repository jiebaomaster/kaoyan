#include <stdio.h>

/**
 * P81 对一个年龄数组排序，要求时间复杂度为 O(n)
 * 待排序的数组元素值在一个范围内，即符合hash
 * @param data
 * @param length
 */
void agesSort(int data[], int length) {
    int maxAge = 99;
    int agesHash[maxAge + 1];
    for (int i = 0; i < maxAge + 1; ++i) {
        agesHash[i] = 0;
    }

    // 统计每一个年龄的人数各有多少
    for (int j = 0; j < length; ++j) {
        if (data[j] > maxAge) {
            printf("超出年龄限制!");
            exit(0);
        }
        agesHash[data[j]]++;
    }

    // 根据统计数据重新设置原数组的值
    int index = 0; // 原数组迭代索引
    for (int k = 0; k < maxAge + 1; ++k) {
        for (int i = 0; i < agesHash[k]; ++i) { // maxAge[k]=m,则 data 中有连续的 m 个 k
            data[index] = k;
            index++;
        }
    }
}

int main() {
    int data[] = {12, 14, 21, 22, 27, 23, 39, 67, 70, 25, 22, 12, 13};
    agesSort(data, 13);
    for (int i = 0; i < 13; ++i) {
        printf("%d ", data[i]);
    }
    return 0;
}