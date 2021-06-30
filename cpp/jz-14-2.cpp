/*
 * 给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 k[0],k[1]...k[m - 1] 。
 * 请问 k[0]*k[1]*...*k[m - 1] 可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。
 * 答案需要取模 1000000007
 * 2 <= n <= 1000
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int multiplyMod(int a, int b) {
        return (long long)a * b % 1000000007;
    }

    int pow3(int n) {
        int ans = 1;
        for (int i = 0; i < n; i++)
            ans = multiplyMod(ans, 3);
        return ans;
    }

    int cuttingRope(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;

        if (n % 3 == 0) // 3 * 3 * ... * 3
            return pow3(n / 3);
        if (n % 3 == 2) // 2 * 3 * 3 * ... * 3
            return multiplyMod(pow3(n / 3), 2);
        // 2 * 2 * 3 * ... * 3
        return multiplyMod(pow3(n / 3 - 1), 4);
    }
};

int main()
{
    cout << Solution().cuttingRope(4) << endl;      // 4
    cout << Solution().cuttingRope(1000) << endl;   // 620946522
}
