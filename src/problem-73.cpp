/*
    给定一个 m x n 的矩阵，如果一个元素为 0，则将其所在行和列的所有元素都设为 0。请使用原地算法。
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0)
            return;
        int n = matrix[0].size();
        // O(m + n), 记录哪些行和列需要置0
        // O(1)
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    // 同行同列置0
                    for (int k1 = 0; k1 < n; k1++) {
                        matrix[i][k1] = (matrix[i][k1] != 0) ? INT_MAX : 0; // 如果是0，不修改
                    }
                    for (int k2 = 0; k2 < m; k2++) {
                        matrix[k2][j] = (matrix[k2][j] != 0) ? INT_MAX : 0;
                    }
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == INT_MAX)
                    matrix[i][j] = 0;
            }
        }
        
    }
};

int main()
{
    vector<vector<int>> matrix = { { 1, 1, 1}, { 1, 0, 1}, { 1, 1, 1 } };
    Solution().setZeroes(matrix);
    for (vector<int> i : matrix) {
        for (int j : i) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}