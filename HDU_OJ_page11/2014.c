#include <stdio.h>

// 青年歌手大奖赛中，评委会给参赛选手打分。选手得分规则为去掉一个最高分和一个最低分，然后计算平均得分，请编程输出某选手的得分。
// http://acm.hdu.edu.cn/showproblem.php?pid=2014

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int sum = 0;
        int max, min, score;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &score);
            if (i == 0) {
                max = score;
                min = score;
            }
            if (score > max) {
                max = score;
            }
            if (score < min) {
                min = score;
            }
            sum += score;
        }
        double par = (sum - max - min) * 1.0 / (n - 2);
        printf("%.2lf\n", par);
    }
    return 0;
}