#include <cstdio>
#include <algorithm>

using namespace std;

/**
 * 向下调整
 * @param data
 * @param start
 * @param end
 */
void adjustDown(int data[], int start, int end) {
    data[0] = data[start];
    while (start * 2 <= end) { // 到叶子节点时退出
        int child = start * 2;
        if (child + 1 <= end && data[child] < data[child + 1]) { child++; } // 选择值最大的子节点
        if (data[start] < data[child]) { // 子节点大于父节点，需要进行交换
            data[start] = data[child];
            start = child;
        } else { // 父节点大于子节点，则已经成为大根堆，直接退出
            break;
        }
    }
    data[start] = data[0];
}

/**
 * 建立大根堆
 * @param data
 * @param length
 */
void buildMaxHeap(int *data, int length) {
    // 从最后一个非叶子节点开始，直到根节点，依次遍历所有的非叶子节点，进行向下调整
    // 反向遍历可以保证到每次遍历后，该子树都是一个大根堆，则最后到根节点时，整个树是一个大根堆
    for (int i = length / 2; i > 0; --i) {
        adjustDown(data, i, length);
    }
}

/**
 * 堆排序，大根堆版
 * ⚠️特别注意，由于堆使用了二叉树的静态存储性质：子节点index = 父节点index*2／父节点index*2+1，故数组下标要从 1 开始
 * @param data
 * @param length
 */
void heapSort(int data[], int length) {
    buildMaxHeap(data, length);
    for (int i = length; i > 1; --i) { // 每次选出（删去）堆中最大的元素（即堆顶），调整剩下元素的为大根堆
        swap(data[1], data[i]); // 将堆顶元素和最后一个元素交换
        adjustDown(data, 1, i - 1); // 排除最后一个元素，调整剩下的堆
    }
}


int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int *pData = new int[n];
        for (int i = 1; i <= n; ++i) {
            scanf("%d", pData + i);
        }
        heapSort(pData, n);
        for (int j = 1; j <= n; ++j) {
            if (j != 1) { printf(" "); }
            printf("%d", *(pData + j));
        }
        printf("\n");
        delete[] pData;
    }

    return 0;
}