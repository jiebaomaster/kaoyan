#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// P167 分解质因数
// 结论：对一个正整数 N，若其存在 [2,N] 范围内的质因数，要么这些质因数全部小于 sqrt(N)，要么只存在一个大于 sqrt(N) 的质因数，
//      因为两个大于 sqrt(N) 的数相乘一定大于 N


const int max = 10001;
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

typedef struct factor { // 质因子
    int x; // 素因数
    int count; // 出现的次数
} factor;

int main() {
    int number = 97532468;
    int numberCopy = number;
    factor factors[10];
    for (int j = 0; j < 10; ++j) {
        factors[j].count = 0;
    }
    findPrime(); // 先打表计算素数
    int factorIndex = 0;
    for (int i = 0; primeNumber[i] < sqrt(numberCopy); ++i) {
        if (number % primeNumber[i] != 0) { continue; }
        factors[factorIndex].x = primeNumber[i];
        while (number % primeNumber[i] == 0) {
            factors[factorIndex].count += 1;
            number /= primeNumber[i];
        }
        factorIndex++;
    }
    if (number != 1) { // 存在一个大于 sqrt(N) 的质因数
        factors[factorIndex].x = number;
        factors[factorIndex++].count = 1;
    }
    printf("%d=", numberCopy);
    for (int k = 0; k < factorIndex; ++k) { // output，例如：97532468=2^2*11*17*101*1291
        printf("%d", factors[k].x);
        if (factors[k].count > 1) {
            printf("^%d", factors[k].count);
        }
        if (k != factorIndex - 1) {
            printf("*");
        }
    }
}