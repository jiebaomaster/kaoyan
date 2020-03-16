/*
 * 汉诺塔IV：不允许直接从最左(右)边移到最右(左)边(每次移动一定是移到中间杆或从中间移出)，也不允许大盘放到小盘的上面。
 * 只允许最大的盘子放在最上面，当然最后需要的结果是盘子从小到大排在最右边。
 * 解：因为最大的可以放在最上面, 所以就不能像 汉诺塔III那样把前 n-1 个盘全部从 1->3 了。可分为以下两步：
 *  1）只要把前 n-1 个盘从 1->2，然后把第 n 个盘 1->2->3，然后把前 n-1 个盘 2->3，这样就完成了。
 *  2）所以问题现在转换成 n 个盘移动一步需要多少次。我们先把前n-2 个盘 1->3，然后把第 n-1 个盘 1->2,
 *     再把前 n-2 个盘 3->2，这样就把前 n-1个盘 1->2 移动了一步。
 * http://acm.hdu.edu.cn/showproblem.php?pid=2077
 * http://www.cppblog.com/MiYu/archive/2010/08/06/122447.html
 *
 * input:
 * 2
 * 1
 * 10
 * output:
 * 2
 * 19684
 */

#include <cstdio>

const int maxn = 21;

int main() {
    int dp3[maxn]; // 表示按汉诺塔3的规则 1->3 所需步数
    int dp4[maxn]; // 表示相邻两柱移动所需步数
    dp3[0] = 0;
    for (int i = 1; i < maxn; ++i) {
        dp3[i] = 3 * dp3[i - 1] + 2;
    }
    dp4[0] = 0;
    for (int j = 1; j < maxn; ++j) {
        dp4[j] = dp4[j - 1] + dp3[j - 1] + 1;
    }
    int t, n;
    while (scanf("%d", &t) != EOF) {
        for (int i = 0; i < t; ++i) {
            scanf("%d", &n);
            printf("%d\n", 2 * dp4[n - 1] + 2);
        }
    }

    return 0;
}