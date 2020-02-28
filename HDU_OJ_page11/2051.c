#include <stdio.h>

// 十进制转2进制
// http://acm.hdu.edu.cn/showproblem.php?pid=2051

int main() {
    int n;
    int number[20];
    while (scanf("%d", &n) != EOF) {
        int index = 0;
        while (n) {
            number[index++] = n % 2;
            n /= 2;
        }
        for (int i = index-1; i >=0; --i) {
            printf("%d", number[i]);
        }
        printf("\n");
    }
}
