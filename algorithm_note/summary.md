# 算法笔记-胡凡 学习总结

## cp4-初步算法

### 递归

#### 全排列

求全排列的两种写法
- [按位尝试型](./cp4/fullPermutation.cpp)
- [分布依次交换型](../jianzhi_offer/cp4/permutation.c)

### 二分法

P129
可以用二分法求解的问题基本有以下两个特征：
1. 数组有序或基本有序
2. 寻找有序序列中第一个满足某条件的元素的位置。所谓"某条件"在序列中一定是从左到右先不满足，然后满足的（否则把该条件取反即可）

``` cpp
// 解决"寻找有序序列中第一个满足某条件的元素的位置"问题的固定模版
// 二分区间为左闭右闭的 [left,right]，初值必须能覆盖所有可能取值
int solve(int left, int right) {
    int mid;
    while (left < right) { // left == right时，找到唯一位置，退出循环
        mid = start + (end - start) / 2;
        if (条件成立) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}
```
#### 二分法的扩展

P131
给定一个定义在 [L,R] 上的单调函数 f(x)，求方程 f(x)=0 的根。
可见二分法中序列不一定会直接给出，有可能是一个单调函数「连续型」，也有可能是实际可以算出「离散型」，关键在于序列的单调性

``` cpp
// 解决"方程 f(x)=0 的根"问题的固定模版
const double eps = 1e-5;
double f(double x) { // 计算 f(x)
    return ...;
}
double solve(double left, double right) {
    int mid;
    while (right-left < eps) { // 误差小于指定值时可以接受，即算得方程的根
        mid = start + (end - start) / 2;
        if (f(mid) > 0) {
            right = mid;
        } else {
            left = mid;
        }
    }
    return left;
}
```