#include <cstdio>
#include <algorithm>

using namespace std;

// 选择不相交的区间，使选出的区间数最大，区间贪心问题
// http://acm.hdu.edu.cn/showproblem.php?pid=2037

typedef struct section { // 定义区间结构体，方便排序使用贪心策略
    int start, end;
} section;

/**
 * 区间排序比较函数
 * @param a
 * @param b
 * @return
 */
bool cmp(section a, section b) {
    if (a.end != b.end) return a.end < b.end; // 按结束时间从小到大排列
    else return a.start > b.start; // 结束时间相同时，按开始时间从大到小排列
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        if (n == 0) { break; }
        section *pSection = new section[n];
        for (int i = 0; i < n; ++i) {
            scanf("%d %d", &((pSection + i)->start), &((pSection + i)->end));
        }
        sort(pSection, pSection + n, cmp);
        int count = 1;
        int preEnd = pSection->end;
        for (int j = 1; j < n; ++j) { // 优先选择结束时间最早且开始时间最晚的
            if (preEnd <= (pSection + j)->start) { // 当前的开始大于等于前一个的结束，则这个区间入选
                count++;
                preEnd = (pSection + j)->end; // 更新结束时间
            }
        }
        printf("%d\n", count);
        delete[] pSection;
    }
}
