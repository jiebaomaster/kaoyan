#include <stdio.h>

/**
 * 与快速排序一样的分割算法
 * @param data
 * @param start
 * @param end
 * @return 枢轴在数组中的索引
 */
int partition(int data[], int start, int end) {
    int pivot = data[start]; // 选取第一个数作为枢轴
    while (start < end) {
        while (start < end && data[end] > pivot) { end--; }
        data[start] = data[end];
        while (start < end && data[start] < pivot) { start++; }
        data[end] = data[start];
    }
    data[start] = pivot;
    return pivot;
}

/**
 * P209 找出数组中最小的 k 个数
 * 1.本算法的时间复杂度为 O(n)，分析过程如下：
 *   已知一次 partition 算法的时间复杂度为 O(n)，理想情况下循环中每次都会舍弃一半的数据，
 *   则总的时间复杂度为 O(n + n/2 + n/4 + n/8 + ...) = O(2n) = O(n)
 *   作为对比，快速排序中每次递归后并没有舍弃，仍然对所有数进行分割，且递归栈深度为 logn，即要进行 logn 次分割，即时间复杂度为 O(nlogn)
 * 2.需要注意的是该算法会改变输入数组的元素排序，若要求不改变顺序则应选用书本 P211 基于大根堆活红黑树的算法
 * @param data
 * @param length
 * @param k
 */
void getKthLeastNumber(int data[], int length, int k) {
    if (data == NULL || length <= 0 || k > length || k <= 0) { return; }

    int start = 0;
    int end = length - 1;
    int index = partition(data, start, end); // 这次分割的枢轴索引
    while (index != k - 1) {
        if (index < k - 1) { // 第 k 小的数在枢轴在第 index 小的数右边
            start = index + 1;
            index = partition(data, start, end); // 对剩下的部分再次分割
        } else {
            end = index - 1;
            index = partition(data, start, end);
        }
    }
    // 输出最小的 k 个数
    for (int i = 0; i < k; ++i) {
        printf("%d ", data[i]);
    }
}

int main() {
    int testData[] = {4, 5, 1, 6, 2, 7, 3, 8};
    getKthLeastNumber(testData, 8, 8);

    return 0;
}