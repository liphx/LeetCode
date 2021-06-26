/* 给定范围 [m, n]，其中 0 <= m <= n <= 2147483647，返回此范围内所有数字的按位与（包含 m, n 两端点）。 */

#include <iostream>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int ret = 0;
        unsigned int tmp = 1;
        for (int i = 0; i < sizeof(int) * 8; i++) {
            int flag = 1;
            for (unsigned int j = m; j <= n; j++) {
                if ((j & tmp) == 0) {
                    flag = 0;
                    break;
                }
            }
            if (flag)
                ret += tmp;
            tmp <<= 1;
        }
        return ret;
    }
};

int main()
{
    cout << Solution().rangeBitwiseAnd(5, 7) << endl; //=> 4
    cout << Solution().rangeBitwiseAnd(0, 1) << endl; //=> 0
    cout << Solution().rangeBitwiseAnd(2147483646, 2147483647) << endl; //=> 2147483646

    return 0;
}
