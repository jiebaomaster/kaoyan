/*
 * 有一群人，打乒乓球比赛，两两捉对撕杀，每两个人之间最多打一场比赛。
 * 球赛的规则如下：
 * 如果A打败了B，B又打败了C，而A与C之间没有进行过比赛，那么就认定，A一定能打败C。
 * 如果A打败了B，B又打败了C，而且，C又打败了A，那么A、B、C三者都不可能成为冠军。
 * 根据这个规则，无需循环较量，或许就能确定冠军。你的任务就是面对一群比赛选手，在经过了若干场撕杀之后，确定是否已经实际上产生了冠军。
 * 由题可知：只有一点的入度为 0 即只有一个人未被击败时产生了冠军
 * http://acm.hdu.edu.cn/showproblem.php?pid=2094
 *
 * input:
 * 3
 * Alice Bob
 * Smith John
 * Alice Smith
 * 5
 * a c
 * c d
 * d e
 * b e
 * a d
 * output:
 * Yes
 * No
 */

#include <iostream>
#include <cstring>
#include <string>
#include <map>

using namespace std;

int in[1010]; // 记录每个节点的入度
map<string, int> s2i; // 将字符串映射到整数
int num; // 选手人数

void registerName(string str) {
    if (s2i.find(str) == s2i.end()) {
        s2i[str] = num++;
    }
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        if (n == 0) { break; }
        memset(in, 0, sizeof(in));
        s2i.clear();
        num = 0;
        string a, b;
        for (int i = 0; i < n; ++i) {
            cin >> a >> b;
            registerName(a);
            registerName(b);
            in[s2i[b]]++;
        }
        int count = 0;
        for (int j = 0; j < num; ++j) { // 计算未被击败的选手数，即入度为 0 的数
            if (in[j] == 0) {
                count++;
                if (count == 2) { break; }
            }
        }
        if (count == 1) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}