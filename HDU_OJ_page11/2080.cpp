/*
 * 在一个平面内有两个点，求两个点分别和原点的连线的夹角的大小。
 * a·b=(x1*x2+y1*y2)=|a||b|·cosθ，算出cos后再根据反三角函数算出角度，需要将弧度转换成角度
 * http://acm.hdu.edu.cn/showproblem.php?pid=2080
 */

#include <cstdio>
#include <cmath>

#define PI acos(-1.0)

int main() {
    int t;
    double x1, y1, x2, y2;
    while (scanf("%d", &t) != EOF) {
        for (int i = 0; i < t; ++i) {
            scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
            double a = sqrt(x1 * x1 + y1 * y1); // (x1,y1)点距离(0,0)点的距离
            double b = sqrt(x2 * x2 + y2 * y2);
            double cos = (x1 * x2 + y1 * y2) / (a * b);
            double ans = acos(cos) / PI * 180; // 反三角函数得出的是弧度
            printf("%.2lf\n", ans);
        }
    }
}