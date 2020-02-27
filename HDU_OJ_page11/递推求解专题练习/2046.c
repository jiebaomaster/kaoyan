#include <stdio.h>

// 骨牌铺方格
// fibo
// http://acm.hdu.edu.cn/showproblem.php?pid=2046

int main() {
    int n;
    while (scanf("%d",&n)!=EOF) {
        long long f1 = 1;
        long long f2 = 1;
        long long tmp;
        while (--n) {
            tmp = f2;
            f2 = f1+f2;
            f1 = tmp;
        }
        printf("%lld\n",f2);
    }
}