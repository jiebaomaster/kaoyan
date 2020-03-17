/*
 * 寒假的时候，ACBOY要去拜访很多朋友，恰巧他所有朋友的家都处在坐标平面的X轴上。
 * ACBOY可以任意选择一个朋友的家开始访问，但是每次访问后他都必须回到出发点，然后才能去访问下一个朋友。
 * 比如有4个朋友，对应的X轴坐标分别为1， 2， 3， 4。当ACBOY选择坐标为2的点做为出发点时，则他最终需要的时间为 |1-2|+|2-2|+|3-2|+|4-2| = 4。
 * 现在给出Ｎ个朋友的坐标，那么ACBOY应该怎么走才会花费时间最少呢？
 * 由数学知识可得，数列中的中位数到其他数的距离之和最小。
 * http://acm.hdu.edu.cn/showproblem.php?pid=2083
 */

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int num[10010];

int main() {
    int t;
    int n;
    while (scanf("%d", &t) != EOF) {
        for (int i = 0; i < t; ++i) {
            scanf("%d", &n);
            for (int j = 0; j < n; ++j) {
                scanf("%d", &num[j]);
            }
            sort(num, num + n);
            int mid = n / 2;
            int ans = 0;
            for (int k = 0; k < n; ++k) {
                ans += abs(num[mid] - num[k]);
            }
            printf("%d\n", ans);
        }
    }

    return 0;
}