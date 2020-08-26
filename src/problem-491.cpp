/*
给定一个整型数组, 你的任务是找到所有该数组的递增子序列，递增子序列的长度至少是2。

给定数组的长度不会超过15。
数组中的整数范围是 [-100,100]。
给定数组中可能包含重复数字，相等的数字应该被视为递增的一种情况。
*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> ans; // 去重
        int size = nums.size();
        if (size < 2) {
            return vector<vector<int>> { ans.begin(), ans.end() };
        }
        ans.insert(vector<int> { nums[0] }); // 初始化
        for (int i = 1; i < size; i++) {
            vector<vector<int>> a; // 用于防止下面死循环
            for (auto j : ans) {
                if (nums[i] >= j.back()) {
                    vector<int> tmp = j;
                    tmp.emplace_back(nums[i]);
                    a.emplace_back(tmp);
                }
            }
            ans.insert(a.begin(), a.end());
            vector<int> tmp;
            tmp.emplace_back(nums[i]);
            ans.insert(tmp);
        }

        vector<vector<int>> ret;
        for (auto x : ans) {
            if (x.size() >= 2) {
                ret.emplace_back(x);
            }
        }

        return ret;
    }
};

int main()
{
    vector<int> nums { 4, 6, 7, 7 };
    auto ans = Solution().findSubsequences(nums);
    for (auto i : ans) {
        cout << "[ ";
        for (auto j : i) {
            cout << j << " ";
        }
        cout << "]  ";
    } //=>[ 4 6 ]  [ 4 6 7 ]  [ 4 6 7 7 ]  [ 4 7 ]  [ 4 7 7 ]  [ 6 7 ]  [ 6 7 7 ]  [ 7 7 ]
    

    return 0;
}
