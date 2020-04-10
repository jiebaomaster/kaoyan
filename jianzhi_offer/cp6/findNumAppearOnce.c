/*
 * P278 一个整型数组除了两个数字之外，其他数字都出现了三次。找出这两个只出现了一次的数字。
 * 由于其他的数字出现了奇数次，则不能直接应用异或运算规律。
 * 如果一个数出现了三次，则其二进制表示的每一位也出现了三次。如果把所有出现三次的数字的二进制表示的每一位都分别相加，那么每一位都可以被 3 整除。
 * 把数组中所有数字的二进制表示的每一位加起来，如果其中一位的和能被 3 整除，则那个只出现一次的数字的二进制表示中对应的那一位就是 0，否则为 1。
 */

#include <stdio.h>

int findNumAppearOnce(int data[], int length) {
    if (data == NULL || length <= 0) { return -1; }

    int sumPerBit[32] = {0}; // 每一位的和，从低位到高位
    for (int i = 0; i < length; ++i) {
        int tmp = data[i];
        for (int j = 0; j < 32; ++j) { // 将一个数字转化为二进制，记录每一位的值
            if (tmp & 1) {
                sumPerBit[j]++;
            }
            tmp = tmp >> 1;
            if (!tmp) {
                break;
            }
        }
    }
    int result = 0;
    for (int i = 31; i >= 0; --i) { // 从高位到低位拼装最终结果
        result = result << 1;
        result += sumPerBit[i] % 3;
    }
    return result;
}

int main() {
    int testData[] = {1, 2, 2, 2, 3, 3, 3, 4, 4, 4};
    printf("%d", findNumAppearOnce(testData, 10));

    return 0;
}