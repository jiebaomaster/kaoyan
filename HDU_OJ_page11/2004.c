#include <stdio.h>

// 输入一个百分制的成绩t，将其转换成对应的等级，具体转换规则如下：
// 90~100为A;
// 80~89为B;
// 70~79为C;
// 60~69为D;
// 0~59为E;
// http://acm.hdu.edu.cn/showproblem.php?pid=2004

int main() {
    int t;
    while (scanf("%d%*c", &t)!=EOF) {
        char rank = '\0';
        if (t >= 90 && t <= 100) {
            rank = 'A';
        } else if (t >= 80 && t <= 89) {
            rank = 'B';
        } else if (t >= 70 && t <= 79) {
            rank = 'C';
        } else if (t >= 60 && t <= 69) {
            rank = 'D';
        } else if (t >= 0 && t <= 59) {
            rank = 'E';
        }
        if (rank == '\0') {
            printf("Score is error!\n");
        } else {
            printf("%c\n", rank);
        }
    }
}