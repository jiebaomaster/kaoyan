/*
 * P304 假设把某股票的价格按照时间顺序存储在数组中，求买卖该股票一次可能获得的最大利润。
 * 显然，只有在买入股票之后才能卖出，故本题不是简单的求最大值最小值问题。
 * 当考虑整体难以解决时，可以先考虑局部，定义 diff[i] 表示卖出价为第i个数字时，可获得的最大利润，显然最后答案为 max{diff[i]}
 * 而当卖出价固定时，买入价格越低利润越大，故只要记录前 i-1 个数字中的最小值即可
 */

#include <stdio.h>

/**
 *
 * @param data
 * @param length
 * @return
 */
int maxDiff(int data[], int length) {
    if (data == NULL || length <= 1) { return -1; }

    int min = data[0];
    int maxDiff = data[1] - min;
    for (int i = 1; i < length; ++i) {
        int tmp = data[i] - min;
        if (maxDiff < tmp) { // 更新最大利润
            maxDiff = tmp;
        }
        if (data[i] < min) { // 更新最小值
            min = data[i];
        }
    }
    return maxDiff;
}

int main() {
    int testData[] = {9, 11, 8, 5, 7, 12, 16, 14};
    printf("%d", maxDiff(testData, 8));

    return 0;
}