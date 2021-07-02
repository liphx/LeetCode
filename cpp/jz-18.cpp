/*
 * 给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。
 * 返回删除后的链表的头节点。
 * 题目保证链表中节点的值互不相同。
 * 不需要 free 或 delete 被删除的节点。
 */

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode ret(0), *pre = &ret;
        ret.next = head;

        while (head) {
            if (head->val == val) {
                pre->next = head->next; 
            }
            pre = head;
            head = head->next;
        }
        return ret.next;
    }
};

int main() {}
