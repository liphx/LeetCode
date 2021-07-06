/*
 * 从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。
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
        while (!q.empty()) {
            int n = q.size();
            vector<int> sub(n);
            for (int i = 0; i < n; i++) {
                TreeNode *node = q.front();
                sub[i] = node->val;
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
                q.pop();
            }
            ans.emplace_back(sub);
        }
        return ans;
    }
};

int main() {}
