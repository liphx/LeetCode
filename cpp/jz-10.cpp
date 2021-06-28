/*
 * 求斐波那契（Fibonacci）数列的第 n 项
 * 答案需要取模 1000000007
 * 0 <= n <= 100
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static int ans[101];

    int init() {
        ans[0] = 0;
        ans[1] = 1;
        for (int i = 2; i <= 100; i++) {
            ans[i] = (ans[i - 1] % 1000000007 + ans[i - 2] % 1000000007) % 1000000007;
        }

        return 0;
    }

    int fib(int n) {
        static int dumy = init();
        (void)dumy;
        return ans[n];
    }
};

int Solution::ans[101];

class Solution2 {
public:
    int fib(int n) {
        if (n == 0)
            return 0;
        int a = 0, b = 1;
        for (int i = 1; i < n; i++) {
            int c = (a % 1000000007 + b % 1000000007) % 1000000007;
            a = b;
            b = c;
        }
        return b;
    }
};

int main()
{
    for (int i = 0; i <= 100; i++) {
        cout << Solution().fib(i) << endl;
        cout << Solution2().fib(i) << endl;
    }
}
