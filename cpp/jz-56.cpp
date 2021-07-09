/*
 * 一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。
 * 请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。
 * 2 <= nums.length <= 10000
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * 1. 异或满足交换律，结合律
 * 2. x & (-x) 得到 1 的最低位
 * 3. num & x 将数分成两组，a, b 在不同组
 */
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int a = 0, b = 0;
        int x = 0;
        for (int num: nums)
            x ^= num;
        x = x & (-x);
        for (int num: nums) {
            if (num & x)
                a ^= num;
            else
                b ^= num;
        }
        return vector<int> { a, b };
    }
};

int main()
{
    vector<int> nums { 1, 2, 10, 4, 1, 4, 3, 3 };
    auto ans = Solution().singleNumbers(nums);
    for (auto x: ans) {
        cout << x << " ";
    }
    cout << endl;
}
