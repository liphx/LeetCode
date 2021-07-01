/*
 * 编写一个函数，输入是一个无符号整数（以二进制串的形式），返回其二进制表达式中数字位数为 '1' 的个数（也被称为 汉明重量).）。
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        uint32_t mask = 0x80000000;
        for (int i = 0; i < 32; i++) {
            if ((n & mask) == mask)
                ans++;
            mask >>= 1;
        }
        return ans;
    }
};

int main() {}
