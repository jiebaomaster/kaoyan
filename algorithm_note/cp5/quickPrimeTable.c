#include <stdio.h>
#include <stdbool.h>

// P162 埃氏筛选法快速计算素数表，计算 2～100 以内的所有素数，时间复杂度 O(n*loglogn)
// 从小到大到达某数 a 时，如果 a 没有被之前的步骤筛去，则 a 一定是素数。
// 因为若 a 不是素数，那么 a 一定有小于 a 的素因子，那么在 a 之前的步骤中一定会被筛去。
// 计算素数普通的方法是在 2～sqrt(n) 内判断有没有因子，时间复杂度为 O(n*sqrt(n))

const int max = 101;
int primeNumber[max]; // 存放素数的数组
bool isNotPrime[max] = {false}; // 某个数是否是素数，用来筛选

void findPrime() {
    int primeNumberIndex = 0;
    for (int i = 2; i < max; ++i) {
        if (!isNotPrime[i]) { // 在之前的步骤中未被筛去，则一定是素数
            primeNumber[primeNumberIndex++] = i;
            for (int j = i * 2; j < max; j += i) { // 所有 i 的倍数都不是素数
                isNotPrime[j] = true;
            }
        }
    }
    primeNumber[primeNumberIndex] = -1;
}

int main() {
    findPrime();
    for (int i = 0; primeNumber[i] != -1; ++i) {
        printf("%d ", primeNumber[i]);
    }
    return 0;
}