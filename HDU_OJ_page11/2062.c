#include <stdio.h>

// Consider the aggregate An= { 1, 2, …, n }. For example, A1={1}, A3={1,2,3}.
// A subset sequence is defined as a array of a non-empty subset.
// Sort all the subset sequence of An in lexicography order. Your task is to find the m-th one.
// 直接用递归一直算到第 m 个会超时，需要考虑加速方法
// An 子集合的个数为: C1n·A11 + C2n·A22 + ... + Cnn·Ann，可以分成以不同的数字开头的n组
// 例如 n=3 时，有以下分别以1，2，3开头的 3 组
// {1}, {1,2}, {1,2,3}, {1,3}, {1,3,2}
// {2}, {2,1}, {2,1,3}, {2,3}, {2,3,1}
// {3}, {3,1}, {3,1,2}, {3,2}, {3,2,1}
// 则关键在于求出每组集合个数，取余即可得到是由哪个数开始的，计算一次排列数即可
// 令 An 子集合的个数为 f(n)，观察 n=3 的情况，以3开头时，除了第一项3，其余的就是 A2 的子集合，故f(n) = n[f(n-1) + 1]
// 令 An 中每一组的个数 g(n)，则 g(n) = f(n) / n = n * [f(n-1) + 1] / n = f(n-1) + 1
// 又有 g(n) = f(n) / n => f(n-1) = (n-1) * g(n-1)
// ∴g(n) = (n-1) * g(n-1) + 1
// https://blog.csdn.net/lianqi15571/article/details/8877014?depth_1-utm_source=distribute.pc_relevant.none-task&utm_source=distribute.pc_relevant.none-task
// http://acm.hdu.edu.cn/showproblem.php?pid=2062

int main() {
    long long groupNumber[21] = {0}; // An 子集合按首字母分组，每组包含的子集合数量
    int numberInIndex[21]; // 按字典序排序，每一位上的值
    int AnLength;
    long long subsetNo;
    for (int k = 1; k < 21; ++k) {
        groupNumber[k] = (k - 1) * groupNumber[k - 1] + 1;
    }
    while (scanf("%d %lld", &AnLength, &subsetNo) != EOF) {
        for (int i = 0; i < 21; ++i) {
            numberInIndex[i] = i;
        }
        int groupIndex;
        while (subsetNo > 0 && AnLength > 0) {
            groupIndex = subsetNo / groupNumber[AnLength] + (subsetNo % groupNumber[AnLength] > 0 ? 1 : 0); // 当前位所在分组
            if (groupIndex > 0) {
                printf("%d", numberInIndex[groupIndex]); // 输出所在组的首元素
                // 将该子集的下一个元素到最后一个的值+1,注意这个规律：在第i组，首元素为i，删除首元素后，在第i个子集后首元素均变大+1
                for (int i = groupIndex; i <= AnLength; ++i) {
                    numberInIndex[i] = numberInIndex[i + 1];
                }
                subsetNo -= ((groupIndex - 1) * groupNumber[AnLength] + 1); // subsetNo 变为表示在剩余子集中位于第几个
                printf("%c", subsetNo == 0 ? '\n' : ' ');
            }
            AnLength--;
        }
    }
}
