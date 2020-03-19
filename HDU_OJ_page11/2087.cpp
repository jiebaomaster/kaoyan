/*
 * 计算子串的数量
 * 本题字符串长度很小，可以采用暴力法，时间复杂度为 O(n*m)
 * todo 若 n 和 m 都达到 10^5 级别，需使用 kmp 算法
 * http://acm.hdu.edu.cn/showproblem.php?pid=2087
 *
 * input:
 * abcde a3
 * aaaaaa  aa
 * output:
 * 0
 * 3
 */

#include <cstdio>
#include <cstring>

char text[1010];
char patten[1010];

int main() {
    while (scanf("%s%*c", text) != EOF) {
        if (text[0] == '#') { break; }
        scanf("%s%*c", patten);
        int pattenLen = strlen(patten);
        int i = 0, j, k;
        int count = 0;
        while (text[i] != '\0') {
            for (j = 0, k = i; text[k] != '\0' && patten[j] != '\0' && patten[j] == text[k]; ++j, ++k) {
            }
            if (j == pattenLen) {
                count++;
                i += pattenLen; // 匹配字串成功，向前走字串的长度
            } else {
                i++; // 匹配不成功，向前走一步
            }
        }
        printf("%d\n", count);
    }

    return 0;
}