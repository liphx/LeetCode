/*
 * 给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 k[0],k[1]...k[m-1] 。
 * 请问 k[0]*k[1]*...*k[m-1] 可能的最大乘积是多少？
 * 例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。
 * 2 <= n <= 58
 */

#include <bits/stdc++.h>
using namespace std;

int ans[59];

class Solution {
public:
    int cuttingRope(int n) {
        if (ans[n] > 0)
            return ans[n];
        if (n == 2)
            return 1;
        int ret = 1;
        for (int i = 1; i < n; i++) {
            if (n - i >= 2)
                ret = max(ret, i * cuttingRope(n - i));
            ret = max(ret, i * (n - i));
        }
        return ans[n] = ret;
    }
};

int main()
{
    cout << Solution().cuttingRope(2) << endl;  // 1
    cout << Solution().cuttingRope(3) << endl;  // 2
    cout << Solution().cuttingRope(10) << endl; // 36
    cout << Solution().cuttingRope(31) << endl; // 78732
}
