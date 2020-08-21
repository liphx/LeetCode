/*
给定一个二叉树，找出其最小深度。

最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
*/

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) 
            return 0;
        if (root->left == nullptr && root->right == nullptr)
            return 1;
        if (root->left != nullptr && root->right == nullptr)
            return 1 + minDepth(root->left);
        if (root->right != nullptr && root->left == nullptr)
            return 1 + minDepth(root->right);       
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};

int main()
{
    TreeNode a(1), b(2);
    a.left = &b;
    cout << Solution().minDepth(&a) << endl; //=> 2

    return 0;
}
