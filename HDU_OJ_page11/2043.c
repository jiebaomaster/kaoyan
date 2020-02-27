#include <stdio.h>

// (1).密码长度大于等于8，且不要超过16。
// (2).密码中的字符应该来自下面“字符类别”中四组中的至少三组。
// 这四个字符类别分别为：
// 1.大写字母：A,B,C...Z;
// 2.小写字母：a,b,c...z;
// 3.数字：0,1,2...9;
// 4.特殊符号：~,!,@,#,$,%,^;
// 给你一个密码，你的任务就是判断它是不是一个安全的密码。
// http://acm.hdu.edu.cn/showproblem.php?pid=2043

int main() {
    int n;
    char str[55];
    while (scanf("%d%*c", &n) != EOF) {
        for (int i = 0; i < n; ++i) {
            scanf("%s", str);
            int typeFlag[4] = {0, 0, 0, 0};
            int j;
            int lengthFlag = 1;
            for (j = 0; str[j] != '\0'; ++j) {
                if (j >= 16) {
                    lengthFlag = 0;
                    break;
                }
                if (str[j] >= 'a' && str[j] <= 'z') { // 小写字母
                    typeFlag[0] = 1;
                } else if (str[j] >= 'A' && str[j] <= 'Z') { // 大写字母
                    typeFlag[1] = 1;
                } else if (str[j] >= '0' && str[j] <= '9') { // 数字
                    typeFlag[2] = 1;
                } else { // 特殊字符
                    typeFlag[3] = 1;
                }
            }
            if (!lengthFlag || j < 8) { // 判断长度
                printf("NO\n");
                continue;
            }
            int count = 0;
            for (int k = 0; k < 4; ++k) {
                count += typeFlag[k];
            }
            if (count < 3) {
                printf("NO\n");
                continue;
            }
            printf("YES\n");
        }
    }
    return 0;
}