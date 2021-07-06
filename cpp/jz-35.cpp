/*
 * 请实现 copyRandomList 函数，复制一个复杂链表。
 * 在复杂链表中，每个节点除了有一个 next 指针指向下一个节点，还有一个 random 指针指向链表中的任意节点或者 null。
 * Node.random 为空（null）或指向链表中的节点。
 * -10000 <= Node.val <= 10000
 */

#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// O(n^2)
class Solution {
public:
    Node* copyRandomList(Node* head) {
        vector<Node *> nodes;
        vector<Node *> origin;
        while (head) {
            nodes.emplace_back(new Node(head->val));
            origin.emplace_back(head);
            head = head->next;
        }
        int n = nodes.size();

        vector<int> idx(n);
        for (int i = 0; i < n; i++) {
            Node *cur = origin[i];
            if (cur->random == nullptr)
                idx[i] = -1;
            else {
                for (int j = 0; j < n; j++) {
                    if (cur->random == origin[j]) {
                        idx[i] = j;
                        break;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            nodes[i]->next = i + 1 < n ? nodes[i + 1] : nullptr;
            nodes[i]->random = idx[i] == -1 ? nullptr : nodes[idx[i]];
        }

        return n == 0 ? nullptr : nodes[0];
    }
};

// 原地修改
class Solution2 {
public:
    Node *copyRandomList(Node* head) {
        if (head == nullptr)
            return nullptr;

        // copy node and insert into next
        Node *cur = head;
        while (cur) {
            Node *next = cur->next;
            Node *node = new Node(cur->val);
            cur->next = node;
            node->next = next;
            cur = next;
        }

        // get random by random->next
        cur = head;
        while (cur) {
            Node *node = cur->next;
            node->random = cur->random == nullptr ? nullptr : cur->random->next;
            cur = cur->next->next;
        }

        // split to two lists
        Node *ret = head->next;
        while (head) {
            Node *node = head->next;
            Node *next = head->next->next;
            node->next = next == nullptr ? nullptr : next->next;
            head->next = next;
            head = next;
        }

        return ret;
    }
};

int main()
{
    Node nodes[3] = { 1, 2, 3 };
    nodes[0].next = &nodes[1];
    nodes[0].random = &nodes[2];
    nodes[1].next = &nodes[2];
    nodes[1].random = nullptr;
    nodes[2].random = &nodes[0];

    Node *ans = Solution2().copyRandomList(&nodes[0]);
    while (ans) {
        cout << ans->val << " ";
        if (ans->random)
            cout << ans->random->val << endl;
        else
            cout << "nullptr" << endl;
        ans = ans->next;
    }
}
