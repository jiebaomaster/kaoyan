/*
 * 一个整数，只知道前几位，不知道末二位，被另一个整数除尽了，那么该数的末二位该是什么呢？
 * http://acm.hdu.edu.cn/showproblem.php?pid=2099
 *
 * input:
 * 200 40
 * 1992 95
 * output:
 * 00 40 80
 * 15
 */

#include <cstdio>

int main() {
    int a, b;
    while (scanf("%d%d", &a, &b) != EOF) {
        if (a + b == 0) { break; }
        int f = 0;
        for (int i = 0; i < 100; ++i) {
            int tmp = a * 100 + i;
            if (tmp % b == 0) {
                if (f++) { printf(" "); }
                printf("%02d", i);
            }
        }
        printf("\n");
    }
}