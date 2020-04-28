/*
 * 单调栈指存放的元素是有序的栈，可用 O(n) 时间解决以下三个基本问题：
 * 1.最基础的应用就是给定一组数，针对每个数，寻找它和它右边第一个比它大的数之间有多少个数。
 * 2.给定一序列，寻找某一子序列，使得子序列中的最小值乘以子序列的长度最大。
 * 单调栈这种数据结构，通常应用在一维数组上。如果遇到的问题，和前后元素之间的大小关系有关系的话，我们可以试图用单调栈来解决。
 * 最后的时间复杂度，因为每个元素都出栈入栈各一次，所以是线性时间的复杂度。
 *
 * https://blog.csdn.net/lucky52529/article/details/89155694
 * https://blog.csdn.net/smileiam/article/details/88732245
 * https://zhuanlan.zhihu.com/p/26465701
 *
 * 在中缀表达式转后缀表达式算法中，也借助了一个单调栈存放操作符序列
 */

#include <stack>

using namespace std;

/**
 * 找出数组中每个数右边第一个比它大的元素，若不存在这样的数取 -1
 * 容易想到暴力解法，对数组中的每个数向后遍历求得目标值，时间复杂度为 O(n^2)
 * 从左往右扫描原数组，对每个数字向右寻找，目标值一定在后面满足先进后出，可以想到栈，未找到目标的数的元素在栈中单调递减，构成单调栈
 * @param data
 * @param length
 * @return 返回目标值数组
 */
int *findNextExceed(const int data[], int length) {
    if (data == NULL || length <= 0) { return NULL; }

    int *result = new int[length]; // 结果数组
    memset(result, -1, sizeof(int) * length); // 结果数组初始化为 -1，即默认不存在目标数

    stack<int> monoStack; // 单调栈，栈内元素从底到顶递减，保存还未找到目标数的元素"索引"
    for (int i = 0; i < length; ++i) {
        while (!monoStack.empty() && data[monoStack.top()] < data[i]) { // 栈外大于栈顶，则所有小于栈外的元素出栈，以保持单调性
            result[monoStack.top()] = data[i]; // 栈外大于栈顶，即找到栈顶的右边第一个较大数，记录结果
            monoStack.pop();
        }
        monoStack.push(i); // 当前元素入栈
    }
    return result;
}


/**
 * 有 N 个矩形，宽度都为 1，给出 N 个矩形的高度，求由这 N 个矩形组成的图形包含的最大的矩形面积。
 *
 * 在上一题，每个元素出栈，是说明它找到了它在原数组中的next greater element。那这道题呢？元素出栈，意味着计算了以它的顶为上边框的最大矩形。
 * 首先，可以知道最后的结果中的最大矩形的上边框，一定和某一个矩形的顶重合。
 * 这一步之后，我们还需要理解，这时候我们计算的矩形的左右边框都已经到达了极限。
 * 当前栈顶元素为 i 时，左边界索引是下一个栈顶元素索引+1，右边界索引是当前欲压栈的元素索引 j，易知左右边界内的元素高度一定大于等于 height[i]
 * 因此我们证明了，当我们将第 i 个元素弹出栈的时候，可以计算出以 height[i] 为高的最大矩形的面积。
 *
 * @param data
 * @param length
 * @return
 */
int getMaxRectangleInHistogram(const int data[], int length) {
    if (data == NULL || length < 0) { return -1; }

    int curMax = 0; // 当前最大值
    stack<int> monoStack; // 单调栈，栈内元素从低到顶递增，保持还未计算最大面积的元素索引

    for (int i = 0; i < length; ++i) {
        while (!monoStack.empty() && data[monoStack.top()] > data[i]) {
            int height = data[monoStack.top()]; // 高度
            monoStack.pop();
            int right = i - 1; // 右边界
            int left = monoStack.empty() ? 0 : (monoStack.top() + 1); // 左边界
            int tmp = (right - left + 1) * height;
            if (tmp > curMax) { curMax = tmp; } // 更新最大值
        }
        monoStack.push(i);
    }
    while (!monoStack.empty() && data[monoStack.top()] > 0) { // 为使栈中的元素全部出栈，最后用 0 比较，也可以一开始在数组末尾添加 0
        int height = data[monoStack.top()]; // 高度
        monoStack.pop();
        int right = length - 1; // 右边界
        int left = monoStack.empty() ? 0 : (monoStack.top() + 1); // 左边界
        int tmp = (right - left + 1) * height;
        if (tmp > curMax) { curMax = tmp; }
    }
    return curMax;
}

int main() {
    int testData[] = {8, 2, 5, 4, 3, 9, 7, 2, 5};
    int *result = findNextExceed(testData, 9);
    for (int i = 0; i < 9; ++i) { // [9, 5, 9, 9, 9, -1, -1, 5, -1]
        printf("%d ", result[i]);
    }

    printf("\n%d", getMaxRectangleInHistogram(testData, 9));
    return 0;
}