/*
 * 把一个个大小差一圈的筐叠上去，使得从上往下看时，边筐花色交错
 * 输出叠在一起的筐图案，中心花色与外筐花色字符从内层起交错相叠，多筐相叠时，最外筐的角总是被打磨掉。叠筐与叠筐之间应有一行间隔。
 * http://acm.hdu.edu.cn/showproblem.php?pid=2074
 *
 * input:
 * 11 B A
 * 5 @ W
 * output:
 *  AAAAAAAAA
 * ABBBBBBBBBA
 * ABAAAAAAABA
 * ABABBBBBABA
 * ABABAAABABA
 * ABABABABABA
 * ABABAAABABA
 * ABABBBBBABA
 * ABAAAAAAABA
 * ABBBBBBBBBA
 *  AAAAAAAAA
 *
 *  @@@
 * @WWW@
 * @W@W@
 * @WWW@
 *  @@@
 */

#include <cstdio>

using namespace std;

char matrix[90][90];

int main() {
    int n;
    char ch[2];
    bool isNotFirstInput = false;
    while (scanf("%d %c %c%*c", &n, &ch[0], &ch[1]) != EOF) {
        int flag = ((n - 1) / 2) % 2;
        for (int i = 0; i <= n / 2; ++i) { // 从外圈到内圈填上花色
            char border = ch[flag];
            for (int j = i; j < n - i; ++j) { // 上下
                matrix[i][j] = border;
                matrix[n - i - 1][j] = border;
            }
            for (int j = i + 1; j < n - i - 1; ++j) { // 左右
                matrix[j][i] = border;
                matrix[j][n - i - 1] = border;
            }
            flag = !flag; // 交换填充花色
        }
        if (n > 1) { // 磨去四个角
            matrix[0][0] = matrix[0][n - 1] = matrix[n - 1][0] = matrix[n - 1][n - 1] = ' ';
        }
        if (isNotFirstInput) { printf("\n"); } // 除第一次外输入一行就换行，再输出，我一直是输出后再换行
        for (int i = 0; i < n; ++i) { // 依次输出
            for (int j = 0; j < n; ++j) {
                printf("%c", matrix[i][j]);
            }
            printf("\n");
        }
        isNotFirstInput = true;
    }
    return 0;
}

