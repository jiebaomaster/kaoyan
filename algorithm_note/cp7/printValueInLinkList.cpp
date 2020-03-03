#include <cstdio>
#include <algorithm>

using namespace std;

/*
 * P265 按节点值从小到大的顺序输出链表上的所有节点，⚠️注意输入中可能含有不在链表上的节点
 */
const int maxn = 100010; // 静态链表最大空间

struct Node { // 静态链表的节点
    int data; // 本节点数据
    int address; // 本节点的地址
    int next; // 下一个节点的地址
    bool isListNode; // 本节点是和否在链表上

    Node() {
        isListNode = false; // 默认节点不在链表上
    };
} node[maxn];


/**
 * 应用与排序的比较函数，将所有在链表上的节点按节点值从小到大排在数组的左端
 * @param a
 * @param b
 * @return
 */
bool compare(Node a, Node b) {
    if (!a.isListNode || !b.isListNode) { // 主序为节点是否在链表上，保证链表上的节点被排在数组左端
        return a.isListNode > b.isListNode;
    } else { return a.data < b.data; }
}

int main() {
    int n, listAddress;
    int data, next, address;
    scanf("%d %d", &n, &listAddress);
    for (int i = 0; i < n; ++i) { // input
        scanf("%d%d%d", &address, &data, &next);
        node[address].address = address;
        node[address].data = data;
        node[address].next = next;
    }
    int count = 0; // 链表中节点的数量
    for (int p = listAddress; p != -1; p = node[p].next) { // 标记链表中的节点，并计算链表中节点的数量
        node[p].isListNode = true;
        count++;
    }
    if (count) {
        printf("%d %d\n", count, node[0].address);
        sort(node, node + maxn, compare);
        for (int j = 0; j < count; ++j) { // 数组左端的 count 个节点即在链表上的所有节点
            if (j != count - 1) {
                printf("%05d %d %05d\n", node[j].address, node[j].data, node[j].next); }
            else {
                printf("%05d %d -1\n", node[j].address, node[j].data);
            }
        }
    } else { // 所有节点都不在链表上，输出特殊处理
        printf("0 -1\n");
    }
}