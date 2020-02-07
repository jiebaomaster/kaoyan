#include <math.h>
#include <stdbool.h>

#define EPSILON 1e-7 // 精度

/**
 * 由于浮点数的精度问题，浮点数的相等比较不能直接使用 '=='
 * @param a
 * @param b
 * @return
 */
bool isEqual(double a, double b) {
    return fabs(a - b) < EPSILON;
}