#include <cstdio>
#include <string.h>

// 首先,给每位新娘打扮得几乎一模一样,并盖上大大的红盖头随机坐成一排;
// 然后,让各位新郎寻找自己的新娘.每人只准找一个,并且不允许多人找一个.
// 最后,揭开盖头,如果找错了对象就要当众跪搓衣板...
// 假设一共有N对新婚夫妇,其中有M个新郎找错了新娘,求发生这种情况一共有多少种可能.
// 即从 N 个人中选出 M 个出来进行错排，即F(N,M) = CNM * f(M)，
// 其中由2048有：f(N)=(N-1)*[f(N-1)+f(N-2)]; CMN=N!/(M!*(N-M)!)。即CMN=N!/M!/(N-M)!
// http://acm.hdu.edu.cn/showproblem.php?pid=2049

int main() {
    long long f[21] = {0, 0, 1}; // 错排数
    long long base[21] = {1, 1, 2}; // 尖乘
    for (int i = 3; i < 21; ++i) {
        base[i] = base[i - 1] * i;
        f[i] = (i - 1) * (f[i - 1] + f[i - 2]);
    }
    long long F[21][21];
    for (int nn = 2; nn < 21; ++nn) {
        for (int mm = 2; mm <= nn; ++mm) {
            F[nn][mm] = base[nn] / base[mm] / base[nn - mm] * f[mm]; // 乘法最后做，防止越界
        }
    }

    int n, N, M;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i) {
            scanf("%d %d", &N, &M);
            printf("%lld\n", F[N][M]);
        }
    }
    return 0;
}

// 除了上面先选再全错排的方法，我们还可以直接从整个数列角度进行考虑
// f(N,M) 表示 N 长的数列有 M 个错排，分析可得加入一个数字后可以增加0～2个错排，则有：
// 1. 若前 N-1 个数字中已有 M 个错排，则直接加上第 N 个数字即可，即 F(N-1,M) 种可能
// 2. 若前 N-1 个数字中已有 M-1 个错排，则将第 N 个数字与前 N-1 中任意的一个错排交换，就可增加一个错排，即 (M-1)*F(N-1,M-1) 种可能
// 3. 若前 N-1 个数字中已有 M-2 个错排，则将第 N 个数字与前 N-1 中任意的一个正确排列交换，就可增加两个错排，即 [(N-1)-(M-2)]*F(N-1,M-2) 种可能
// 综上：F(N,M) = F(N-1,M) + (M-1)*F(N-1,M-1) + [(N-1)-(M-2)]*F(N-1,M-2)
//int main() {
//    long long an[21][21];
//    for (int k = 1; k < 21; ++k) { // 给数组赋初值
//        memset(an[k], 0, sizeof(long long) * 21); // 不同编译器对未初始化的数组赋初值不同，应该显式初始化为0
//        an[k][0] = 1;
//    }
//    an[2][2] = 1;
//    for (int i = 3; i < 21; ++i) {
//        for (int j = 2; j <= i; ++j) {
//            an[i][j] = an[i - 1][j] + (j - 1) * an[i - 1][j - 1] + (i - j + 1) * an[i - 1][j - 2];
//        }
//    }
//
//    int n, N, M;
//    while (scanf("%d", &n) != EOF) {
//        for (int i = 0; i < n; ++i) {
//            scanf("%d %d", &N, &M);
//            printf("%lld\n", an[N][M]);
//        }
//    }
//}