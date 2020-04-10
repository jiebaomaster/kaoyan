/*
 * P275 一个整型数组除了两个数字之外，其他数字都出现了两次。找出这两个只出现了一次的数字。
 * 先考虑数组中只有一个数字出现了一次，只要依次按位异或，最后得到的数就是只出现一次的数。
 * 问题就转化为如何将原数组分成两组，每组中含有一个只出现一次的数，其余数字成对出现。
 * 1. 先将全部数字依次按位异或，得到的结果是两个只出现一次的数字的异或，且这两个数字一定不想等，故异或结果一定不为 0，即异或结果的二进制表示中一定有一位 k 不为 0。
 * 2. 将所有的数字按第 k 位是否为 0 分为两组，由异或运算规律易知两个只出现一次的数必定被分在两组。又因为两个相同的数其第 k 位一定相同，故它们一定分在同一组。
 * 3. 每组进行依次按位异或，可得到两个只出现一次的数字。
 */

#include <stdio.h>
#include <stdbool.h>

/**
 * 找出数字以二进制表示时，第一个不为 0 的位
 * @param num
 * @return
 */
int findFirstBitIs1(int num) {
    int k = 0;
    while (num) {
        if (num & 1) {
            return k;
        }
        k++;
        num = num >> 1;
    }
}

/**
 * 判断数字的二进制表示的某位是否为 1
 * @param num
 * @param k
 * @return
 */
bool isBit1(int num, int k) {
    num = num >> k;// 用右移运算代替除法
    return (num & 1);
}

/**
 * 找出数组中两个只出现了一次的数字
 * @param data
 * @param length
 * @param num1
 * @param num2
 */
void findNumsAppearOnce(const int data[], int length, int *num1, int *num2) {
    if (data == NULL || length <= 2) { return; }

    int tmp = 0; // 初始化为 0，因为任何数与 0 按位异或得其本身
    for (int i = 0; i < length; ++i) {
        tmp ^= data[i];
    }
    int k = findFirstBitIs1(tmp); // 得到第一个不为 0 的位

    *num1 = *num2 = 0;
    for (int j = 0; j < length; ++j) {
        if (isBit1(data[j], k)) { // 按位分组
            *num1 ^= data[j];
        } else {
            *num2 ^= data[j];
        }
    }
}

int main() {
    int testData[] = {1, 2, 3, 3, 4, 4, 5, 5};
    int num1, num2;
    findNumsAppearOnce(testData, 8, &num1, &num2);
    printf("%d %d", num1, num2);

    return 0;
}