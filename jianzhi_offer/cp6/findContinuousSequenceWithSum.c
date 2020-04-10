/*
 * P282 打印所有和为 s 的连续正整数序列（至少含有两个数）
 */

#include <stdio.h>

/**
 * 打印连续序列
 * @param start
 * @param end
 */
void printSequence(int start, int end) {
    for (int i = start; i <= end; ++i) {
        if (i != start) {
            printf("+");
        }
        printf("%d", i);
    }
    printf("\n");
}

/**
 * 求所有和为 s 的连续整数序列
 * 先 end 增大，序列向后扩散，然后 start 增大，序列向后缩小
 * @param sum
 */
void findContinuousSequenceWithSum(int sum) {
    int start = 1, end = 2;
    while (end <= (sum / 2 + 1)) { // 至少含有两个数，则末尾最大是 sum/2+1
        int tmpSum = (start + end) * (end - start + 1) / 2; // 计算临时和
        if (tmpSum == sum) {
            printSequence(start, end);
            // 找到一个符合要求的序列后移区间，继续寻找下一个序列
            end++;
            start++;
        } else if (tmpSum > sum) { // 临时和过大，需减少数字，即将左指针后移
            start++;
        } else { // 临时和过小，需增加数字，即将右指针后移
            end++;
        }
    }
}

int main() {
    findContinuousSequenceWithSum(18);
    printf("\n");
    findContinuousSequenceWithSum(15);

    return 0;
}
