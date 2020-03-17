/*
 * 假设有x1个字母A， x2个字母B,..... x26个字母Z，同时假设字母A的价值为1，字母B的价值为2,..... 字母Z的价值为26。
 * 那么，对于给定的字母，可以找到多少价值<=50的单词呢？单词的价值就是组成一个单词的所有字母的价值之和，
 * 比如，单词ACM的价值是1+3+14=18，单词HDU的价值是8+4+21=33。(组成的单词与排列顺序无关，比如ACM与CMA认为是同一个单词）
 * http://acm.hdu.edu.cn/showproblem.php?pid=2082
 *
 * input:
 * 2
 * 1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
 * 9 2 6 2 10 2 2 5 6 1 0 2 7 0 2 2 7 5 10 6 10 2 10 6 1 9
 * output:
 * 7
 * 379297
 */

#include <cstdio>

int num[27];
long long countWord;

/**
 * dfs遍历所有选择方法
 * @param index
 * @param curSum
 */
void dfs(int index, int curSum) {
    if (index == 27 || curSum + index > 50 || num[index] < 0) { return; } // 注意第二个剪枝条件
    if (num[index] > 0) { // index号元素还可以选，则选择一次
        countWord++;
        num[index]--;
        dfs(index, curSum + index);
        num[index]++;
    }
    dfs(index + 1, curSum);
}

int main() {
    int t;
    while (scanf("%d", &t) != EOF) {
        for (int i = 0; i < t; ++i) {
            for (int j = 1; j < 27; ++j) {
                scanf("%d", &num[j]);
            }
            countWord = 0;
            dfs(1, 0);
            printf("%lld\n", countWord);
        }
    }
}
