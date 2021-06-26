/*
给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
k 是一个正整数，它的值小于或等于链表的长度。
如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

你的算法只能使用常数的额外空间。
你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
*/

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode ret(0);
        ret.next = head;
        ListNode *pre = &ret;
        // 每次读取k节点
        while (true) {
            ListNode *tmp = head;
            for (int i = 0; i < k; i++) {
                if (tmp == nullptr) {
                    return ret.next;
                }
                tmp = tmp->next;
            }
            ListNode *nodes[k]; // ListNode**
            for (int i = 0; i < k; i++) {
                nodes[i] = new ListNode(0);
            }
            for (int i = 0; i < k; i++) {
                nodes[i]->next = ((i < k-1) ? nodes[i+1] : nullptr);
                nodes[k-1-i]->val = head->val;
                head = head->next;
            }
            nodes[k-1]->next = head;
            pre->next = nodes[0];
            pre = nodes[k-1];
        }
    }
};

int main()
{
    ListNode a5(5), a4(4, &a5), a3(3, &a4), a2(2, &a3), a1(1, &a2);
    ListNode *head = &a1;
    int k = 5;
    auto ans = Solution().reverseKGroup(head, k);
    while (ans) {
        cout << ans->val << " ";
        ans = ans->next;
    }
    cout << endl; //=>2 1 4 3 5

    return 0;
}
