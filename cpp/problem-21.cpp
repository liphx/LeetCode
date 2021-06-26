/* 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 */

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode ret;
        ListNode *tmp = &ret;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                tmp->next = l1;
                l1 = l1->next;
            } else {
                tmp->next = l2;
                l2 = l2->next;
            }
            tmp = tmp->next;
        }

        if (l1 != nullptr) {
            tmp->next = l1;
        }

        if (l2 != nullptr) {
            tmp->next = l2;
        }
        
        return ret.next;
    }
};

int main()
{
    ListNode a1(1), a2(2), a3(4), b1(1), b2(3), b3(4);
    a1.next = &a2;
    a2.next = &a3;
    b1.next = &b2;
    b2.next = &b3;
    auto ans = Solution().mergeTwoLists(&a1, &b1);
    while (ans) {
        cout << ans->val << " ";
        ans = ans->next;
    } //=> 1 1 2 3 4 4

    return 0;
}
