/*
 * 输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
 * 输出结果可能非常大，所以你需要返回一个字符串而不是整数
 * 拼接起来的数字可能会有前导 0，最后结果不需要去掉前导 0
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string minNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), comp);

        string ans;
        for (int x: nums) {
            ans += to_string(x);
        }
        return ans;
    }

private:
    static bool comp(int x, int y) {
        string s = to_string(x), t = to_string(y);
        return s + t < t + s;
    }
};

int main()
{
    vector<int> nums { 10, 2 };
    cout << Solution().minNumber(nums) <<endl;  // 102

    vector<int> nums2 { 3, 30, 34, 5, 9 };
    cout << Solution().minNumber(nums2) <<endl; // 3033459

    vector<int> nums3 { 0, 0, 0, 0, 0 };
    cout << Solution().minNumber(nums3) <<endl; // 00000

    vector<int> nums4 { 12, 121 };
    cout << Solution().minNumber(nums4) <<endl; // 12112
}
