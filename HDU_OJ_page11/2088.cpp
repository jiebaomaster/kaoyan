/*
 * 叠砖块
 * http://acm.hdu.edu.cn/showproblem.php?pid=2088
 *
 * input:
 * 6
 * 5 2 4 1 7 5
 * output:
 * 5
 */

#include <cstdio>

int main() {
    int n;
    int wall[55];
    int t = 0;
    while (scanf("%d", &n) != EOF) {
        if (n == 0) { break; }
        if (t++) { printf("\n"); }
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &wall[i]);
            sum += wall[i];
        }
        int average = sum / n; // 计算平均高度，即要叠成的目标高度
        int ans = 0;
        for (int j = 0; j < n; ++j) {
            if (wall[j] > average) {
                ans += wall[j] - average;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}