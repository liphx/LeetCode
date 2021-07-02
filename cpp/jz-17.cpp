/*
 * 输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> ans(pow(10, n) - 1);
        generate(ans.begin(), ans.end(), [n = 1] () mutable { return n++; });
        return ans;
    }
};

int main() {}
