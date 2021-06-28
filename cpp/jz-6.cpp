/*
 * 输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。
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
    vector<int> reversePrint(ListNode* head) {
        vector<int> ans;
        while (head) {
            ans.emplace_back(head->val);
            head = head->next;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    ListNode nodes[] = { 1, 2, 3, 4, 5 };
    nodes[0].next = &nodes[1];
    nodes[1].next = &nodes[2];
    nodes[2].next = &nodes[3];
    nodes[3].next = &nodes[4];

    auto ans = Solution().reversePrint(&nodes[0]);
    for (auto x: ans) {
        cout << x << " ";
    }
}
