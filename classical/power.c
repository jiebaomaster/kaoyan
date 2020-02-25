#include <stdio.h>
#include <stdlib.h>
#include "../jianzhi_offer/lib/doubleNumberEqual.h"

// P16 数值的整数次方

/**
 * 简单快速幂，时间复杂度为 O(logn)
 * 这里用了从上到下的递归计算思路，另一种方法可见 https://blog.csdn.net/JYMiracle/article/details/88372736
 * @param base
 * @param unsignedExponent
 * @return
 */
double powerWithUnsignedExponent(double base, unsigned int unsignedExponent) {
    // 递归出口
    if (unsignedExponent == 0) { return 1; }
    else if (unsignedExponent == 1) { return base; }

    double result = powerWithUnsignedExponent(base, unsignedExponent / 2);
    result *= result;
    if (unsignedExponent % 2 == 1) { result *= base; }
    return result;
}

/**
 * 求一个数的幂
 * @param base
 * @param exponent
 * @return
 */
double power(double base, int exponent) {
    if (isEqual(base, 0.0) && exponent < 0) { // 处理错误输入
        printf("0的负次幂没有意义！");
        return 0.0;
    }

    unsigned int absExponent = (unsigned int) abs(exponent); // 指数的绝对值
    double result = powerWithUnsignedExponent(base, absExponent);
    if (exponent < 0) { // 负指数幂要做倒数
        result = 1 / result;
    }
    return result;
}

int main() {
    printf("%f ", power(2.0, 2));
    printf("%f ", power(2.0, -2));
    printf("%f ", power(-2.0, 9));
    printf("%f ", power(0.0, 2));
    printf("%f ", power(0.0, -2));
    return 0;
}