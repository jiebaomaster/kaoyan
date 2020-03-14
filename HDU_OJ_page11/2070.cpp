/*
 * fibonacci
 * http://acm.hdu.edu.cn/showproblem.php?pid=2070
 */

#include <cstdio>

long long fibo[55];

int main() {
    fibo[0] = 0;
    fibo[1] = 1;
    for (int i = 2; i <= 50; ++i) {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }
    int n;
    while (scanf("%d", &n) != EOF) {
        if (n == -1) { break; }
        printf("%lld\n", fibo[n]);
    }
}