#include <stdio.h>

// 输入一个十进制数N，将它转换成R进制数输出。
// http://acm.hdu.edu.cn/showproblem.php?pid=2031

int main() {
    int r;
    int number;
    char transformChar[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    while (scanf("%d %d", &number, &r) != EOF) {
        if (number < 0) { // 负数先输出符号
            printf("-");
            number = -number;
        }
        int numberStr[20];
        int index = 0;
        while (number != 0) { // 除 r 取余法化 10 进制数为 r 进制
            numberStr[index++] = number % r;
            number /= r;
        }
        while (--index >= 0) { // output
            if (numberStr[index] >= 10) {
                printf("%c", transformChar[numberStr[index] - 10]);
            } else {
                printf("%d", numberStr[index]);
            }
        }
        printf("\n");
    }
}