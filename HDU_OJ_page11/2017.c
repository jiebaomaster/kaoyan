#include <stdio.h>
#include <stdlib.h>

// 对于给定的一个字符串，统计其中数字字符出现的次数。
// http://acm.hdu.edu.cn/showproblem.php?pid=2017

int main() {
    int n;
    while (scanf("%d%*c", &n) != EOF) {
        int *numbers = (int *) malloc(sizeof(int) * n);
        for (int i = 0; i < n; ++i) {
            int count = 0;
            char ch;
            while (1) {
                scanf("%c", &ch);
                if (ch >= '0' && ch <= '9') { count++; } // 匹配数字，累加
                if (ch == '\n' || ch == '\t') { // 匹配回车，结束本次计算
                    *(numbers + i) = count;
                    break;
                }
            }
        }
        for (int j = 0; j < n; ++j) {
            printf("%d\n", *(numbers + j));
        }
    }
    return 0;
}