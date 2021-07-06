/*
 * 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。
 * 要求不能创建任何新的节点，只能调整树中节点指针的指向。
 */

#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (root == nullptr)
            return nullptr;
        Node *left = treeToDoublyList(root->left);
        Node *right = treeToDoublyList(root->right);

        Node *start = left == nullptr ? root : left;
        Node *end = right == nullptr ? root : right->left;

        if (left) {
            left->left->right = root;
            root->left = left->left;
        }
        if (right) {
            root->right = right;
            right->left = root;
        }

        end->right = start;
        start->left = end;
        return start;
    }
};

int main() {}
