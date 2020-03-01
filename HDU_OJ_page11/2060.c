#include <stdio.h>

// snooker
// http://acm.hdu.edu.cn/showproblem.php?pid=2060

int main() {
    int n;
    int ball, myScore, opponentScore;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i) {
            scanf("%d%d%d", &ball, &myScore, &opponentScore);

            if (ball <= 6) {
                while (ball--) {
                    myScore += 7 - ball;
                }
            } else {
                myScore += (ball - 6) * 8 + 2 + 3 + 4 + 5 + 6 + 7;
            }
            printf("%s\n", myScore >= opponentScore ? "Yes" : "No");
        }
    }
}