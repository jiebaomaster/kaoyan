#include <stdio.h>

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

int main() {
    char *string = "abaccdeff";
    printf("%c", firstNotRepeatingChar(string));

    return 0;
}