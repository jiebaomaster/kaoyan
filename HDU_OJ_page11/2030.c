#include <stdio.h>

// 统计给定文本文件中汉字的个数。
// 汉字机内码在计算机的表达方式的描述是,使用二个字节，每个字节最高位一位为1.
// 计算机中,补码第一位是符号位,1 表示为负数,所以 汉字机内码的每个字节表示的十进制数都是负数
// 所以这题也就可以简化为输入字符串判断其中字符转化为十进制数是否小于零.
// 注意:汉字是有两个小于零的字符组成,所以在统计结果的时候就要将count除以2了.
// http://acm.hdu.edu.cn/showproblem.php?pid=2030

int main() {
    int n;
    char str[1000];
    while (scanf("%d%*c", &n) != EOF) {
        for (int i = 0; i < n; ++i) {
            scanf("%[^\n]%*c", str);
            int count = 0;
            for (int j = 0; str[j] != '\0'; ++j) {
                if (str[j] < 0) {
                    count++;
                }
            }
            printf("%d\n", count / 2);
        }
    }
    return 0;
}