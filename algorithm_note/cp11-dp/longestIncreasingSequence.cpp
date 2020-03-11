#include <iostream>

using namespace std;

/*
 * P432 在一个数字序列中，找到一个最长的子序列（可以不连续），使得这个子序列是不下降（非递减）的，求这个子序列长度
 * 令 dp[i] 为以 A[i] 结尾的最长不下降子序列长度，
 * 则有 dp[i] = { 1, i 之前的数都比 A[i] da
 *             { max{dp[j]+1}，A[j] 为 i 之前任意不大于 A[i] 的数
 * 本题中所求的子序列是不连续的，故有一个 max 操作，若子序列是连续的，则只需要比较 A[i] 和 A[i-1]
 */


int main() {
    int n;
    cin >> n;
    int *pData = new int[n];
    int *dp = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> *(pData + i);
    }

    int ans = -1;
    for (int i = 0; i < n; ++i) {
        *(dp + i) = 1; // 边界初始条件，即先假设每个元素自成一个子序列
        for (int j = 0; j < i; ++j) {
            if (*(pData + i) >= *(pData + j) // A[j] 为 i 之前任意不大于 A[i] 的数
                && *(dp + i) < *(dp + j) + 1) { // 寻找最大值
                *(dp + i) = *(dp + j) + 1;
            }
        }
        if (ans < *(dp + i)) {
            ans = *(dp + i);
        }
    }
    cout << ans;

    return 0;
}