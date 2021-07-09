/*
 * 输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们的和正好是s。
 * 如果有多对数字的和等于s，则输出任意一对即可。
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            if (nums[i] + nums[j] == target)
                return vector<int> { nums[i], nums[j] };
            if (nums[i] + nums[j] > target)
                j--;
            else
                i++;
        }
        return vector<int>();
    }
};

int main()
{
    vector<int> nums { 2, 7, 11, 15 };
    auto ans = Solution().twoSum(nums, 9);
    for (int x: ans)
        cout << x << " ";
    cout << endl;

}
