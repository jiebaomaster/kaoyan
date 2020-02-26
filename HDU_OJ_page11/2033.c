#include <stdio.h>

// 这个题目的A和B不是简单的整数，而是两个时间，A和B 都是由3个整数组成，分别表示时分秒，比如，假设A为34 45 56，就表示A所表示的时间是34小时 45分钟 56秒。
// 对于每个测试实例，输出A+B，每个输出结果也是由时分秒3部分组成，同时也要满足时间的规则（即：分和秒的取值范围在0~59），每个输出占一行，并且所有的部分都可以用32位整数表示
// http://acm.hdu.edu.cn/showproblem.php?pid=2033

int main() {
    int n;
    int h1, m1, s1;
    int h2, m2, s2;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i) {
            scanf("%d %d %d %d %d %d", &h1, &m1, &s1, &h2, &m2, &s2);
            h1 += h2;
            m1 += m2;
            s1 += s2;
            if (s1 >= 60) {
                s1 -= 60;
                m1++;
            }
            if (m1 >= 60) {
                m1 -= 60;
                h1++;
            }
            printf("%d %d %d\n", h1, m1, s1);
        }
    }
}