/*
 * 某核反应堆有两类事件发生：
 * 高能质点碰击核子时，质点被吸收，放出3个高能质点和1个低能质点；
 * 低能质点碰击核子时，质点被吸收，放出2个高能质点和1个低能质点。
 * 假定开始的时候（0微秒）只有一个高能质点射入核反应堆，每一微秒引起一个事件发生(对于一个事件，当前存在的所有质点都会撞击核子)，
 * 试确定n微秒时高能质点和低能质点的数目。
 * http://acm.hdu.edu.cn/showproblem.php?pid=2085
 *
 * input:
 * 5 2
 * output:
 * 571, 209
 * 11, 4
 */

#include <cstdio>
#include <cstring>

int main() {
    int n;
    long long d[34][2];
    memset(d, 0, sizeof(d));
    d[0][0] = 1; // 0 微秒时高能质子数为 1
    d[0][1] = 0; // 0 微秒时低能质子数为 0
    for (int i = 1; i < 34; ++i) {
        d[i][0] = d[i - 1][0] * 3 + d[i - 1][1] * 2;
        d[i][1] = d[i - 1][0] + d[i - 1][1];
    }
    while (scanf("%d", &n) != EOF) {
        if (n == -1) { break; }
        printf("%lld, %lld\n", d[n][0], d[n][1]);
    }

    return 0;
}