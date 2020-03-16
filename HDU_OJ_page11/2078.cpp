/*
 * xhd复习有个习惯，在复习完一门课后，他总是挑一门更简单的课进行复习，而他复习这门课的效率为两门课的难度差的平方,
 * 而复习第一门课的效率为100和这门课的难度差的平方。xhd这学期选了n门课，
 * 但是一晚上他最多只能复习m门课，请问他一晚上复习的最高效率值是多少？
 * 即找最简单的先复习
 * http://acm.hdu.edu.cn/showproblem.php?pid=2078
 *
 * input:
 * 2
 * 2 2
 * 52
 * 25
 * 12 5
 * 89
 * 64
 * 6
 * 43
 * 56
 * 72
 * 92
 * 23
 * 20
 * 22
 * 37
 * 31
 * output:
 * 5625
 * 8836
 */

#include <cstdio>
using namespace std;

int main() {
    int t, n, m;
    int tmp;
    while (scanf("%d", &t) != EOF) {
        for (int i = 0; i < t; ++i) {
            scanf("%d%d", &n, &m);
            int min = 100;
            for (int j = 0; j < n; ++j) {
                scanf("%d", &tmp);
                if (tmp < min) {
                    min = tmp;
                }
            }
            printf("%d\n", (100 - min) * (100 - min));
        }
    }
}