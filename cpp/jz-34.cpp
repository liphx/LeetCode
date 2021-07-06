/*
 * 输入一棵二叉树和一个整数，打印出二叉树中节点值的和为输入整数的所有路径。
 * 从树的根节点开始往下一直到叶节点所经过的节点形成一条路径。
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
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<vector<int>> ans;
        if (root == nullptr)
            return ans;
        vector<int> cur;
        pathSum(ans, cur, root, target);
        return ans;
    }

private:
    void pathSum(vector<vector<int>>& ans, vector<int>& cur, TreeNode *root, int target) {
        if (root->left == nullptr && root->right == nullptr) {
            if (target == root->val) {
                cur.emplace_back(root->val);
                ans.emplace_back(cur);
            }
        } else if (root->left && root->right) {
            cur.emplace_back(root->val);
            vector<int> right(cur);
            pathSum(ans, cur, root->left, target - root->val);
            pathSum(ans, right, root->right, target - root->val);
        } else {
            cur.emplace_back(root->val);
            pathSum(ans, cur, root->left != nullptr ? root->left : root->right, target - root->val);
        }
    }
};

int main() {}
