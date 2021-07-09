/*
 * 在一个数组 nums 中除一个数字只出现一次之外，其他数字都出现了三次。请找出那个只出现一次的数字。
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i += 3) {
            if (i + 2 >= nums.size() || nums[i] != nums[i + 2])
                return nums[i];
        }
        return 0;
    }
};

class Solution2 {
public:
    int singleNumber(const vector<int>& nums) {
        vector<int> bits(32);
        for (int num: nums) {
            for (int i = 0; i < 32; i++) {
                if (num & (1 << i))
                    bits[i]++;
            }
        }
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            if (bits[i] % 3 != 0)
                ans |= (1 << i);
        }
        return ans;
    }
};

class Solution3 {
public:
    int singleNumber(const vector<int>& nums) {
        int a = 0;
        int b = 0;

        for(int num : nums) {
            a = (a ^ num) & ~b;
            b = (b ^ num) & ~a;
        }

        return a;
    }
};

int main()
{
    vector<int> nums { 3, 4, 3, 3 };
    cout << Solution().singleNumber(nums) << endl;  // 4
    cout << Solution2().singleNumber({ 3, 4, 3, 3 }) << endl;
    cout << Solution3().singleNumber({ 3, 4, 3, 3 }) << endl;
}
