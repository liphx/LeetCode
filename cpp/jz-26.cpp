/*
 * 输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)
 * B是A的子结构， 即 A中有出现和B相同的结构和节点值。
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
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (!B)
            return false;
        if (isSameStructure(A, B))
            return true;
        if (A && isSubStructure(A->left, B))
            return true;
        if (A && isSubStructure(A->right, B))
            return true;
        return false;
    }

private:
    bool isSameStructure(TreeNode *A, TreeNode *B) {
        if (!B)
            return true;
        return A && A->val == B->val && isSameStructure(A->left, B->left) && isSameStructure(A->right, B->right);
    }
};

int main() {}
