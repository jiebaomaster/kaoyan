#include <cstdio>
#include <cstring>

using namespace std;

// P170 大整数运算

typedef struct bigNumber { // 大数
    int d[1000]; // 小端序存储每一位字符，例如：123，d[0]=3,d[1]=2,d[2]=1
    int length; // 位数

    bigNumber() { // 利用构造函数自动初始化结构体
        memset(d, 0, sizeof(d));
        length = 0;
    }
} bign;

/**
 * 将一个字符串代表的数转化为大数
 * @param str
 * @return
 */
bign change(char str[]) {
    bign a;
    a.length = strlen(str);
    for (int i = 0; i < a.length; ++i) {
        a.d[i] = str[a.length - i - 1] - '0';
    }
    return a;
}

/**
 * 比较两个正大数的大小
 * @param a
 * @param b
 * @return A < B 返回-1，A > B 返回1，A = B 返回 0
 */
int compare(bign a, bign b) {
    if (a.length != b.length) { return a.length < b.length ? -1 : 1; }
    else {
        for (int i = a.length - 1; i >= 0; --i) { // 从高位到低位比较
            if (a.d[i] < b.d[i]) { return -1; }
            else if (a.d[i] > b.d[i]) { return 1; }
        }
        return 0;
    }
}

/**
 * 计算正大数相加
 * @param a
 * @param b
 * @return
 */
bign add(bign a, bign b) {
    bign result;
    int carry = 0; // 下一位的进位
    for (int i = 0; i < a.length || i < b.length; ++i) {
        int tmp = a.d[i] + b.d[i] + carry;
        result.d[result.length++] = tmp % 10;
        carry = tmp / 10;
    }
    if (carry) { // 处理最后还有一位进位
        result.d[result.length++] = carry;
    }
    return result;
}

/**
 * 计算正大数相减：a - b，要求满足a > b，若不满足可以在函数外调换 ab 位置，且手动添加负号
 * @param a
 * @param b
 * @return
 */
bign sub(bign a, bign b) {
    bign result;
    for (int i = 0; i < a.length; ++i) {
        if (a.d[i] < b.d[i]) { // 不够减时向高位借位
            a.d[i + 1]--;
            a.d[i] += 10;
        }
        result.d[result.length++] = a.d[i] - b.d[i];
    }
    while (result.length >= 2 && result.d[result.length - 1] == 0) { // 去除高位的零，保留一位数，因为 0 也是一位数
        result.length--;
    }
    return result;
}

/**
 * 正大数乘一个普通数，若存在负数，在函数外判断结果的正负性
 * 取大数的每一位与普通数整体相乘，再与进位相加，得到的数低位作为该位结果，其余高位作为进位，注意进位有可能有多位
 * 例如：447 * 35
 *      1. 7*35+0=245, d[0]=5, carry=24
 *      2. 4*35+24=164, d[1]=4, carry=16
 *      3. 4*35+16=156, d[2]=6, carry=15
 *      4. 处理最后的进位，15645
 * @param a
 * @param b
 * @return
 */
bign multi(bign a, int b) {
    bign result;
    int carry = 0; // 进位
    for (int i = 0; i < a.length; ++i) {
        int tmp = a.d[i] * b + carry;
        result.d[result.length++] = tmp % 10; // 低位作为该位结果
        carry = tmp / 10; // 高位作为进位
    }
    while (carry) { // 处理最后的进位，乘法进位有可能不止一位
        result.d[result.length++] = carry % 10;
        carry /= 10;
    }
    return result;
}

/**
 * 大数除以普通数
 * @param a 大数为被除数
 * @param b 普通数为除数
 * @param r 余数
 * @return
 */
bign divide(bign a, int b, int &r) {
    bign result;
    result.length = a.length;
    r = 0;
    for (int i = a.length - 1; i >= 0; --i) {
        r = r * 10 + a.d[i];
        if (r < b) { result.d[i] = 0; }
        else {
            result.d[i] = r / b;
            r %= b;
        }
    }
    while (result.length >= 2 && result.d[result.length - 1] == 0) { result.length--; }
    return result;
}

/**
 * output big number
 * @param a
 */
void printBigNumber(bign a) {
    for (int i = a.length - 1; i >= 0; --i) {
        printf("%d", a.d[i]);
    }
    printf("\n");
}

int main() {
    char str1[] = "147";
    char str2[] = "65";
    bign a = change(str1);
    bign b = change(str2);
    printBigNumber(a);
    printBigNumber(b);
    bign c = add(a, b);
    printBigNumber(c);
    bign d = sub(a, b);
    printBigNumber(d);
    bign e = multi(a, 65);
    printBigNumber(e);
    int r = 0;
    bign f = divide(a, 45, r);
    printBigNumber(f);
    printf("%d", r);

    return 0;
}