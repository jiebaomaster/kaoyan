#include <stdio.h>

// we define f(A) = 1, f(a) = -1, f(B) = 2, f(b) = -2, ... f(Z) = 26, f(z) = -26;
// Give you a letter x and a number y , you should output the result of y+f(x).
// http://acm.hdu.edu.cn/showproblem.php?pid=2055

int main() {
    int n;
    int number;
    char ch;
    while (scanf("%d%*c", &n) != EOF) {
        while (n--) {
            scanf("%c %d%*c", &ch, &number);
            int flag = 1;
            if (ch >= 'a' && ch <= 'z') {
                ch -= 32;
                flag = -1;
            }
            int result = (ch - 'A'+1) * flag + number;
            printf("%d\n", result);
        }
    }
}