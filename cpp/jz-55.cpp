/*
 * 输入一棵二叉树的根节点，求该树的深度。从根节点到叶节点依次经过的节点（含根、叶节点）形成树的一条路径，最长路径的长度为树的深度。
 */

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode *tree) {
        if (!tree) return 0;
        return 1 + max(maxDepth(tree->left), maxDepth(tree->right));
    }
};

class Solution2 {
public:
    int maxDepth(TreeNode *tree) {
        stack<TreeNode *> s;
        if (tree == nullptr)
            return 0;

        s.push(tree);
        int max_depth = 1;
        int depth = 1;
        TreeNode *node, *prev = tree;
        while (!s.empty()) {
            node = s.top();
            if (node->left && prev != node->left && prev != node->right) {
                s.push(node->left);
                depth++;
                max_depth = max(max_depth, depth);
            } else if (node->right && prev != node->right) {
                s.push(node->right);
                depth++;
                max_depth = max(max_depth, depth);
            } else {
                prev = s.top();
                s.pop();
                depth--;
            }
        }
        return max_depth;
    }
};

int main() {}
