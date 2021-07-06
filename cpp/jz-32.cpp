/*
 * 从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。
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
    vector<int> levelOrder(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode *> q;
        if (root)
            q.push(root);
        while (!q.empty()) {
            TreeNode *node = q.front();
            ans.emplace_back(node->val);
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
            q.pop();
        }
        return ans;
    }
};

int main() {}
