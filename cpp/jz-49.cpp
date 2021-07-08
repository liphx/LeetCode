/*
 * 我们把只包含质因子 2、3 和 5 的数称作丑数（Ugly Number）。求按从小到大的顺序的第 n 个丑数。
 * 1 是丑数。
 * n 不超过1690。
 */

#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        if (ans.size() >= n)
            return ans[n - 1];

        if (ans.empty())
            ans.emplace_back(1);

        while (ans.size() < n) {
            int pre = ans.back();
            int next[3];
            next[0] = ans[idx[0]] * 2;
            next[1] = ans[idx[1]] * 3;
            next[2] = ans[idx[2]] * 5;
            for (int i = 0; i < 3; i++) {
                if (next[i] == pre)
                    idx[i]++;
            }
            next[0] = ans[idx[0]] * 2;
            next[1] = ans[idx[1]] * 3;
            next[2] = ans[idx[2]] * 5;

            int i = 0;
            if (next[1] < next[i])
                i = 1;
            if (next[2] < next[i])
                i = 2;
            ans.emplace_back(next[i]);
            idx[i]++;
        }

        return nthUglyNumber(n);
    }

private:
    static::vector<int> ans;
    static int idx[3];
};

vector<int> Solution::ans;
int Solution::idx[3] = { 0 };

int main()
{
    cout << Solution().nthUglyNumber(10) << endl;   // 12
    cout << Solution().nthUglyNumber(12) << endl;   // 16
    cout << Solution().nthUglyNumber(1352) << endl; // 402653184
    cout << Solution().nthUglyNumber(1690) << endl; // 2123366400
}
