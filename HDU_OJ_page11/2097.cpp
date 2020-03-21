/*
 * 判断一个数十进制十六进制十二进制表示的各位数之和是否相等
 * http://acm.hdu.edu.cn/showproblem.php?pid=2097
 *
 * input:
 * 2992
 * 1234
 * output:
 * 2992 is a Sky Number.
 * 1234 is not a Sky Number.
 */

#include <cstdio>

/**
 * 获取某个进制表示下的各数位和
 * @param r 进制基
 * @param number
 * @return
 */
int getSum(int r, int number) {
    int sum = 0;
    while (number) { // 进制转换，除基取余法
        sum += number % r;
        number /= r;
    }
    return sum;
}

int main() {
    int n;
    while (scanf("%d",&n)!=EOF) {
        if (n==0) { break;}
        int n10=getSum(10,n);
        int n12=getSum(12,n);
        int n16=getSum(16,n);
        if (n10==n12&&n10==n16) {
            printf("%d is a Sky Number.", n);
        } else {
            printf("%d is not a Sky Number.", n);
        }
        printf("\n");
    }

    return 0;
}