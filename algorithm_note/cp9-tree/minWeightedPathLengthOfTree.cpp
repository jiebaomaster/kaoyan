#include <cstdio>
#include <algorithm>

using namespace std;

/*
 * P342 在一个果园里，多多已经将所有的果子打了下来，而且按果子的不同种类分成了不同的堆。多多决定把所有的果子合成一堆。
 * 每一次合并，多多可以把两堆果子合并到一起，消耗的体力等于两堆果子的重量之和。可以看出，所有的果子经过n-1次合并之后，就只剩下一堆了。多多在合并果子时总共消耗的体力等于每次合并所耗体力之和。
 * 假定每个果子重量都为1，并且已知果子的种类数和每种果子的数目，设计出合并的次序方案，使多多耗费的体力最少，并输出这个最小的体力耗费值。
 * http://codeup.cn/problem.php?id=21142&csrf=rxwA36QY86bDFhjHIUrph2ziHLfxs20g
 *
 * 把每堆果子看作节点，节点权值为果子重量，这样合并两个果堆的过程可以视作给他们生成一个父节点，父节点的权值为子节点权值之和，于是整个合并过程可以用一棵树来表示。
 * 可以看出，消耗体力之和为树的带权路径长度，则原题即求带权路径长度 WPL 的最小值，可以哈夫曼树解决。
 * 本题中即很多算法题实际场景之中，不需要真的构建一颗哈夫曼树，只需求得最终的 WPL，故只需反复选择两个最小的元素，合并，直到剩下最后一个元素
 */

/**
 * 小根堆向下调整
 * @param data
 * @param start
 * @param end
 */
void adjustDown(long long data[], int start, int end) {
    data[0] = data[start];
    while (start * 2 <= end) {
        int child = start * 2;
        if (child < end && data[child] > data[child + 1]) { child++; }
        if (data[start] > data[child]) {
            data[start] = data[child];
            start = child;
        } else {
            break;
        }
    }
    data[start] = data[0];
}

/**
 * 小根堆向上调整
 * @param data
 * @param start
 */
void adjustUp(long long data[], int start) {
    data[0] = data[start];
    while (start > 1) { // 调整到根节点为止
        int father = start / 2;
        if (data[father] > data[start]) { // 只需判断二叉树的一个孩子，因为另一个孩子一定满足小根堆
            data[start] = data[father];
            start /= 2;
        } else {
            break;
        }
    }
    data[start] = data[0];
}

/**
 * 初始化小根堆
 * @param data
 * @param length
 */
void buildMinHeap(long long data[], int length) {
    for (int i = length / 2; i > 0; --i) {
        adjustDown(data, i, length);
    }
}

const int maxn = 1000;

/**
 * 用小根堆实现优先级队列，即最小的数据总是在队首
 * 也可以直接使用 STL 中的 priority_queue
 */
class PriorityQueue {
private:
    int length;
    long long data[maxn];
public:
    PriorityQueue() {}

    PriorityQueue(long long data[], int length) {
        for (int i = 1; i <= length; ++i) { // 注意小根堆数组从 1 开始计数
            this->data[i] = data[i - 1];
        }
        this->length = length;
        buildMinHeap(this->data, this->length);
    }

    /**
     * 返回当前队列中元素的数量
     * @return
     */
    int size() {
        return this->length;
    }

    /**
     * 向队列添加一个数据
     * 将新数据加在数组末尾，并执行一次向上调整，调整为新的小根堆
     * @param x
     */
    void push(long long x) {
        this->data[++this->length] = x;
        adjustUp(this->data, this->length);
    }

    /**
     * 队首元素出队
     * 交换小根堆第一个元素和最后一个元素，删除最后一个，执行一次向下调整
     */
    void pop() {
        swap(this->data[1], this->data[this->length]);
        adjustDown(this->data, 1, --this->length);
    }

    /**
     * 返回队首（堆顶）元素的值
     * @return
     */
    long long top() {
        return this->data[1];
    }
};

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        long long *pData = new long long[n];
        for (int i = 0; i < n; ++i) {
            scanf("%lld", pData + i);
        }
        PriorityQueue *pPriorityQueue = new PriorityQueue(pData, n);
        long long ans =0;
        while (pPriorityQueue->size() > 1) {
            long long a = pPriorityQueue->top();
            pPriorityQueue->pop();
            long long b = pPriorityQueue->top();
            pPriorityQueue->pop();
            pPriorityQueue->push(a + b); // 反复选择两个最小的元素，合并

            ans += a+b; // 累加计算每次搬运消耗的体力
        }
        printf("%lld\n", ans);
        delete pPriorityQueue;
    }
    return 0;
}