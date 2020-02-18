#include <stdio.h>
#include <math.h>

/**
 * 计算 n 位整数的个数，如 3 位整数 100～999 共有 900 个
 * @param n
 * @return
 */
int countOfIntegers(int n) {
    if (n == 1) {
        return 10;
    }
    return 9 * (int) pow(10, n - 1);
}

/**
 * 计算最小的 n 位数
 * @param n
 * @return
 */
int minOfIntegers(int n) {
    if (n == 1) { return 0; }
    return (int) pow(10, n - 1);
}

/**
 * P225 在数字序列 "0123456789101112131415161718192021..." 中，求任意第 n 位对应的数字
 * @param index
 * @return
 */
int digitAtIndex(int index) {
    if (index < 0) { return -1; }

    int n = 1; // index 索引字符所在数字的位数
    while (1) { // index 依次减去 n 位数占据的位置数
        int numbers = countOfIntegers(n);
        if (index < numbers * n) { // n 位数字在序列中实际占据位置数为：n位数个数 * 位数n
            break;
        }
        index -= numbers * n;
        n++;
    }

    /**
     * 例：1001 - 10 - 90 * 2 = 811 < 900，即 1001 所在数字是一个 3 位数
     *    而 811 = 270 * 3 + 1, 即 811 是从 100 开始的第 270 个数字的中间一位，offset = 1, tmp = 270 + 100 = 370
     */
    int offset = index % n; // 字符所在数字中的偏移，0 代表所在数字的第一个字符
    int indexNumber = minOfIntegers(n) + index / n; // index 索引字符所在的数字
    for (int j = n - offset - 1; j > 0; --j) {
        indexNumber /= 10;
    }
    return indexNumber % 10;
}

int main() {
    printf("%d", digitAtIndex(1001));
    return 0;
}