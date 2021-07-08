/*
 * 在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0）。
 * 你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格、直到到达棋盘的右下角。
 * 给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？
 * 0 < grid.length <= 200
 * 0 < grid[0].length <= 200
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        dp.resize(m);
        for (int i = 0; i < m; i++) {
            dp[i].resize(n);
        }
        return maxValue(grid, 0, 0);
    }

private:
    vector<vector<int>> dp;

    int maxValue(const vector<vector<int>>& grid, int i, int j) {
        if (dp[i][j] != 0)
            return dp[i][j];
        int m = grid.size(), n = grid[0].size();
        int ans = grid[i][j];
        if (i == m - 1 && j == n - 1)
            return dp[i][j] = ans;
        if (i < m - 1 && j < n - 1)
            return dp[i][j] = ans + max(maxValue(grid, i + 1, j), maxValue(grid, i, j + 1));
        if (j == n - 1)
            return dp[i][j] = ans + maxValue(grid, i + 1, j);
        return dp[i][j] = ans + maxValue(grid, i, j + 1);
    }
};

int main()
{
    vector<vector<int>> grid {
        { 1, 2, 5 },
        { 3, 2, 1 }
    };

    cout << Solution().maxValue(grid) << endl; // 9
}
