/*
 * 判断正整数A是否能被正整数B整除
 * http://acm.hdu.edu.cn/showproblem.php?pid=2075
 */

#include <cstdio>

int main() {
    int n, a, b;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &a, &b);
            printf("%s\n", a % b == 0 ? "YES" : "NO");
        }
    }
    return 0;
}