/**
 * 从二维数组中取值
 * @param matrix
 * @param row
 * @param col
 * @param colLength
 * @return
 */
int getValue(int **matrix, int row, int col, int colLength) {
    return *((int *) matrix + row * colLength + col);
}