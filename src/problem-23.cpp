/*
给你一个链表数组，每个链表都已经按升序排列。

请你将所有链表合并到一个升序链表中，返回合并后的链表。
*/

#include <iostream>
#include <vector>
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
    // 合并两个链表，leetcode no.21
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

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int size = lists.size();
        if (size == 0) {
            return nullptr;
        }

        ListNode *ret = lists[0];
        for (int i = 1; i < size; i++) {
            ret = mergeTwoLists(ret, lists[i]);
        }
        
        return ret;
    }
};

int main()
{
    ListNode a3(5), a2(4, &a3), a1(1, &a2);
    ListNode b3(4), b2(3, &b3), b1(1, &b2);
    ListNode c2(6), c1(2, &c2);
    vector<ListNode*> lists = { &a1, &b1, &c1 };
    ListNode *ans = Solution().mergeKLists(lists);
    while (ans) {
        cout << ans->val << " ";
        ans = ans->next;
    } //=> 1 1 2 3 4 4 5 6
    
    return 0;
}
