/*
 * 给定一棵二叉搜索树，请找出其中第k大的节点。
 */

#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        int n = greaterNum(root);
        if (n == k - 1)
            return root->val;
        if (n > k - 1)
            return kthLargest(root->right, k);
        else {
            return kthLargest(root->left, k - n - 1);
        }
    }

private:
    int greaterNum(TreeNode* root) {
        if (root)
            return getNum(root->right);
        return 0;
    }

    int getNum(TreeNode* root) {
        if (root == nullptr)
            return 0;
        return 1 + getNum(root->left) + getNum(root->right);
    }
};

int main() {}
