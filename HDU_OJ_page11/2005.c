#include <stdio.h>

// 给定一个日期，输出这个日期是该年的第几天。
// http://acm.hdu.edu.cn/showproblem.php?pid=2005

int main() {
    int year, mouth, day;
    int mouthDay[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // 每月的天数
    while (scanf("%d/%d/%d", &year, &mouth, &day) != EOF) {
        int countDays = day;
        for (int i = 1; i < mouth; ++i) {
            countDays += mouthDay[i];
        }
        if (mouth > 2 && ((year % 100 == 0 && year % 400 == 0) || (year % 100 && year % 4 == 0))) { // 大于2月且是闰年
            countDays++;
        }

        printf("%d\n", countDays);
    }
}