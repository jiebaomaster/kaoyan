#include <stdio.h>

// 输入一个字符串，判断其是否是C的合法标识符。
// http://acm.hdu.edu.cn/showproblem.php?pid=2024

// C语言中 scanf() 函数提供的“%[]”格式串可以用来进行多个字符的输入，并对结束符进行自定义。
// 对于%[]还可以用^+任意字符(包括 eof)来结束字符串的输入，如 %[^EOF] 就是直到有 EOF 输入，字符串才中止。

int main() {
    int n;
    while (scanf("%d%*c", &n) != EOF) {
        char str[51];
        char *pCh;
        int flag = 1;
        for (int i = 0; i < n; ++i) {
            pCh = str;
            flag = 1;
            scanf("%[^\n]%*c", str); // 直到输入回车键，读取才结束，当然不能超过a定义的大小，否则会出错。此命令与gets(str)效果一样。
            while (*pCh != '\0') {
                if (!((*pCh >= 'a' && *pCh <= 'z')
                      || (*pCh >= 'A' && *pCh <= 'Z')
                      || (*pCh >= '0' && *pCh <= '9' && pCh != str)
                      || *pCh == '_')) {
                    flag = 0;
                    break;
                }
                pCh++;
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