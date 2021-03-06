/* 题目描述：给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。 */

#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> data;
        int n = nums.size();
        for(int i = 0; i < n; ++i){
            int t = target - nums[i];
            if(data.find(t) != data.end()){
                return vector<int> {data[t], i};
            }
            data[nums[i]] = i;
        }
        return vector<int>();
    }
};

int main()
{
    vector<int> data { 2, 7, 11, 5 };
    int target = 9;
    vector<int> ans = Solution().twoSum(data, target);
    for(int x : ans)
        cout << x << " ";
    //=>0 1
    return 0;
}
