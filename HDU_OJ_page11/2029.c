#include <stdio.h>
#include <string.h>

// “回文串”是一个正读和反读都一样的字符串，比如“level”或者“noon”等等就是回文串。请写一个程序判断读入的字符串是否是“回文”。
// http://acm.hdu.edu.cn/showproblem.php?pid=2029

int main() {
    int n;
    char str[100];
    while (scanf("%d%*c", &n) != EOF) {
        for (int i = 0; i < n; ++i) {
            scanf("%s%*c", str);
            int length = strlen(str);
            char *start = str;
            char *end = str + length - 1;
            int flag = 1;
            while (start < end) {
                if (*start != *end) {
                    flag = 0;
                    break;
                }
                start++;
                end--;
            }
            if (flag) {
                printf("yes\n");
            } else {
                printf("no\n");
            }
        }
    }
    return 0;
}