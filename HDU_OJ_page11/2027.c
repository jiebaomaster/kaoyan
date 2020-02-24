#include <stdio.h>

// 统计每个元音字母在字符串中出现的次数。
// http://acm.hdu.edu.cn/showproblem.php?pid=2027

int main() {
    int n;
    char str[100];
    while (scanf("%d%*c", &n) != EOF) {
        for (int j = 0; j < n; ++j) {
            int a = 0;
            int e = 0;
            int i = 0;
            int o = 0;
            int u = 0;
            scanf("%[^\n]%*c", str);
            char *pCh = str;
            while (*pCh != '\0') {
                switch (*pCh) {
                    case 'a':
                        a++;
                        break;
                    case 'e':
                        e++;
                        break;
                    case 'i':
                        i++;
                        break;
                    case 'o':
                        o++;
                        break;
                    case 'u':
                        u++;
                        break;
                    default:;
                }
                pCh++;
            }
            printf("a:%d\ne:%d\ni:%d\no:%d\nu:%d\n", a, e, i, o, u);
            if (j != n - 1) {
                printf("\n");
            }
        }
    }
}