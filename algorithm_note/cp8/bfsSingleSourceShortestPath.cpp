#include <cstdio>
#include <queue>

using namespace std;

/*
 * P278 在一个有障碍的迷宫中，每次只能往上下左右四个方向走一步，求从起点到终点的最短路径
 * 即求单源最短路径
 */

#define rows 5
#define cols 5

struct Node {
    int row, col;
    int level; // 该节点所在层级，即该节点到起点的距离
};
bool hasVisited[rows][cols]; // 标记节点是否已经入队，防止重复遍历
int xDif[4] = {0, 0, 1, -1}; // 相邻位置的横坐标增量
int yDif[4] = {1, -1, 0, 0}; // 相邻位置的纵坐标增量

/**
 * 求起点到终点的最短距离，即利用bfs求单源最短路径，bfs按层序遍历，可以保证最先遍历到终点时，得到的距离是最短的
 * @param matrix
 * @param row 开始坐标
 * @param col 开始坐标
 * @return
 */
int bfsSingleSourceShortestPath(char matrix[rows][cols], int row, int col) {
    queue<Node> q;
    Node node = {row, col, 0};
    q.push(node); // 从起点开始遍历
    while (!q.empty()) {
        Node top = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) { // 广度优先遍历相邻的位置
            Node curNode = {top.row + xDif[i], top.col + yDif[i]};
            if (curNode.row >= 0 && curNode.row < rows
                && curNode.col >= 0 && curNode.col < cols
                && !hasVisited[curNode.row][curNode.col]
                && matrix[curNode.row][curNode.col] != '*') {
                hasVisited[curNode.row][curNode.col] = true;
                curNode.level = top.level + 1; // 当前节点的层数为其根节点加一
                if (matrix[curNode.row][curNode.col] == 'T') { // 遍历到终点，直接输出距离
                    return curNode.level;
                }
                q.push(curNode);
            }
        }
    }
    return -1; // 无法到达的终点时，返回-1
}

int main() {
    char matrix[rows][cols] = { // '.'为平地，'*'为不可跨过的高墙，'S'为起点，'T'为终点
            {'.', '.', '.', '.', '.'},
            {'.', '*', '.', '*', '.'},
            {'.', '*', 'S', '*', '.'},
            {'.', '*', '*', '*', '.'},
            {'.', '.', '.', 'T', '*'}
    };
    printf("%d", bfsSingleSourceShortestPath(matrix, 2, 2));

    return 0;
}