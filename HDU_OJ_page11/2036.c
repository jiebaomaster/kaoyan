#include <stdio.h>

// 计算任意多边形的面积
// http://acm.hdu.edu.cn/showproblem.php?pid=2036

typedef struct node {
    int x, y;
} Node;

/**
 * 利用向量的叉乘求三角形 ABC 的面积
 *         ->    ->   | ABx ABy |
 * SABCA = AB ✖️ AC = | ACx ACy | = BAx * CAy - BAy * CAx
 * 若 ABC 三点是逆时针给出的，即凸多边形的某一小快，此时向量叉乘为正数
 * 若 ABC 三点是顺时针给出的，即凹多边形中凹的那一块，此时向量叉乘为负数
 * https://www.jianshu.com/p/2e7437267b3e
 * @param n1
 * @param n2
 * @param n3
 * @return
 */
double calculateAreaOfTriangle(Node A, Node B, Node C) {
    int BAx = A.x - B.x;
    int BAy = A.y - B.y;
    int CAx = A.x - C.x;
    int CAy = A.y - C.y;
    return (BAx * CAy - BAy * CAx) / 2.0;
}

int main() {
    int n;
    Node node1;
    Node node2;
    Node node3;
    while (scanf("%d", &n) != EOF) {
        if (n == 0) { break; }
        double sSum = 0;
        scanf("%d %d", &node1.x, &node1.y);
        scanf("%d %d", &node2.x, &node2.y);
        for (int i = 2; i < n; ++i) { // 第一个点 A 固定，逆时针输入点 B C，依次计算构成的三角形 ABC 的面积
            scanf("%d %d", &node3.x, &node3.y);
            sSum += calculateAreaOfTriangle(node1, node2, node3);
            node2 = node3;
        }
        printf("%.1lf\n", sSum);
    }
}