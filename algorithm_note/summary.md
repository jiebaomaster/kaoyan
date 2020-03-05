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

## cp7-数据结构专题

### 链表

#### 寻找两个链表的第一个公共节点

1. 若节点元素可添加标记，可以使用标记法，先遍历一次标记链表一的所有节点，再遍历链表二直到遇到一个在链表一中出现的节点 [示例](./cp7/commonPointInTwoList.cpp)
2. 若节点元素不可添加标记，可以使用双指针法，先遍历一次两个链表，双出长度之差 dif，再遍历第二次，此时快指针在较长的链表中先走 dif步，再一起走，直到当两个指针指向同一个节点时停止 [示例](../jianzhi_offer/cp5/findFirstCommonNodeInTwoList.c)

## cp8-搜索专题

### 深度优先搜索

DFS可解决的一个常见问题：
给定一个序列，枚举这个数列的所有子序列（可以不连续），求一个最优的子序列。
其中采用递归实现DFS，因此可以用一个栈存储临时遍历序列，可见[示例](./cp8/dfsElementMultiplyUse.cpp)

此外，DFS结合回溯法，可以解决[二维数组中寻找符合要求的路径问题](../jianzhi_offer/cp2/findStringPathInMatrix.c)
从以上两个例子可以看出，DFS有个好处是可以对某条特殊的路径进行判断，可以最终得到这个路径上的每一个节点（栈保存）

### 广度优先搜索

可以利用其层序的特点求单源最短路径长度，如[迷宫中从起点到终点的最短路径长度求解](./cp8/bfsSingleSourceShortestPath.cpp)
BFS虽然能求出最短路径长度，但是不能指出路径上的每一个节点

解决[多路径选择（图／矩阵）的遍历](./cp8/find1blockInMatrix.cpp)问题时，dfs和bfs都适用

#### STL 的 queue 容器

当使用 STL 的 queue 时，元素入队的 push 操作只是制造了该元素的一个副本入队，因此在入队后对原元素的修改不会影响队列中的副本。