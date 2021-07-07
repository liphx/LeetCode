/*
 * 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
 * 你可以假设数组是非空的，并且给定的数组总是存在多数元素。
 */

#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> hash_table;
        int n = nums.size();
        for (int x: nums) {
            hash_table[x]++;
            if (hash_table[x] > n / 2)
                return x;
        }
        return -1;
    }
};

class Solution2 {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};

class Solution3 {
public:
    int majorityElement(vector<int>& nums) {
        int ans;
        int count = 0;
        for (int x: nums) {
            if (count == 0) {
                ans = x;
                count++;
            }
            else if (ans == x)
                count++;
            else
                count--;
        }
        return ans;
    }
};

int main()
{
    vector<int> nums { 1, 2, 3, 2, 2, 2, 5, 4, 2 };
    cout << Solution().majorityElement(nums) << endl;   // 2
    cout << Solution2().majorityElement(nums) << endl;  // 2
    cout << Solution3().majorityElement(nums) << endl;  // 2
}
