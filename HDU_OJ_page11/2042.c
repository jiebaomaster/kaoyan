#include <stdio.h>

// 每过一个收费站，都是拿走当时羊的一半，然后退还一只，等到老汉到达市场，就只剩下3只羊了。
// 计算一下老汉最初有多少只羊吗？
// http://acm.hdu.edu.cn/showproblem.php?pid=2042

int main() {
    int n;
    int m;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", &m);
            int result = 3;
            while (m--) {
                result = (result - 1) * 2;
            }
            printf("%d\n", result);
        }
    }

    return 0;
}