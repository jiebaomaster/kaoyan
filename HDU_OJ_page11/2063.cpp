/*
 * 过山车的每一排只有两个座位，每个女生必须找个个男生做partner和她同坐。每个女孩都有各自的想法，例如
 * Rabbit只愿意和XHD或PQK做partner，Grass只愿意和linle或LL做partner，PrincessSnow愿意和水域浪子或伪酷儿做partner。
 * 考虑到经费问题，boss刘决定只让找到partner的人去坐过山车，其他的人，嘿嘿，就站在下面看着吧。计算最多有多少对组合可以坐上过山车。
 * 图论中寻找最大匹配的算法，可用匈牙利算法解决。
 * 简要思路：顺沿配对，被占用的配对先让上级让出，递归下去，直到有一级不能出让或者出让成功为止
 * https://blog.csdn.net/u013384984/article/details/90718287
 * http://acm.hdu.edu.cn/showproblem.php?pid=2063
 */

#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 510;
bool map[maxn][maxn];
int boy[maxn]; // 记录每个男孩配对的女孩索引
bool matched[maxn]; // 顺沿配对过程中，标记每个男孩是否已经配对
int k, m, n; // 可能的组合数目，女生的人数，男生的人数

/**
 * 给第 x 个女同学找配对
 * @param x
 * @return 配对成功输出true
 */
bool find(int x) {
    for (int i = 1; i <= n; ++i) { // 遍历女孩可配对的所有男孩
        if (map[x][i] && !matched[i]) { // 可以产生配对 且 没有在该次顺沿配对中使用过
            matched[i] = true;
            if (!boy[i] || find(boy[i])) { // 该男孩目前没有配对 或者 可以顺沿配对
                boy[i] = x; // 更新男生配对的女孩
                return true;
            }
        }
    }
    return false;
}

int main() {
    int x, y;
    while (scanf("%d%d%d", &k, &m, &n) != EOF) {
        if (k == 0) { break; }
        memset(map, false, sizeof(map));
        memset(boy, 0, sizeof(boy));
        for (int i = 0; i < k; ++i) {
            scanf("%d%d", &x, &y);
            map[x][y] = true; // 女生 x 愿意和男生 y 配对
        }
        int ans = 0;
        for (int j = 1; j <= m; ++j) {
            memset(matched, false, sizeof(matched));
            if (find(j)) {
                ans++;
            }
        }
        printf("%d\n", ans);
    }
}

