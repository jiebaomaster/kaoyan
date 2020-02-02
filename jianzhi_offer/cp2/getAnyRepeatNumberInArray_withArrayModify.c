#include <stdio.h>
#include <stdbool.h>

// P39 长度为n的数组，数组元素值在 0～n-1 内
// 避免使用辅助空间，故要在数组本地作hash，即将数组中值为x的元素放在索引为x的单元下
/**
 *
 * @param numbers 待检查数组
 * @param length 数组长度，数组的数字在 0 ～ max_number-1 范围内
 * @param duplications 重复数字地址
 * @return 数组中是否存在重复的数字
 */
bool find_duplicate(int numbers[], int length, int *duplication) {
    // 参数检查
    if (numbers == NULL || length <= 0) { return false; }
    for (int i = 0; i < length; ++i) {
        if (numbers[i] < 0 || numbers[i] >= length) { return false; }
    }

    // 本地hash
    for (int j = 0; j < length; ++j) {
        while (numbers[j] != j) {
            if (numbers[numbers[j]] == numbers[j]) {
                *duplication = numbers[j];
                return true;
            } else {
                // swap
                int temp = numbers[j];
                numbers[j] = numbers[temp];
                numbers[temp] = temp;
            }
        }
    }
    return false;
}

int main() {
    int test1[] = {1, 0, 3, 9, 7, 6, 4};
    int duplication1 = -1;
    find_duplicate(test1, 7, &duplication1);
    printf("%d", duplication1);

    return 0;
}