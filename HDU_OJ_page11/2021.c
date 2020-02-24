#include <stdio.h>

// 如果每个老师的工资额都知道，最少需要准备多少张人民币，才能在给每位老师发工资的时候都不用老师找零呢？
// 这里假设老师的工资都是正整数，单位元，人民币一共有100元、50元、10元、5元、2元和1元六种。
// http://acm.hdu.edu.cn/showproblem.php?pid=2021

int countMoney(int money, const int moneyCategory[], int length) {
    int count = 0;
    while (money) {
        for (int i = 0; i < length; ++i) {
            if (money >= moneyCategory[i]) { // 贪心策略，每次找到刚好不大于的数值
                count++;
                money -= moneyCategory[i];
                break;
            }
        }
    }
    return count;
}

int main() {
    int n;
    int moneyCategory[] = {100, 50, 10, 5, 2, 1};
    while (scanf("%d", &n) != EOF) {
        if (n == 0) { break; }
        int sum = 0;
        int money = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &money);
            sum += countMoney(money, moneyCategory, 6);
        }
        printf("%d\n", sum);
    }

    return 0;
}