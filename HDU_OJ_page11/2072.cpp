/*
 * 统计一篇文章里不同单词的总数
 * http://acm.hdu.edu.cn/showproblem.php?pid=2072
 */

#include <cstdio>
#include <set>
#include <string>

using namespace std;

char article[10010];

int main() {
    while (scanf("%[^\n]%*c", article) != EOF) {
        if (article[0] == '#') { break; }
        string str;
        set<string> S;
        for (int i = 0; article[i] != '\0'; ++i) {
            if (article[i] == ' ') {
                if (str.size() > 0) {
                    S.insert(str);
                    str = "";
                }
            } else {
                str += article[i];
            }
        }
        if (str.size() > 0) {
            S.insert(str);
        }
        printf("%d\n", S.size());
    }
}