/*
 * 请完成一个函数，输入一个二叉树，该函数输出它的镜像。
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
    TreeNode* mirrorTree(TreeNode* root) {
        if (root) {
            TreeNode *tmp = mirrorTree(root->left);
            root->left = mirrorTree(root->right);
            root->right = tmp;
        }
        return root;
    }
};

int main() {}
