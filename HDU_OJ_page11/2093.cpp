/*
 * 按规则排序
 * http://acm.hdu.edu.cn/showproblem.php?pid=2093
 *
 * input:
 * 8 20
 * Smith	  -1	-16	8	0	0	120	39	0
 * John	  116	-2	11	0	0	82	55(1)	0
 * Josephus  72(3)	126	10	-3	0	47	21(2)	-2
 * Bush	  0	-1	-8	0	0	0	0	0
 * Alice	  -2	67(2)	13	-1	0	133	79(1)	-1
 * Bob	  0	0	57(5)	0	0	168	-7	0
 * output:
 * Josephus    5  376
 * John        4  284
 * Alice       4  352
 * Smith       3  167
 * Bob         2  325
 * Bush        0    0
 */

#include <cstdio>
#include <algorithm>

using namespace std;

struct student {
    char name[10];
    int ac = 0, time = 0;
} stu[10010];

bool cmp(student s1, student s2) {
    if (s1.ac != s2.ac) {
        return s1.ac > s2.ac;
    } else {
        return s1.time < s2.time;
    }
}

int main() {
    int n, m;
    int studentNum = 0;
    scanf("%d %d", &n, &m);
    while (scanf("%s", stu[studentNum].name) != EOF) {
        for (int j = 0; j < n; ++j) { // 统计一个学生的 ac 数和耗费时间
            int acTime = 0, errorTime = 0;
            scanf("%d(%d)", &acTime, &errorTime); // 数据间的空格使得每次输入独立
            if (acTime > 0) { // 正数代表已 ac
                stu[studentNum].ac++;
                stu[studentNum].time += acTime + m * errorTime;
            }
        }
        getchar(); // 抵消回车
        studentNum++;
    }
    sort(stu, stu + studentNum, cmp);
    for (int i = 0; i < studentNum; ++i) {
        // -表示左对齐，默认右对齐，数字表示输出的字符宽
        printf("%-10s %2d %4d\n", stu[i].name, stu[i].ac, stu[i].time);
    }
    return 0;
}