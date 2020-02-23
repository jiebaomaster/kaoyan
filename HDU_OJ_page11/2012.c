#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// 对于表达式 n^2+n+41，当 n 在（x,y）范围内取整数值时（包括 x,y）(-39<=x<y<=50)，判定该表达式的值是否都为素数。
// http://acm.hdu.edu.cn/showproblem.php?pid=2012

/**
 * 判断一个数是否是素数
 * @param number
 * @return
 */
bool isPrimeNumber(int number) {
    for (int i = 2; i <= sqrt(number); ++i) { // 判断素数时，因子最大为其平方根
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int x, y;
    int tmp;
    while (scanf("%d %d", &x, &y) != EOF) {
        if (x == 0 && y == 0) break;
        if (x > y) tmp = y, y = x, x = tmp;

        bool isAllPrimeNumber = true;
        for (int i = x; i <= y; ++i) {
            if (!isPrimeNumber(i * i + i + 41)) { // 遇到第一个非素数时可判断不全是素数
                isAllPrimeNumber = false;
                break;
            }
        }
        if (isAllPrimeNumber) {
            printf("OK\n");
        } else {
            printf("Sorry\n");
        }
    }
}