#include <stdio.h>
#include <stdlib.h>

/**
 * P243 第一个只出现一次的字符
 * @param string
 * @return
 */
char firstNotRepeatingChar(char *string) {
    int hashTable[256]; // hash表，因为 char 是 8 位的，最多 256 种可能，故 hash 表大小为256
    for (int i = 0; i < 256; ++i) { // 初始化 hash 表
        hashTable[i] = 0;
    }
    char *pString = string;
    while (*pString != '\0') { // 字符串所有字符按其 ascii 码值依次进行 hash
        hashTable[*(pString++)]++; // 字符隐式类型转化为 int 作为索引
    }
    pString = string;
    while (*pString != '\0') {
        if (hashTable[*pString] == 1) { break; }
        pString++;
    }
    return *pString;
}

/**
 * P247 字符流中第一个只出现一次的字符
 * 字符流是一个一个字符读入数据的，不能如上题全部遍历，需要借助一个容器记录已读取内容的特征
 */
typedef struct { // 一个读取字符流并记录读取内容的容器
    int index; // 当前读取的字符在字符流中的位置
    int charHash[256]; // -1:未出现; -2:多次出现; >=0:只出现一次，值为出现的时候在字符流中的次序
} CharStatistics;

/**
 * 初始化字符流容器
 * @param charStatistics
 */
void initCharStatistics(CharStatistics *charStatistics) {
    charStatistics->index = 0;
    for (int i = 0; i < 256; ++i) {
        charStatistics->charHash[i] = -1;
    }
}

/**
 * 在容器中插入一个字符
 * @param charStatistics
 * @param ch
 */
void insertCharStatistics(CharStatistics *charStatistics, char ch) {
    if (charStatistics->charHash[ch] == -1) {
        charStatistics->charHash[ch] = charStatistics->index;
    } else if (charStatistics->charHash[ch] >= 0) {
        charStatistics->charHash[ch] = -2;
    }
    charStatistics->index++;
}

/**
 * 获取当前字符流中第一个只出现一次的字符
 * @param charStatistics
 * @return
 */
char firstNotRepeatingCharOnStream(CharStatistics *charStatistics) {
    char ch = '\0';
    int curIndex = charStatistics->index;
    for (int i = 0; i < 256; ++i) { // 扫描整个 hash 表，最小的大于等于 0 的值即为所求字符的位置
        int tmp = charStatistics->charHash[i];
        if (tmp >= 0 && tmp < curIndex) {
            ch = (char) i;
            curIndex = tmp;
        }
    }
    return ch;
}

int main() {
    char *string = "abaccdeff";
    printf("%c\n", firstNotRepeatingChar(string));

    CharStatistics *pCharStatistics = (CharStatistics *)malloc(sizeof(CharStatistics));
    initCharStatistics(pCharStatistics);
    insertCharStatistics(pCharStatistics,'g');
    insertCharStatistics(pCharStatistics,'o');
    insertCharStatistics(pCharStatistics,'o');
    printf("%c\n",firstNotRepeatingCharOnStream(pCharStatistics));
    insertCharStatistics(pCharStatistics,'g');
    printf("%c\n",firstNotRepeatingCharOnStream(pCharStatistics));
    insertCharStatistics(pCharStatistics,'l');
    insertCharStatistics(pCharStatistics,'e');
    printf("%c",firstNotRepeatingCharOnStream(pCharStatistics));
    return 0;
}