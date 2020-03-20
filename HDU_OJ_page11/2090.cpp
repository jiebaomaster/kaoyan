/*
 * 简单求和计算
 * http://acm.hdu.edu.cn/showproblem.php?pid=2090
 */

#include <cstdio>

int main() {
    char name[1010];
    double num, price;
    double sum = 0;
    while (scanf("%s%lf%lf", name, &num, &price) != EOF) {
        sum += price * num;
    }
    printf("%.1lf\n", sum);
    return 0;
}