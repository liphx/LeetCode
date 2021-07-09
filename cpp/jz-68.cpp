/*
 * 给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。
 * 所有节点的值都是唯一的。
 * p、q 为不同节点且均存在于给定的二叉搜索树中。
 */

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode *> v1, v2;
        TreeNode *node = root;
        while (node != p) {
            v1.emplace_back(node);
            if (node->val < p->val)
                node = node->right;
            else
                node = node->left;
        }
        v1.emplace_back(p);

        node = root;
        while (node != q) {
            v2.emplace_back(node);
            if (node->val < q->val)
                node = node->right;
            else
                node = node->left;
        }
        v2.emplace_back(q);

        int i = 0;
        while (i < v1.size() && i < v2.size() && v1[i] == v2[i]) i++;
        return v1[i - 1];
    }
};

int main() {}
