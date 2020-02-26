#include <cstdio>
#include <map>

using namespace std;

// 求两个集合的差，就是做集合的减法运算，从小到大输出结果
// http://acm.hdu.edu.cn/showproblem.php?pid=2034
// 关于树的应用 "并查集"，只能作集合的合并与查找，不能作差集
// 本题要求按从小到大输出，可选用红黑树实现的map，其查找时间复杂度为O(logN)，若对排序没有要求，可使用hash实现的 unordered_map，查找性能O(1)

int main() {
    int n, m;
    int tmp;
    while (scanf("%d %d", &n, &m) != EOF) {
        if (n == 0 && m == 0) { break; }
        map<int, bool> mapN;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &tmp);
            mapN[tmp] = true;
        }
        for (int j = 0; j < m; ++j) {
            scanf("%d", &tmp);
            if (mapN.find(tmp) != mapN.end()) {
                mapN[tmp] = false;
                n--;
            }
        }
        if (n) {
            // 可选c++11 特性for range循环
            // for(auto it : mapN){
            for (map<int, bool>::iterator it = mapN.begin(); it != mapN.end(); it++) { // 利用迭代器遍历 STL 容器
                if (it->second) {
                    printf("%d ", it->first);
                }
            }
        } else { // 差集为空输出NULL
            printf("NULL");
        }
        printf("\n");
    }
    return 0;
}