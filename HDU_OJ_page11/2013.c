#include <stdio.h>

// 第一天悟空吃掉桃子总数一半多一个，第二天又将剩下的桃子吃掉一半多一个，以后每天吃掉前一天剩下的一半多一个，
// 到第 n 天准备吃的时候只剩下一个桃子。计算第一天开始吃的时候桃子一共有多少个
// http://acm.hdu.edu.cn/showproblem.php?pid=2013

int main() {
    int n;
    int sum;
    while (scanf("%d", &n) != EOF) {
        sum = 1;
        for (int i = 1; i < n; ++i) {
            sum = (sum + 1) * 2;
        }
        printf("%d\n", sum);
    }

    return 0;
}
