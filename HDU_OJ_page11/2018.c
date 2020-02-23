#include <stdio.h>

// 有一头母牛，它每年年初生一头小母牛。每头小母牛从第四个年头开始，每年年初也生一头小母牛。请编程实现在第n年的时候，共有多少头母牛？
// http://acm.hdu.edu.cn/showproblem.php?pid=2018

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        if (n==0) { break;}

        int n1 = 0, n2 = 0, n3 = 0;
        int n4 = 1; // 最开始只有一头可生育母牛
        int tmp;
        while (--n) {
            n4 += n3; // 长大一岁
            tmp = n4; // 生小牛
            n3 = n2; // 长大一岁
            n2 = n1; // 长大一岁
            n1 = tmp; // 重置小牛数量
        }
        printf("%d\n", n1 + n2 + n3 + n4);
    }
}