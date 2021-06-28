/*
 * 找出数组中重复的数字。
 * 在一个长度为 n 的数组 nums 里的所有数字都在 0 ~ n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。
 * 请找出数组中任意一个重复的数字。
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findRepeatNumber(const vector<int>& nums) {
        vector<bool> flags(nums.size());
        for (auto x: nums) {
            if (flags[x])
                return x;
            flags[x] = true;
        }
        return -1;
    }

    int findRepeatNumber2(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] != i) {
                if (nums[i] == nums[nums[i]])
                    return nums[i];
                swap(nums[i], nums[nums[i]]);
            }
        }
        return -1;
    }
};

int main()
{
    vector<int> nums {2, 3, 1, 0, 2, 5, 3};
    cout << Solution().findRepeatNumber(nums) << endl;
    cout << Solution().findRepeatNumber2(nums) << endl;
}
