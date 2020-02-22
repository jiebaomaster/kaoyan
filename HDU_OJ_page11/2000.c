#include <stdio.h>

// 输入三个字符后，按各字符的ASCII码从小到大的顺序输出这三个字符。
// http://acm.hdu.edu.cn/showproblem.php?pid=2000

int main() {
    char ch1, ch2, ch3;
    while (scanf("%c%c%c%*c", &ch1, &ch2, &ch3) != EOF) { // 用 %*c 抵消忽略输入的回车键
        char tmp = '\0';
        // 两趟冒泡
        if (ch1 > ch2) tmp = ch2, ch2 = ch1, ch1 = tmp; // 逗号表达式
        if (ch2 > ch3) tmp = ch3, ch3 = ch2, ch2 = tmp;
        if (ch1 > ch2) tmp = ch2, ch2 = ch1, ch1 = tmp;
        printf("%c %c %c\n", ch1, ch2, ch3);
    }
}
