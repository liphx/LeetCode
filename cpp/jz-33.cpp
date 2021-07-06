/*
 * 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。如果是则返回 true，否则返回 false。
 * 假设输入的数组的任意两个数字都互不相同。
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        if (postorder.empty())
            return true;
        return verifyPostorder(postorder, 0, postorder.size() - 1);
    }

private:
    bool verifyPostorder(const vector<int>& postorder, int i, int j) {
        int root = postorder[j];
        int m = i;
        while (m < j && postorder[m] < root)
            m++;
        int n = m;
        while (n < j) {
            if (postorder[n] < root)
                return false;
            n++;
        }

        bool left = true, right = true;
        if (m > i)
            left = verifyPostorder(postorder, i, m - 1);
        if (m < j)
            right = verifyPostorder(postorder, m, j - 1);
        
        return left && right;
    }
};

int main()
{
    vector<int> postorder { 1, 6, 3, 2, 5 };
    cout << Solution().verifyPostorder(postorder) << endl; // 0

    vector<int> postorder2 { 1, 3, 2, 6, 5 };
    cout << Solution().verifyPostorder(postorder2) << endl; // 1
}
