/* 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。给定的 n 保证是有效的 */

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr)
            return nullptr;
        ListNode ans(0);
        ans.next = head;
        ListNode *tmp1 = &ans, *tmp2 = &ans;
        for (int i = 0; i <= n; i++) {
            tmp1 = tmp1->next;
        }
        while (tmp1) {
            tmp2 = tmp2->next;
            tmp1 = tmp1->next;
        }
        tmp2->next = tmp2->next->next;
        return ans.next;
    }
};

int main()
{
    ListNode a1(1), a2(2), a3(3), a4(4), a5(5);
    a1.next = &a2;
    a2.next = &a3;
    a3.next = &a4;
    a4.next = &a5;
    auto head = &a1;
    int n = 2;
    auto ans = Solution().removeNthFromEnd(head, n);
    while (ans) {
        cout << ans->val << " ";
        ans = ans->next;
    }
    //=> 1 2 3 5

    return 0;
}
