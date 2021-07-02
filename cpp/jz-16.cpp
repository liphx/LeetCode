/*
 * 实现 pow(x, n) ，即计算 x 的 n 次幂函数（即，x^n）。不得使用库函数，同时不需要考虑大数问题。
 * -100.0 < x < 100.0
 * -2^31 <= n <= 2^31-1
 * -10^4 <= x^n <= 10^4
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0)
            return 1;
        if (n % 2 == 1)
            return x * myPow(x, n - 1);
        if (n % 2 == -1)
            return 1 / x * myPow(x, n + 1);
        double ans = myPow(x, n / 2);
        return ans * ans;
    }
};

int main()
{
    cout << Solution().myPow(2, 10) << endl;        // 1024
    cout << Solution().myPow(2.1, 3) << endl;       // 9.261
    cout << Solution().myPow(2, -2) << endl;        // 0.25
    cout << Solution().myPow(2, INT_MIN) << endl;   // 0
}
