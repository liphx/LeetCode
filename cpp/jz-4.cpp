/*
 * 在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
 * 请完成一个高效的函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
 * 0 <= n <= 1000
 * 0 <= m <= 1000
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // matrix, [i, m][j, n]
    bool search(vector<vector<int>>& matrix, int i, int m, int j, int n, int target) {
        if (i > m || j > n)
            return false;
        if (i == m && j == n)
            return matrix[i][j] == target;
        int x = i + (m - i) / 2;
        int y = j + (n - j) / 2;
        if (matrix[x][y] == target)
            return true;
        if (matrix[x][y] > target) {
            return search(matrix, i, m, j, y - 1, target) ||
                search(matrix, i, x - 1, y, n, target);
        }

        return search(matrix, x + 1, m, j, n, target) ||
            search(matrix, i, x, y + 1, n, target);
    }

    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        return search(matrix, 0, matrix.size() - 1, 0, matrix[0].size() - 1, target);
    }
};

class Solution2 {
public:
    bool search(vector<vector<int>>& matrix, int i, int m, int j, int n, int target) {
        if (i > m || j > n)
            return false;
        if (matrix[i][n] == target)
            return true;
        if (matrix[i][n] < target)
            return search(matrix, i + 1, m, j, n, target);
        return search(matrix, i, m, j, n - 1, target);
    }

    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        return search(matrix, 0, matrix.size() - 1, 0, matrix[0].size() - 1, target);
    }
};

int main()
{
    vector<vector<int>> matrix {
        { 1, 4, 7, 11, 15 },
        { 2, 5, 8, 12, 19 },
        { 3, 6, 9, 16, 22 },
        { 10, 13, 14, 17, 24 },
        { 18, 21, 23, 26, 30 }
    };
    cout << Solution().findNumberIn2DArray(matrix, 5) << endl;  // 1
    cout << Solution().findNumberIn2DArray(matrix, 20) << endl; // 0
    cout << Solution2().findNumberIn2DArray(matrix, 5) << endl; // 1
    cout << Solution2().findNumberIn2DArray(matrix, 20) << endl;// 0

    vector<vector<int>> matrix2 {
        { 5 },
        { 6 }
    };
    cout << Solution().findNumberIn2DArray(matrix2, 6) << endl; // 1

    vector<vector<int>> matrix3 {
        { 1, 2, 3, 4, 5 }
    };
    cout << Solution().findNumberIn2DArray(matrix3, 4) << endl; // 1

    vector<vector<int>> matrix4 {
        { 1, 3, 5, 7, 9 },
        { 2, 4, 6, 8, 10 },
        { 11, 13, 15, 17, 19 },
        { 12, 14, 16, 18, 20 },
        { 21, 22, 23, 24, 25 }
    };
    cout << Solution().findNumberIn2DArray(matrix4, 11) << endl; // 1

    vector<vector<int>> matrix5 {
        { 4, 5, 10, 15, 19, 20, 20 },
        { 4, 9, 12, 15, 22, 23, 26 },
        { 7, 11, 12, 20, 25, 27, 27 },
        { 10, 14, 17, 23, 27, 30, 32 },
        { 11, 18, 19, 24, 28, 34, 39 }
    };
    cout << Solution().findNumberIn2DArray(matrix5, 25) << endl; // 1
}
