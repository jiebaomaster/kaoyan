#include <stdio.h>
#include <math.h>

// 一行中有许多灯。一开始他们都关闭了。在这些灯上执行了一系列操作。在第i次操作中，数字为i的倍数的灯会更改条件（从开到关，从关到开）
// 求无穷次操作后，第 n 个台灯的状态
// 例如第5个台灯在第5次操作之后都不会再改变状态
// 分析可知，实际上看的是数字的因数个数，而且除了平方根之外，因数总是成对出现的，即若平方根是整数，则有奇数个因数
// http://acm.hdu.edu.cn/showproblem.php?pid=2053

#define eps 1e-5

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        if (sqrt(n) - floor(sqrt(n)) < eps) {
            printf("1\n");
        } else {
            printf("0\n");
        }
    }
}