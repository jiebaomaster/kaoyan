#include <stdio.h>

/**
 * P74 计算第n个斐波那契数
 * 简单递归算法会存在很多次多余的递归，为了避免重复的计算，可以使用一个数组保存已经计算出的结果，
 * 这里使用自底向上的算法，用循环解决问题
 * @param n
 * @return
 */
long long fibonacci_loop(int n) {
    int f[] = {0, 1};
    if (n < 2) { return f[n]; }

    int fN = 0, // 第n个斐波那契数
            f_pre0 = f[0], // 当前要求的数之前2个数
            f_pre1 = f[1]; // 当前要求的数之前1个数
    for (int i = 2; i <= n; ++i) {
        fN = f_pre0 + f_pre1;

        f_pre0 = f_pre1;
        f_pre1 = fN;
    }
    return fN;
}

int main () {
    printf("%lld", fibonacci_loop(30));
    return 0;
}