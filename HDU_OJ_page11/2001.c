#include <stdio.h>
#include <math.h>

// 输入两点坐标（X1,Y1）,（X2,Y2）,计算并输出两点间的距离。
// http://acm.hdu.edu.cn/showproblem.php?pid=2001

int main() {
    float x1, y1, x2, y2;
    while (scanf("%f %f %f %f%*c", &x1, &y1, &x2, &y2) != EOF) {
        printf("%.2f\n", sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2))); // .2f 表示保留两位小数输出浮点数
    }

    return 0;
}