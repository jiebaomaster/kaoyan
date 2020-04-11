/*
 * P288 给定一个数组和其上的滑动窗口大小，求每个滑动窗口中数字的最大值
 * 本题的暴力解法需要扫描每个滑动窗口（大小为k）的数字，时间复杂度为 O(nk)
 * 如果把每个滑动看成一个队列，每次滑动意味着队首出队，新元素入队。
 * 以空间换时间的方法可在 O(1) 时间内求得栈的 max，又知可用两个栈模拟队列，故可在 O(1) 时间内求得队列的 max，即本题时间复杂可用队列优化为 O(n)。
 * 用上述方法代码较为复杂，可以考虑：用一个队列保存可能成为滑动窗口中最大值数字的下标，并始终保持当前滑动窗口的最大值在队首
 */

#include <cstdio>
#include <deque>
#include <vector>

using namespace std;

/**
 * 求每个滑动窗口中数字的最大值
 * @param data
 * @param length
 * @param slidingWindowsSize
 * @return
 */
vector<int> getMaxInSlidingWindows(const int data[], int length, int slidingWindowsSize) {
    vector<int> maxInSlidingWindows; // 每个滑动窗口的最大值
    if (data == NULL || length <= 0 || slidingWindowsSize > length) { return maxInSlidingWindows; }

    deque<int> index; // 可能成为最大值数字的下标，始终保持当前滑动窗口的最大值在队首
    for (int i = 0; i < slidingWindowsSize; ++i) { // 将第一个滑动窗口的元素尝试入队
        while (!index.empty() && data[i] >= data[index.back()]) { // 若队列中存在比当前值小的数，那这些数都不可能是接下去的滑动窗口的最大值，应当出队
            index.pop_back();
        }
        index.push_back(i); // 当前值有可能作为以后的滑动窗口的最大值
    }
    maxInSlidingWindows.push_back(data[index.front()]); // 先得到第一个滑动窗口的最大值

    for (int i = slidingWindowsSize; i < length; ++i) { // 剩下的元素依次尝试入队，⚠️此时要考虑队首元素是否在滑动窗口内
        if (index.front() <= i - slidingWindowsSize) { // 队首元素不在滑动窗口内，先出队
            index.pop_front();
        }
        while (!index.empty() && data[i] > data[index.back()]) { // 若队列中存在比当前值小的数，那这些数都不可能是接下去的滑动窗口的最大值，应当出队
            index.pop_back();
        }
        index.push_back(i); // 当前值有可能作为以后的滑动窗口的最大值
        maxInSlidingWindows.push_back(data[index.front()]);
    }
    return maxInSlidingWindows;
}

int main() {
    int testData[] = {2, 3, 4, 2, 6, 2, 5, 1};
    vector<int> maxInSlidingWindows = getMaxInSlidingWindows(testData, 8, 3);

    for (vector<int>::iterator it = maxInSlidingWindows.begin(); it != maxInSlidingWindows.end(); it++) {
        printf("%d ", *it);
    }

    return 0;
}