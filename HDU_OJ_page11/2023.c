#include <stdio.h>
#include <stdlib.h>

// 假设一个班有n(n<=50)个学生，每人考m(m<=5)门课，求每个学生的平均成绩和每门课的平均成绩，并输出各科成绩均大于等于平均成绩的学生数量。
// http://acm.hdu.edu.cn/showproblem.php?pid=2023

int main() {
    int students, lessons;
    while (scanf("%d %d", &students, &lessons) != EOF) {
        int *score = (int *) malloc(sizeof(int) * students * lessons); // 存储所有学生的成绩数组
        double *parStudent = (double *) malloc(sizeof(double) * students); // 每个学生的各科成绩平均数
        double *parLesson = (double *) malloc(sizeof(double) * lessons); // 各科目的所有学生成绩平均数
        int sumPreStudent;
        for (int i = 0; i < students; ++i) { // input
            sumPreStudent = 0;
            for (int j = 0; j < lessons; ++j) {
                scanf("%d", score + i * lessons + j);
                sumPreStudent += *(score + i * lessons + j);
            }
            *(parStudent + i) = sumPreStudent * 1.0 / lessons; // 计算学生平均分
        }

        int sumPreLesson;
        for (int k = 0; k < lessons; ++k) {
            sumPreLesson = 0;
            for (int i = 0; i < students; ++i) {
                sumPreLesson += *(score + k + i * lessons);
            }
            *(parLesson + k) = sumPreLesson * 1.0 / students; // 计算科目平均分
        }

        int count = 0; // 全科成绩都大于平均数的人数
        for (int l = 0; l < students; ++l) {
            int flag = 1;
            for (int i = 0; i < lessons; ++i) {
                if (*(parLesson + i) > *(score + l * lessons + i)) {
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                count++;
            }
        }

        // output
        for (int m = 0; m < students; ++m) {
            if (m == 0) {
                printf("%.2lf", *(parStudent));
            } else {
                printf(" %.2lf", *(parStudent + m));
            }
        }
        printf("\n");
        for (int n = 0; n < lessons; ++n) {
            if (n == 0) {
                printf("%.2lf", *(parLesson));
            } else {
                printf(" %.2lf", *(parLesson + n));
            }
        }
        printf("\n%d\n\n", count);
        free(score);
        free(parLesson);
        free(parStudent);
    }
}