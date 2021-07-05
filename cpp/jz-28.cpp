/*
 * 请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。
 */

#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            vector<TreeNode *> vc(n);
            for (int i = 0; i < n; i++) {
                TreeNode *node = q.front();
                vc[i] = node;
                if (node) {
                    q.push(node->left);
                    q.push(node->right);
                }
                q.pop();
            }

            for (int i = 0; i < n / 2; i++) {
                TreeNode *left = vc[i], *right = vc[n - 1 - i];
                if (left == nullptr && right == nullptr)
                    continue;
                if (left == nullptr || right == nullptr || left->val != right->val)
                    return false;
            }
        }
        return true;
    }
};

class Solution2 {
public:
    bool isSymmetric(TreeNode* root) {
        return isSymmetric(root, root);
    }

private:
    bool isSymmetric(TreeNode* left, TreeNode *right) {
        if (left == nullptr && right == nullptr)
            return true;

        if (left && right)
            return left->val == right->val && isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);

        return false;
    }
};

int main() {}
