/*
 * 地上有一个 m 行 n 列的方格，从坐标 [0, 0] 到坐标 [m-1, n-1] 。
 * 一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。
 * 例如，当 k 为 18 时，机器人能够进入方格 [35, 37] ，因为 3 + 5 + 3 + 7 = 18。
 * 但它不能进入方格 [35, 38]，因为3 + 5 + 3 + 8 = 19。
 * 请问该机器人能够到达多少个格子？
 * 1 <= n, m <= 100
 * 0 <= k <= 20
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canMove(int x, int y, int k) {
        while (x >= 10) {
            k -= x % 10;
            x /= 10;
        }
        k -= x;
        while (y >= 10) {
            k -= y % 10;
            y /= 10;
        }
        k -= y;
        return k >= 0;
    }

    // bfs
    int movingCount(int m, int n, int k) {
        queue<pair<int, int>> q;
        int visited[m][n];
        memset(visited, 0, sizeof(visited));
        q.push(make_pair(0, 0));
        visited[0][0] = 1;
        int ans = 1;
        while (!q.empty()) {
            int num = q.size();
            for (int i = 0; i < num; i++) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if (x + 1 < m && visited[x + 1][y] == 0 && canMove(x + 1, y, k)) {
                    ans++;
                    visited[x + 1][y] = 1;
                    q.push(make_pair(x + 1, y));
                }
                if (y + 1 < n && visited[x][y + 1] == 0 && canMove(x, y + 1, k)) {
                    ans++;
                    visited[x][y + 1] = 1;
                    q.push(make_pair(x, y + 1));
                }
            }
        }
        return ans;
    }
};

int main()
{
    cout << Solution().movingCount(2, 3, 1) << endl;    // 3
    cout << Solution().movingCount(3, 1, 0) << endl;    // 1
    cout << Solution().movingCount(16, 8, 4) << endl;   // 15
    cout << Solution().movingCount(38, 15, 9) << endl;  // 135
}
