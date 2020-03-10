#include <cstdio>
#include <queue>

using namespace std;

/*
 * P276 一个矩阵由01组成，位置 (x,y)，的上下左右称为其相邻位置。
 * 如果矩阵中有若干个快是相邻的，则称他们构成一个块，求矩阵中块的个数。
 */
#define rows 6
#define cols 7
bool hasVisited[rows][cols]; // 标记节点是否已经入队，防止重复遍历

/**
 * 递归进行深度优先遍历，标记矩阵中相邻的1
 * @param matrix
 * @param row
 * @param col
 */
void find1block_dfs(int matrix[rows][cols], int row, int col) {
    if (row >= 0 && row < rows
        && col >= 0 && col < cols
        && !hasVisited[row][col]
        && matrix[row][col]) {
        hasVisited[row][col] = true;
        find1block_dfs(matrix, row - 1, col);
        find1block_dfs(matrix, row + 1, col);
        find1block_dfs(matrix, row, col - 1);
        find1block_dfs(matrix, row, col + 1);
    }
}

struct Node {
    int row, col;
};
int xDif[4] = {0, 0, 1, -1}; // 相邻位置的横坐标增量
int yDif[4] = {1, -1, 0, 0}; // 相邻位置的纵坐标增量

/**
 * 循环进行广度优先遍历，标记矩阵中相邻的1
 * @param matrix
 * @param row
 * @param col
 */
void find1block_bfs(int matrix[rows][cols], int row, int col) {
    queue<Node> q;
    Node node = {row, col};
    q.push(node);
    hasVisited[row][col] = true;
    while (!q.empty()) {
        Node top = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) { // 广度优先遍历相邻的位置
            Node curNode = {top.row + xDif[i], top.col + yDif[i]};
            if (curNode.row >= 0 && curNode.row < rows
                && curNode.col >= 0 && curNode.col < cols
                && !hasVisited[curNode.row][curNode.col]
                && matrix[curNode.row][curNode.col]) {
                hasVisited[curNode.row][curNode.col] = true;
                q.push(curNode);
            }
        }
    }
}

int main() {
    int matrix[rows][cols] = {
            {0, 1, 1, 1, 0, 0, 1},
            {0, 0, 1, 0, 0, 0, 0},
            {0, 0, 0, 0, 1, 0, 0},
            {0, 0, 0, 1, 1, 1, 0},
            {1, 1, 1, 0, 1, 0, 0},
            {1, 1, 1, 1, 0, 0, 0}
    };
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            hasVisited[i][j] = false;
        }
    }
    int count = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) { // 遍历每一个元素，如果是1，则块数加一，且将其相邻的所有的1标记
            if (!hasVisited[i][j] && matrix[i][j] == 1) {
                count++;
                find1block_bfs(matrix, i, j);
            }
        }
    }
    printf("%d", count);

    return 0;
}