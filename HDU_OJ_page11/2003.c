#include <stdio.h>

// 求实数的绝对值。
// http://acm.hdu.edu.cn/showproblem.php?pid=2003

int main() {
    double number;
    while (scanf("%lf%*c", &number) != EOF) {
        if (number < 0) {
            number = -number;
        }
        printf("%.2lf\n", number);
    }
}