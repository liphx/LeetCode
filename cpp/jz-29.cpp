/*
 * 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。
 * 0 <= matrix.length <= 100
 * 0 <= matrix[i].length <= 100
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return vector<int>();

        vector<int> ans;
        spiralOrder(matrix, ans, 0, matrix.size() - 1, 0, matrix[0].size() - 1);
        return ans;
    }

private:
    void spiralOrder(const vector<vector<int>>& matrix, vector<int>& ans, int i, int m, int j, int n) {
        if (m - i > 0 && n - j > 0) {
            for (int k = j; k < n; k++)
                ans.emplace_back(matrix[i][k]);
            for (int k = i; k < m ; k++)
                ans.emplace_back(matrix[k][n]);
            for (int k = n; k > j; k--)
                ans.emplace_back(matrix[m][k]);
            for (int k = m; k > i; k--)
                ans.emplace_back(matrix[k][j]);

            spiralOrder(matrix, ans, i + 1, m - 1, j + 1, n - 1);
        }
        if (m == i) {
            for (int k = j; k <= n; k++)
                ans.emplace_back(matrix[i][k]);
        } else if (n == j) {
            for (int k = i; k <= m; k++)
                ans.emplace_back(matrix[k][j]);
        }

    }
};

int main()
{
    vector<vector<int>> matrix {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 }
    };
    auto ans = Solution().spiralOrder(matrix);
    for (auto x: ans)
        cout << x << " ";
    cout << endl;
    // 1 2 3 6 9 8 7 4 5
}
