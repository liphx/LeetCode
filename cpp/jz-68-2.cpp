/*
 * 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
 * 所有节点的值都是唯一的。
 * p、q 为不同节点且均存在于给定的二叉树中。
 */

#include <iostream>
#include <vector>
#include <algorithm>
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
        findNode(v1, root, p);
        findNode(v2, root, q);
        reverse(v1.begin(), v1.end());
        reverse(v2.begin(), v2.end());

        int i = 0;
        while (i < v1.size() && i < v2.size() && v1[i] == v2[i]) i++;
        return v1[i - 1];
    }

private:
    bool findNode(vector<TreeNode*>& path, TreeNode* root, TreeNode* node) {
        if (root == node) {
            path.emplace_back(node);
            return true;
        }

        if (root == nullptr)
            return false;

        if (findNode(path, root->left, node) || findNode(path, root->right, node)) {
            path.emplace_back(root);
            return true;
        }

        return false;
    }
};

int main() {}
