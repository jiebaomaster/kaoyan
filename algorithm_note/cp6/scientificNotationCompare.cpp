#include <string>
#include <iostream>

using namespace std;

/**
 * P209 将两个数转化成保留N位小数的科学计数法后判断是否相等
 * 不考虑四舍五入
 */

/**
 * 将一个字符串表示的数转化成科学计数法表示
 * @param number
 * @param e 科学计数法中的指数，通过引用传给调用者
 * @param n 本地部分精度
 * @return 本地部分
 */
string deal(string number, int &e, int n) {
    e = 0;
    while (number.length() > 0 && number[0] == '0') { // 去除数字前的0
        number.erase(number.begin());
    }
    if (number[0] == '.') { // 原数字是一个小于0的小数
        number.erase(number.begin()); // 删除小数点
        while (number.length() > 0 && number[0] == '0') { // 删除小数点后第一个不为零的数之前所有的零
            number.erase(number.begin());
            e--;
        }
    } else {
        while (e < number.length() && number[e] != '.') { // 寻找数字中的小数点
            e++;
        }
        if (e > 0 && e < number.length()) {
            number.erase(number.begin() + e); // 删除小数点
        }
    }
    if (number.length() == 0) { // 去除先导零之后长度变为 0，则原数值为 0
        e = 0;
    }
    string result;
    for (int i = 0; i < n; ++i) { // 按指定精度拼接本地部分
        if (i < number.length()) {
            result += number[i];
        } else { // 不够精度的在最后补零
            result += '0';
        }
    }
    return result;
}

int main() {
    string a, b, scientificNotationA, scientificNotationB;
    int eA, eB;
    int n;
    cin >> n >> a >> b;
    scientificNotationA = deal(a, eA, n);
    scientificNotationB = deal(b, eB, n);
    if (scientificNotationA == scientificNotationB && eA == eB) {
        cout << "YES 0." << scientificNotationA << "*10^" << eA << endl;
    } else {
        cout << "NO 0." << scientificNotationA << "*10^" << eA << " 0." << scientificNotationB << "*10^" << eB << endl;
    }
    return 0;
}