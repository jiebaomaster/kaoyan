/*
 * 又到了选课的时间了，xhd看着选课表发呆，为了想让下一学期好过点，
 * 他想知道学n个学分共有多少组合。你来帮帮他吧。（xhd认为一样学分的课没区别）
 * http://acm.hdu.edu.cn/showproblem.php?pid=2079
 *
 * input:
 * 2
 * 2 2
 * 1 2
 * 2 1
 * 40 8
 * 1 1
 * 2 2
 * 3 2
 * 4 2
 * 5 8
 * 6 9
 * 7 6
 * 8 8
 * output:
 * 2
 * 445
 */

#include <cstdio>

using namespace std;
int t, n, k;
int num[9];
int count;

/**
 * dfs遍历所有的组合方式，找出其中符合要求的
 * @param index
 * @param curSum
 */
void dfs(int index, int curSum) {
    if (curSum > n || index == 9 || num[index] == -1) { return; }
    if (curSum == n) {
        count++;
        return;
    }
    num[index]--;
    dfs(index, curSum + index);
    num[index]++;
    dfs(index + 1, curSum);
}

int main() {
    while (scanf("%d", &t) != EOF) {
        for (int i = 0; i < t; ++i) {
            scanf("%d%d", &n, &k);
            int tmp;
            for (int j = 1; j <= k; ++j) {
                scanf("%d %d", &tmp, &num[j]);
            }
            count = 0;
            dfs(1, 0);
            printf("%d\n", count);
        }
    }

    return 0;
}