#include <stdio.h>

// 根据输入的半径值，计算球的体积。
// http://acm.hdu.edu.cn/showproblem.php?pid=2002

#define PI 3.1415927

int main() {
    double r;
    while (scanf("%lf%*c", &r) != EOF) {
        // 不能直接写成 4/3*PI*r*r*r。因为除号“/”当除数和被除数都是整数的时候，得出来的结果是整数
        printf("%.3lf\n", PI * r * r * r * 4 / 3);
    }
}