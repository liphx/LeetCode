/*
 * 一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。
 * 求该青蛙跳上一个 n 级的台阶总共有多少种跳法。
 * 答案需要取模 1000000007
 * 0 <= n <= 100
 */

class Solution {
public:
    int numWays(int n) {
        int a = 0, b = 1;
        for (int i = 0; i < n; i++) {
            int c = (a % 1000000007 + b % 1000000007) % 1000000007;
            a = b;
            b = c;
        }
        return b;
    }
};

int main() {}
