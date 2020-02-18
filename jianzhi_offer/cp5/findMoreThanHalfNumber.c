#include <stdio.h>

/**
 * P205 寻找数组中出现次数超过一半的数
 * 最简单的方法使先排序，然后取 data[n/2]即中位数，此时时间复杂度为 O(nlogn)
 * 排序方法没有考虑本题数组的特点，这里用变量记录法，时间复杂度为 O(n)
 * @param data
 * @param length
 * @return
 */
int findMoreThanHalfNumber(const int data[], int length) {
    if (data == NULL || length <= 0) { return 0; }

    int number = data[0]; // 最后一次使 count 置一的数，即出现次数超过一半的数
    int count = 1; // number 出现的次数，动态变化，遍历过程中遇到不相等的，该值减一
    for (int i = 1; i < length; ++i) {
        if (data[i] == number) {
            count++;
        } else {
            count--;
            if (count == 0) {
                number = data[i];
                count = 1;
            }
        }
    }

    int numberCount = 0;
    for (int j = 0; j < length; ++j) {
        if (data[j] == number) {
            numberCount++;
        }
    }
    if (numberCount * 2 <= length) {
        printf("输入数据有误，不存在出现次数超过一半的数！");
        return 0;
    }
    return number;
}

int main() {
    int test1[] = {1, 2, 3, 2, 2, 2, 5, 4, 2, 1};
    printf("%d\n", findMoreThanHalfNumber(test1, 10));
    int test2[] = {1, 2, 3, 2, 2, 2, 5, 4, 2, 2};
    printf("%d", findMoreThanHalfNumber(test2, 10));
    return 0;
}