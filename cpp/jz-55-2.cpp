/*
 * 输入一棵二叉树的根节点，判断该树是不是平衡二叉树。如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。
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
    bool isBalanced(TreeNode* root) {
        if (root == nullptr)
            return true;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        if (abs(left - right) > 1)
            return false;
        return isBalanced(root->left) && isBalanced(root->right);

    }

private:
    int maxDepth(TreeNode *tree) {
        if (!tree) return 0;
        return 1 + max(maxDepth(tree->left), maxDepth(tree->right));
    }
};

int main() {}
