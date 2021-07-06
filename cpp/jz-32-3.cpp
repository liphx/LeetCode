/*
 * 请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。
 */

#include <iostream>
#include <vector>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode *> q;
        if (root)
            q.push(root);
        bool odd = true;
        while (!q.empty()) {
            int n = q.size();
            vector<int> sub(n);
            for (int i = 0; i < n; i++) {
                TreeNode *node = q.front();
                if (odd)
                    sub[i] = node->val;
                else
                    sub[n - 1 - i] = node->val;
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
                q.pop();
            }
            odd = !odd;
            ans.emplace_back(sub);
        }
        return ans;
    }
};

int main() {}
