#include <stdio.h>
#include <string.h>

// a==b?，考虑大数问题
// http://acm.hdu.edu.cn/showproblem.php?pid=2054
#define strLength 100000

/**
 * 裁剪掉小数点后面多余的 0
 * @param number
 */
void trim(char *number) {
    if (!strchr(number, '.')) { return; } // 判断是否有小数点
    int j;
    for (j = strlen(number) - 1; number[j] == '0'; --j) {
    }
    number[j + 1] = '\0';
    if (number[j] == '.') {
        number[j] = '\0';
    }
}

int main() {
    char a[strLength];
    char b[strLength];
    while (scanf("%s %s%*c", a, b) != EOF) {
        trim(a);
        trim(b);
        printf("%s\n", strcmp(a, b) == 0 ? "YES" : "NO"); // 用 strcmp 直接比较两个字符串即可
    }
}

