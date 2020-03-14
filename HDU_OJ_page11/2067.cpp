/*
 * 一个正方形棋盘，从起点(0，0)走到终点(n,n)的最短路径数是C(2n,n),如果不穿越对角线(但可接触对角线上的格点)，求这样的路径数有多少?
 * 这题的结果是卡塔兰数的2倍，因为有2种可能，只从对角线下方走和只从对角线上方走。
 * 卡塔兰数 catlan(n) = C_n = C(n,2n)*1/(n+1) = (2n)!/n!(n+1)!
 * 本题用公式计算的要注意计算组合数时容易溢出，可以利用下列递推式计算：
 * dp[i][j]表示只从对角线上方走时，从坐标(0,0)到(i,j)的路径数，所以有如下结果：
 * dp[0][0]=1
 * dp[i][j]=dp[i-1][j]+dp[i][j-1]，即每点的路径条数等于其左和上两点的路径条数之和
 * https://blog.csdn.net/qq_38238041/article/details/78452930
 * http://acm.hdu.edu.cn/showproblem.php?pid=2067
 */

#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 36;
long long dp[maxn][maxn]; // 到达对角线的左下角各个位置的路径条数

/*
 * input:
 * 1
 * 3
 * 12
 * output:
 * 1 1 2
 * 2 3 10
 * 3 12 416024
 */
int main() {
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 0; i < maxn; ++i) {
        for (int j = 0; j <= i; ++j) { // 遍历对角线左下角各点
            if (j > 0) { dp[i][j] += dp[i][j - 1]; }
            if (i > 0 && i != j) { dp[i][j] += dp[i - 1][j]; } // 注意不能跨过对角线，故对角线上的点路径条数等于其左边点的路径条数
        }
    }
    int n;
    int count = 1;
    while (scanf("%d", &n) != EOF) {
        if (n == -1) { break; }
        printf("%d %d %lld\n", count, n, dp[n][n] * 2);
        count++;
    }
}