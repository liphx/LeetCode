/*
 * 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分。
 */

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        vector<int> ans(nums.size());
        int i = 0, j = nums.size() - 1;
        for (int x: nums) {
            if (x % 2 == 0)
                ans[j--] = x;
            else
                ans[i++] = x;
        }
        return ans;
    }
};

// partition
class Solution2 {
public:
    vector<int> exchange(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            while (i < j && nums[i] % 2 != 0)
                i++;
            while (i < j && nums[j] % 2 == 0)
                j--;
            swap(nums[i++], nums[j--]);
        }
        return nums;
    }
};

class Solution3 {
public:
    vector<int> exchange(vector<int>& nums) {
        partition(nums.begin(), nums.end(), [] (int x) { return x % 2 != 0; });
        return nums;
    }
};

int main() {}
