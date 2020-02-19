#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int g_maxNumberLength = 10; // 全局定义数组中可能的最长的正整数位数

/**
 * 自定义的排序规则函数，数字 n 和数字 m，若拼接后 mn < nm，则称 m 小于 n
 * 由于两个数字两种方式拼接后得到的数字位数总是相等的，在比较大小时，只需按字符串 ascii 码方式比较大小
 * @param strNumber1 原数组中一个值的指针，这里即 char**
 * @param strNumber2
 * @return
 */
int compare(const void *strNumber1, const void *strNumber2) {
    char *g_strCombineNumber1 = (char *) malloc(sizeof(char) * (g_maxNumberLength * 2 + 1)); // nm
    strcpy(g_strCombineNumber1, *(const char **)strNumber1);
    strcat(g_strCombineNumber1, *(const char **)strNumber2);
    char *g_strCombineNumber2 = (char *) malloc(sizeof(char) * (g_maxNumberLength * 2 + 1)); // mn
    strcpy(g_strCombineNumber2, *(const char **)strNumber2);
    strcat(g_strCombineNumber2, *(const char **)strNumber1);

    int result = strcmp(g_strCombineNumber1, g_strCombineNumber2);
    free(g_strCombineNumber1);
    free(g_strCombineNumber2);
    return result;
}

/**
 * P227 把一个正整数数组中的数字进行再排列，拼接成一个最小的数
 * 例：{3, 32, 321}，拼接成的最小数是 321323
 * 由于拼接后的数字又可能会超过 int 的范围，即考虑大数问题，先将正整数转化为一个字符串
 * @param data
 * @param length
 */
void arrangeMinNumber(int data[], int length) {
    // 初始化一个字符串数组
    char **strNumber = (char **) malloc(sizeof(char *) * length);
    for (int i = 0; i < length; ++i) { // 遍历数组，将每一个数字转化为字符串
        *(strNumber + i) = (char *) malloc(sizeof(char) * g_maxNumberLength + 1);
        sprintf(*(strNumber + i), "%d", data[i]); // 自定义输出区的 print 函数
    }

    qsort(strNumber, length, sizeof(char *), compare); // 用自定义的排序规则将字符串数组排序，排序后拼接出最小数的证明可见P229
    for (int j = 0; j < length; ++j) { // 依次输出排序后数组中的字符串
        printf("%s", *(strNumber + j));
    }
    printf("\n");

    // 释放堆中申请的内存空间
    for (int k = 0; k < length; ++k) {
        free(*(strNumber + k));
    }
    free(strNumber);
}

int main() {
    int data[] = {3, 321, 32};
    arrangeMinNumber(data, 3);

    return 0;
}