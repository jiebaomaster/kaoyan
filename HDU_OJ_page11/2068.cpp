/*
 * 今年暑假杭电ACM集训队第一次组成女生队,其中有一队叫RPG,但做为集训队成员之一的野骆驼竟然不知道RPG三个人具体是谁谁。
 * RPG给他机会让他猜猜，第一次猜：R是公主，P是草儿，G是月野兔；第二次猜：R是草儿，P是月野兔，G是公主；第三次猜：R是草儿，P是公主，G是月野兔；......
 * 可怜的野骆驼第六次终于把RPG分清楚了。由于RPG的带动，做ACM的女生越来越多，我们的野骆驼想都知道她们，可现在有N多人，他要猜的次数可就多了，
 * 为了不为难野骆驼，女生们只要求他答对一半或以上就算过关，请问有多少组答案能使他顺利过关。
 * 即累加（选择小于一般的人数 * 这些人发生错排）
 * http://acm.hdu.edu.cn/showproblem.php?pid=2068
 */

#include <cstdio>

using namespace std;

const int maxn = 26;
long long f[maxn]; // i个人完全错排的种类数
long long C[maxn][maxn]; // 组合数 C(i,j)

/**
 * 递归计算组合数，防止直接计算导致溢出
 * C(i,j) 表示从 j 个数中选择 i 个数的方案数，可以转化为：
 *  1. 不选最后一个数，从前 j-1 个数中选 i 个数；
 *  2. 选择最后一个数，从前 j-1 个数中选 i-1 个数
 * 即 C(i,j)=C(i,j-1)+C(i-1,j-1)，递归边界为 C(i,i)=C(0,j)=1
 * @param i
 * @param j
 * @return
 */
long long calculateC(int i, int j) {
    if (i == 0 || i == j) { return 1; }
    if (C[i][j]) { return C[i][j]; }
    else {
        return calculateC(i, j - 1) + calculateC(i - 1, j - 1);
    }
}

int main() {
    // 计算错排
    f[0] = 1;
    f[1] = 0;
    for (int i = 2; i <= 25; ++i) {
        f[i] = (i - 1) * (f[i - 1] + f[i - 2]);
    }
    int n;
    while (scanf("%d", &n) != EOF) {
        if (n == 0) { break; }
        long long ans = 0;
        for (int i = 0; i <= n / 2; ++i) {
            ans += calculateC(i, n) * f[i];
        }
        printf("%lld\n", ans);
    }
    return 0;
}