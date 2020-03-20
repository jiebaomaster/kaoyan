/*
 * 输出空心三角形
 * http://acm.hdu.edu.cn/showproblem.php?pid=2091
 *
 * input:
 * X 2
 * A 7
 * output:
 *  X
 * XXX
 *
 *        A
 *       A A
 *      A   A
 *     A     A
 *    A       A
 *   A         A
 *  AAAAAAAAAAAAA
 */

#include <cstdio>

int main() {
    char x;
    int n;
    int flag=0;
    while (scanf("%c", &x) != EOF) {
        if (x == '@') { break; }
        if (flag++) {printf("\n");}
        scanf("%d%*c", &n);
        for (int i = 0; i < n - 1; ++i) { // 输出前 n-1 行
            for (int j = 1; j <= n + i; ++j) {
                if (j == n - i && i != 0) { // 第一行只需输出一个符号
                    printf("%c", x);
                } else if (j == n + i) {
                    printf("%c\n", x);
                } else {
                    printf(" ");
                }
            }
        }
        for (int k = 0; k < 2 * n - 1; ++k) { // 最后一行
            printf("%c", x);
        }
        printf("\n");
    }

    return 0;
}