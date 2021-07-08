/*
 * 一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0～n-1之内。
 * 在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字。
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        while (i <= j) {
            int mid = i + (j - i) / 2;
            if (nums[mid] != mid)
                j = mid - 1;
            else
                i = mid + 1;
        }
        return i;
    }
};

int main()
{
    vector<int> nums { 0, 1, 2, 3, 5, 6 };
    cout << Solution().missingNumber(nums) << endl; // 4
}
