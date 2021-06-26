/*
给定一个排序数组，你需要在 原地 删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。

不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int n = nums.size();
        int temp = nums[0];
        int k = 1;
        for (int i = 1; i < n; ++i) {
            if (nums[i] != temp) {
                temp = nums[i];
                if (k == i) 
                    ++k;
                else
                    nums[k++] = nums[i];
            }
        }
        return k;
    }
};

int main()
{
    vector<int> nums { 1, 1, 2 };
    cout << Solution().removeDuplicates(nums) << endl; //=> 2

    return 0;
}

