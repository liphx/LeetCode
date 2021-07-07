/*
 * 输入一个整型数组，数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。
 * 要求时间复杂度为O(n)。
 */

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int sum = ans;
        for (int i = 1; i < nums.size(); i++) {
            if (ans <= 0) {
                ans = max(ans, nums[i]);
                sum = ans;
            }
            else {
                if (sum + nums[i] < 0) {
                    sum = 0;
                } else {
                    sum += nums[i];
                    ans = max(ans, sum);
                }
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> nums { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
    cout << Solution().maxSubArray(nums) << endl; // 6
}
