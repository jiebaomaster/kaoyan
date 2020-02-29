#include <stdio.h>

// 十六进制加法，十六进制数小于15位，换算成2进制，即小于60位，可用长整型
// %d  从键盘输入十进制整数
// %o  从键盘输入八进制整数
// %x  从键盘输入十六进制整数
// %c  从键盘输入一个字符
// %s  从键盘输入一个字符串
// %f  从键盘输入一个实数
// %e  与%f的作用相同
// http://acm.hdu.edu.cn/showproblem.php?pid=2057

int main() {
    long long x, y;
    while (scanf("%llx %llx", &x, &y) != EOF) {
        long long result = x + y;
        if (result < 0) {
            result = -result; // 输出16进制的负数不会在其前面加负号，而是变成2进制补码；因此在前面输出负号而原来的负数变成正数
            printf("-%llX\n", result);
        } else {
            printf("%llX\n", result);
        }
    }
}