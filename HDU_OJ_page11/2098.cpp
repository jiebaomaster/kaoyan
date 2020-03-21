/*
 * 把一个偶数拆成两个不同素数的和，求有几种拆法
 * http://acm.hdu.edu.cn/showproblem.php?pid=2098
 *
 * input:
 * 30
 * 26
 * output:
 * 3
 * 2
 */

#include <cstdio>
#include <cstring>

const int maxn = 10010;
bool isNotPrime[maxn] = {false}; // 记录不是素数的数

int main() {
    int n;
    memset(isNotPrime, false, sizeof(isNotPrime));
    // 筛选法打表计算素数
    isNotPrime[1] = true;
    for (int j = 2; j < maxn; ++j) {
        if (!isNotPrime[j]) {
            for (int i = j * 2; i < maxn; i += j) { // 一个素数的所有倍数都不是素数
                isNotPrime[i] = true;
            }
        }
    }
    while (scanf("%d", &n) != EOF) {
        if (n == 0) { break; }
        int count = 0;
        for (int i = 3; i < n / 2; ++i) {
            if (!isNotPrime[i] && !isNotPrime[n - i]) { count++; }
        }
        printf("%d\n", count);
    }
    return 0;
}