/*
 * P292 定义一个队列并实现函数 max 求队列的最大值，要求max、出队、入队时间复杂度都为 O(1)
 * 只用一个变量保留最大值不能满足要求，因为最大值元素可能出队，此时要求得次最大值，
 * 与上一题一样，可以利用双栈法构造队列，也可以使用最大值队列法构造目标队列。本题出于代码复杂度的角度选用最大值队列法
 */

#include <cstdio>
#include <iostream>
#include <deque>

using namespace std;

template<typename T> // 模版类型
class QueueWithMax {
private:
    struct InternalData {
        T number;
        int index; // 给队列中每个元素编号，出队时用来判断最大值元素是否出队
    };
    deque<InternalData> data; // 数据队列
    deque<InternalData> maxData; // 最大值队列，保存可能是队列最大值的元素，且保持最大值在队首
    int _index; // 入队元素编号
public:
    QueueWithMax() : _index(0) {};

    /**
     * 队尾入队
     * @param value
     */
    void push_back(T value) {
        // ⚠️ 这里将输入值等于最大值的情况也包括了，故在最大值队列中不存在相等的值，且最大值队列中保存的是后入队的值，
        // 这样在出队时，队首元素等于最大值，但不是最后入队的，即 index 不相等，故最大值队列不用出队
        while (!this->maxData.empty() && this->maxData.back().number <= value) {
            this->maxData.pop_back();
        }
        InternalData internalData = {value, this->_index++};
        this->data.push_back(internalData);
        this->maxData.push_back(internalData);
    };

    /**
     * 队首出队
     */
    void pop_front() {
        if (maxData.empty()) { // 判空
            cout << "queue is empty" << endl;
            return;
        }

        if (this->data.front().index == this->maxData.front().index) { // 通过 index 判断出队的元素是否是当前最大元素
            this->maxData.pop_front();
        }
        this->data.pop_front();
    };

    /**
     * 获取队列中的最大值
     * @return
     */
    int getMax() {
        if (this->maxData.empty()) {
            cout << "queue is empty" << endl;
            return -1;
        }
        return this->maxData.front().number;
    }
};

int main() {
    QueueWithMax<int> queueWithMax;

    queueWithMax.push_back(1);
    printf("%d", queueWithMax.getMax());
    queueWithMax.push_back(3);
    printf("%d", queueWithMax.getMax());
    queueWithMax.push_back(3);
    printf("%d", queueWithMax.getMax());
    queueWithMax.push_back(2);
    printf("%d\n", queueWithMax.getMax());

    queueWithMax.pop_front();
    printf("%d", queueWithMax.getMax());
    queueWithMax.pop_front();
    printf("%d", queueWithMax.getMax());
    queueWithMax.pop_front();
    printf("%d", queueWithMax.getMax());

    return 0;
}