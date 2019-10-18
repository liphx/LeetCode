#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ret;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int pre = INT_MAX; // 针对重复用例的优化
        for(int i = 0; i < n - 2; ++i){
            int j = i + 1, k = n - 1;
            int target = -nums[i];
            if(target == pre)
                continue;
            pre = target;
            while(j < k){
                if((nums[j] + nums[k]) == target){
                    ret.insert(vector<int>{ nums[i], nums[j], nums[k] });
                    ++j;
                    --k;
                }
                else if((nums[j] + nums[k]) > target){
                    --k;
                }
                else{
                    ++j;
                }
            }
        }
        return vector<vector<int>>(ret.begin(), ret.end());
    }
};

/* 

给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？
找出所有满足条件且不重复的三元组。 注意：答案中不可以包含重复的三元组。 

*/

int main()
{   
    vector<int> nums { -1, 0, 1, 2, -1, -4 };
    vector<vector<int>> ans = Solution().threeSum(nums);
    for(auto v : ans){
        for(auto x : v){
            cout << x << " ";
        }
        cout << endl;
    }
    //=>-1 -1 2
    //  -1 0 1

    return 0;
}
