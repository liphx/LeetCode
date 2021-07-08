/*
 * 给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。
 * 一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。
 * 0 <= num < 2^31
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int translateNum(int num) {
        vector<int> nums;
        while (num >= 10) {
            nums.emplace_back(num % 10);
            num /= 10;
        }
        nums.emplace_back(num);
        reverse(nums.begin(), nums.end());
        return translateNum(nums, 0);
    }

private:
    int translateNum(const vector<int>& nums, int idx) {
        if (idx == nums.size())
            return 1;
        int a = translateNum(nums, idx + 1);
        int b = 0;
        if (nums.size() > idx + 1 && nums[idx] > 0 && 10 * nums[idx] + nums[idx + 1] < 26) {
            b = translateNum(nums, idx + 2);
        }
        return a + b;
    }
};

int main()
{
    cout << Solution().translateNum(12258) << endl; // 5
    cout << Solution().translateNum(506) << endl;   // 1
}
