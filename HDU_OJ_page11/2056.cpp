#include <cstdio>
#include <algorithm>

using namespace std;

// Given two rectangles and the coordinates of two points on the diagonals of each rectangle,
// you have to calculate the area of the intersected part of two rectangles. its sides are parallel to OX and OY .
// https://blog.csdn.net/hpulw/article/details/50783001
// http://acm.hdu.edu.cn/showproblem.php?pid=2056

typedef struct node {
    double x, y; // 坐标
    int index; // 所属的矩形索引
} Node;

/**
 * 按点的 x 坐标排序
 * @param n1
 * @param n2
 * @return
 */
bool cmpX(Node n1, Node n2) {
    return n1.x < n2.x;
}

/**
 * 按点的 y 坐标排序
 * @param n1
 * @param n2
 * @return
 */
bool cmpY(Node n1, Node n2) {
    return n1.y < n2.y;
}

int main() {
    Node nodeList[4];
    while (scanf("%lf%lf%lf%lf%lf%lf%lf%lf",
                 &(nodeList[0].x), &(nodeList[0].y),
                 &(nodeList[1].x), &(nodeList[1].y),
                 &(nodeList[2].x), &(nodeList[2].y),
                 &(nodeList[3].x), &(nodeList[3].y)) != EOF) {

        nodeList[0].index = nodeList[1].index = 1; // 初始化点所属的矩形
        nodeList[2].index = nodeList[3].index = 2;
        sort(nodeList, nodeList + 4, cmpX);
        if (nodeList[0].index == nodeList[1].index) { // 判断两个矩形横向是否相交
            printf("0.00\n");
            continue;
        }
        double xDiff = nodeList[2].x - nodeList[1].x;
        sort(nodeList, nodeList + 4, cmpY);
        if (nodeList[0].index == nodeList[1].index) { // 判断两个矩形纵向是否相交
            printf("0.00\n");
            continue;
        }
        double yDiff = nodeList[2].y - nodeList[1].y;
        printf("%.2lf\n", xDiff * yDiff);
    }
}