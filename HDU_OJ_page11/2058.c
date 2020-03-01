#include <stdio.h>
#include <math.h>

// Given a sequence 1,2,3,...N, your job is to calculate all the possible sub-sequences that the sum of the sub-sequence is M.
// 采用双循环直接遍历法会超时，根本问题是区间项数需要遍历得到，如果有一个（项数，首项，和）的直接关系就可以快速求得项数，而本题的数组是一个1为公差的等差数列
// 由等差数列求和公式：Sn = n*a + d*n*(n-1)/2，其中 n 位项数，d 为公差，a 为首项值
// 易知若存在由 1 开始的序列和等于m，则这个序列长度肯定是最长的。再由（项数，和）求 首项即可
// m = n*a+n(n-1)/2 => n^2+(2a-1)n-2m=0（关于n的一元二次方程）=> n = 1/2-a+sqrt((2a-1)^2+8m)/2 (求根公式，舍弃负值)，带入a=1，有n = sqrt(0.25 + 2 * m) - 0.5
//                  => a = m/n+1/2-n/2
// http://acm.hdu.edu.cn/showproblem.php?pid=2058

int main() {
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF) {
        if (m == 0 && n == 0) { break; }
        int maxNeedNumberQuantity = (int) (sqrt(0.25 + 2 * m) - 0.5); // 计算以 1 为首项时所需的项数，即最大需要的项数
        while (maxNeedNumberQuantity) {
            double a1 = 1.0 * m / maxNeedNumberQuantity + 1.0 / 2 - 1.0 * maxNeedNumberQuantity / 2;
            if (a1 == (int) a1) { // 若首项是一个整数，则可以输出
                printf("[%d,%d]\n", (int) a1, (int) a1 + (int) maxNeedNumberQuantity - 1);
            }
            maxNeedNumberQuantity--;
        }

        printf("\n");
    }
}