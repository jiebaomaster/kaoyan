#include <stdio.h>

/**
 * P42 数组中连续子数组的最大和，例：数组 {1,-2,3,10,-4,7,2,-5} 中子数组 {3,10,-4,7,2} 的和最大
 * 动态规划：令以下标 i 为最后元素的子数组最大和为 f(i)，则
 *          f(i) = { data[i]          ,f(i-1)<=0 或 i=0
 *                 { f(i-1) + data[i] ,f(i-1)>0 且 i!=0
 * 可知，题目所求即 max{f(i)}，其中0 <= i < length
 * 
 * @param data
 * @param length
 * @return
 */
int maxSubArraySum(const int data[], int length) {
    int curSum = data[0];
    int maxSum = curSum;
    for (int i = 1; i < length; ++i) {
        if (curSum < 0) {
            curSum = data[i];
        } else {
            curSum += data[i];
        }
        if (curSum > maxSum) {
            maxSum = curSum;
        }
    }
    return maxSum;
}

int main() {
    int data[] = {1, -2, 3, 10, -4, 7, 2, -5};
    printf("%d", maxSubArraySum(data, 8));

    return 0;
}