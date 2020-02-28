#include <stdio.h>

// 打印矩形
// http://acm.hdu.edu.cn/showproblem.php?pid=2052

/**
 * 打印一行
 * @param str
 * @param length
 */
void printLine(char str[], int length) {
    for (int i = 0; i < length; ++i) {
        printf("%c", str[i]);
    }
    printf("\n");
}

int main() {
    int n, m;
    char n_edge[80] = {'+'};
    char m_edge[80] = {'|'};
    while (scanf("%d %d", &n, &m) != EOF) {
        int i;
        for (i = 1; i <= n; ++i) { // 初始化每一行需要打印的内容
            n_edge[i] = '-';
            m_edge[i] = ' ';
        }
        n_edge[i] = '+';
        m_edge[i] = '|';
        printLine(n_edge, n + 2);
        for (int j = 0; j < m; ++j) {
            printLine(m_edge, n + 2);
        }
        printLine(n_edge, n + 2);
        printf("\n");
    }
}