/*
给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
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
    ListNode* swapPairs(ListNode* head) {
        ListNode ret(0);
        ret.next = head;
        ListNode *pre = &ret;
        // 每次读取两个节点
        while (head != nullptr && head->next != nullptr) {
            ListNode *tmp1 = new ListNode(head->next->val);
            ListNode *tmp2 = new ListNode(head->val);
            ListNode *tmp = head;
            tmp1->next = tmp2;
            tmp2->next = head->next->next;
            head = tmp2->next;
            pre->next = tmp1;
            pre = tmp2;
        }

        return ret.next;
    }
};

int main()
{
    ListNode a4(4), a3(3, &a4), a2(2, &a3), a1(1, &a2);
    ListNode *head = &a1;
    auto ans = Solution().swapPairs(head);
    while (ans) {
        cout << ans->val << " ";
        ans = ans->next;
    }
    cout << endl; //=>2 1 4 3

    return 0;
}
