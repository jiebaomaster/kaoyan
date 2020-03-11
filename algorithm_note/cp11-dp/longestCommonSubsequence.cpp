#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

/*
 * P434 给定两个字符串（或数字序列）A 和 B，求一个字符串，使得这个字符串是 A 和 B 的最长公共部分（子序列可以不连续），求最长公共子序列长度。
 * 令 dp[i][j] 表示字符串 A 的 i 号位和字符串 B 的 j 号位之前的最长公共子序列长度（下标从 1 开始），
 * 则有 dp[i][j] = { dp[i-1][j-1] + 1,           A[i] == B[j]
 *                { max{dp[i-1][j], dp[i][j-1]}, A[i] != B[j]
 * 边界：dp[i][0] = dp[0][j] = 0
 */

const int maxn = 100;
int dp[maxn][maxn];

int main() {
    string a, b;
    cin >> a >> b;
    int a_length = a.size();
    int b_length = b.size();
    for (int i = 0; i <= a_length; ++i) {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= b_length; ++j) {
        dp[0][j] = 0;
    }

    for (int i = 1; i <= a_length; ++i) {
        for (int j = 1; j <= b_length; ++j) {
            if (a[i] == b[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[a_length][b_length];

    return 0;
}