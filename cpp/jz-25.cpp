/*
 * 输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。 
 */

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode ret(0), *node = &ret;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                node->next = l1;
                l1 = l1->next;
            } else {
                node->next = l2;
                l2 = l2->next;
            }
            node = node->next;
        }

        node->next = l1 != nullptr ? l1 : l2;
        return ret.next;
    }
};

int main() {}
