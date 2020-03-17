/*
 * 数塔问题，DP
 * http://acm.hdu.edu.cn/showproblem.php?pid=2084
 *
 * input:
 * 1
 * 5
 * 7
 * 3 8
 * 8 1 0
 * 2 7 4 4
 * 4 5 2 6 5
 * output:
 * 30
 */

#include <cstdio>
#include <iostream>

using namespace std;

int tower[110][110];

int main() {
    int c, n;
    while (scanf("%d", &c) != EOF) {
        for (int i = 0; i < c; ++i) {
            scanf("%d", &n);
            for (int j = 1; j <= n; ++j) {
                for (int k = 1; k <= j; ++k) {
                    scanf("%d", &tower[j][k]);
                }
            }
            for (int l = n - 1; l > 0; --l) {
                for (int j = 1; j <= l; ++j) {
                    tower[l][j] += max(tower[l + 1][j], tower[l + 1][j + 1]);
                }
            }
            printf("%d\n", tower[1][1]);
        }
    }

    return 0;
}