/*
 * 假设所有的短号都是是 6+手机号的后5位，比如号码为13512345678的手机，对应的短号就是645678。将一个11位长的手机号码转为短号
 * http://acm.hdu.edu.cn/showproblem.php?pid=2081
 */

#include <cstdio>

int main() {
    int t;
    char phoneNum[12];
    while (scanf("%d", &t) != EOF) {
        for (int i = 0; i < t; ++i) {
            scanf("%s%*c", phoneNum); // 读取号码
            printf("6");
            for (int k = 6; k < 11; ++k) { // 输出5位尾号
                printf("%c", phoneNum[k]);
            }
            printf("\n");
        }
    }
    return 0;
}