/*
 * 输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。
 * 假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
 * 0 <= 节点个数 <= 5000
 */

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void print(TreeNode *tree) {
    if (tree == nullptr)
        return;
    cout << tree->val << " ";
    print(tree->left);
    print(tree->right);
}

class Solution {
public:
    TreeNode *build(const vector<int>& preorder, const vector<int>& inorder, int i, int j, int n) {
        if (n <= 0)
            return nullptr;
        TreeNode *tree = new TreeNode(preorder[i]);
        int size = 0;
        for (int k = j; inorder[k] != preorder[i]; k++, size++) ;
        int size2 = n - 1 - size;

        if (size > 0)
            tree->left = build(preorder, inorder, i + 1, j, size);
        if (size2 > 0)
            tree->right = build(preorder, inorder, i + 1 + size, j + 1 + size, size2);

        return tree;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, 0, preorder.size());
    }
};

int main()
{
    vector<int> preorder { 3, 9, 20, 15, 7 };
    vector<int> inorder { 9, 3, 15, 20, 7 };
    auto ans = Solution().buildTree(preorder, inorder);
    print(ans);
}
