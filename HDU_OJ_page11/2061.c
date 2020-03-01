#include <stdio.h>

// calculate GPA
// If there are K(K > 0) courses, the i-th course has the credit Ci, your score Si, then the result GPA is
// GPA = (C1 * S1 + C2 * S2 +……+Ci * Si……) / (C1 + C2 + ……+ Ci……) (1 <= i <= K, Ci != 0)
// If there is a 0 <= Si < 60, The GPA is always not existed.
// http://acm.hdu.edu.cn/showproblem.php?pid=2061

int main() {
    int n;
    int totalCoursesNumber;
    char name[35];
    double credit;
    double score;
    while (scanf("%d%*c", &n) != EOF) {
        for (int i = 0; i < n; ++i) {
            scanf("%d%*c", &totalCoursesNumber);
            int under60Flag = 0;
            double creditSum = 0;
            double scoreMultipleCreditSum = 0;
            for (int j = 0; j < totalCoursesNumber; ++j) {
                scanf("%s%*c%lf%lf%*c", name, &credit, &score);
                if (score < 60) {
                    under60Flag = 1;
                }
                creditSum += credit;
                scoreMultipleCreditSum += score * credit;
            }
            if (under60Flag) {
                printf("Sorry!\n");
            } else {
                double gpa = scoreMultipleCreditSum / creditSum;
                printf("%.2lf\n", gpa);
            }
            if (i!=n-1) {
                printf("\n");
            }
        }
    }
}