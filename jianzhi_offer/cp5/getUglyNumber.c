#include <stdio.h>
#include <stdlib.h>

/**
 * 从 indexN 开始，以 n 为因子寻找下一个刚好大于当前最大丑数的丑数
 * @param uglyNumbers
 * @param maxUglyNumber
 * @param n
 * @param indexN
 * @return
 */
int nextUgly(const int *uglyNumbers, int maxUglyNumber, int n, int *indexN) {
    int nextUglyNumber = 0;
    while (1) {
        nextUglyNumber = *(uglyNumbers + *indexN) * n;
        if (nextUglyNumber > maxUglyNumber) {
            break;
        }
        *indexN = (*indexN) + 1;
    }
    return nextUglyNumber;
}

/**
 * P240 只包含 2，3，5 因子的数称为丑数，求第 n 个丑数
 * 用一个数组从小到大保存已求得的丑数，则下一个丑数时数组中某个丑数乘以 2／3／5 得到的
 * 关键在于保证数组递增，即下一个丑数刚好是大于当前最大丑数的最小值
 * @param index
 * @return
 */
int getUglyNumber(int index) {
    if (index <= 0) { return -1; }

    int *uglyNumbers = (int *) malloc(sizeof(int) * index); // 保存已经计算出的丑数的数组
    *uglyNumbers = 1;
    int maxUglyNumber = 1; // 当前最大的丑数
    int index2 = 0; // 上次以因子 2 计算下一个丑数时，遍历到的位置，当前考虑因子 2 时必然在这个数之后
    int index3 = 0;
    int index5 = 0;
    int m2 = 0; // 以 2 为因子计算出的下一个丑数
    int m3 = 0;
    int m5 = 0;
    for (int i = 1; i < index; ++i) {
        // 计算2，3，5因子的下一个丑数
        m2 = nextUgly(uglyNumbers, maxUglyNumber, 2, &index2);
        m3 = nextUgly(uglyNumbers, maxUglyNumber, 3, &index3);
        m5 = nextUgly(uglyNumbers, maxUglyNumber, 5, &index5);
        // 三个之中的最小值作为下一个丑数，即保持丑数数组是递增的
        int tmpMin = m2 < m3 ? m2 : m3;
        maxUglyNumber = tmpMin < m5 ? tmpMin : m5;
        *(uglyNumbers + i) = maxUglyNumber;
    }
    int result = *(uglyNumbers + index - 1);
    free(uglyNumbers);
    return result;
}

int main() {
    printf("%d", getUglyNumber(20));

    return 0;
}