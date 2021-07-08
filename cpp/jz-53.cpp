/*
 * 统计一个数字在排序数组中出现的次数。
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ans = 0;
        for (auto iter = lower_bound(nums.begin(), nums.end(), target);
                iter != nums.end() && *iter == target; iter++)
            ans++;
        return ans;
    }
};

class Solution2 {
public:
    int search(vector<int>& nums, int target) {
        return distance(lower_bound(nums.begin(), nums.end(), target),
               upper_bound(nums.begin(), nums.end(), target));
    }
};

int main()
{
    vector<int> nums { 5, 7, 7, 8, 8, 10 };
    cout << Solution().search(nums, 8) << endl;     // 2
    cout << Solution2().search(nums, 8) << endl;    // 2
}
