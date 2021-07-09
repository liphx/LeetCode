/*
 * 写一个函数，求两个整数之和，要求在函数体内不得使用 “+”、“-”、“*”、“/” 四则运算符号。
 * a, b 均可能是负数或 0
 * 结果不会溢出 32 位整数
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int add(int a, int b) {
        if (b == 0)
            return a;
        return add(a ^ b, (unsigned int)(a & b) << 1);
    }
};

int main()
{
    cout << Solution().add(1, 1) << endl;   // 2
    cout << Solution().add(1, 2) << endl;   // 3
    cout << Solution().add(1, -3) << endl;  // -2
    cout << Solution().add(-1, 2) << endl;  // 1
}
