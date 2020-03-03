#include <cstdio>

using namespace std;

/*
 * P261 寻找链表的第一个共同节点
 * 这里给出了链表中每一个节点的地址 A，且 A <= 10^5，则可用一个数组存储静态链表，
 */
const int max = 100010;

struct Node { // 静态链表节点
    char data; // 数据
    int next; // 下一个节点地址
    bool inList1; // 节点是否在第一个链表中

    Node() {
        inList1 = false; // 默认节点不再第一个链表中
    }
} node[max];

int main() {
    int l1_address, l2_address; // 两个链表的首地址
    int n; // 总共的节点数
    scanf("%d %d %d", &l1_address, &l2_address, &n);
    int nodeAddress;
    char nodeData;
    int nodeNextAddress;
    for (int j = 0; j < n; ++j) { // 读入所有节点建立链表
        scanf("%d %c %d", &nodeAddress, &nodeData, &nodeNextAddress);
        node[nodeAddress].data = nodeData;
        node[nodeAddress].next = nodeNextAddress;
    }
    int p;
    for (p = l1_address; p != -1; p = node[p].next) { // 遍历第一个链表，给其所有元素标志为在第一个链表中
        node[p].inList1 = true;
    }
    for (p = l2_address; p != -1; p = node[p].next) { // 遍历第二个链表，直到遇到第一个在第一个链表中的元素，即为第一个共同节点
        if (node[p].inList1) { break; }
    }
    if (p == -1) {
        printf("-1\n");
    } else {
        printf("%05d", p);
    }
}