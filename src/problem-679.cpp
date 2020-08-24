/* 你有 4 张写有 1 到 9 数字的牌。你需要判断是否能通过 *，/，+，-，(，) 的运算得到 24。 */

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    bool f(vector<double>& nums) {
        // 递归
        int size = nums.size();
        if (size == 0)
            return false;
        if (size == 1)
            return abs(nums[0] - 24) < 1e-10;
        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                double num1 = nums[i], num2 = nums[j];
                auto tmp = nums;
                tmp.erase(tmp.begin() + i);
                tmp.erase(tmp.begin() + j - 1); // j > i, 移除nums[i]后,nums[j]提前,或者先移除nums[j]
                
                auto tmp2 = tmp;
                tmp2.emplace_back(num1 + num2);
                if (f(tmp2))
                    return true;

                tmp2 = tmp;
                tmp2.emplace_back(num1 * num2);
                if (f(tmp2))
                    return true;

                tmp2 = tmp;
                tmp2.emplace_back(num1 - num2);
                if (f(tmp2))
                    return true;
                tmp2 = tmp;
                tmp2.emplace_back(num2 - num1);
                if (f(tmp2))
                    return true;

                if (num2 != 0) {
                    tmp2 = tmp;
                    tmp2.emplace_back(num1 / num2);
                    if (f(tmp2))
                        return true;
                }
                
                if (num1 != 0) {
                    tmp2 = tmp;
                    tmp2.emplace_back(num2 / num1);
                    if (f(tmp2))
                        return true;
                }
            }
        }

        return false;
    }

    bool judgePoint24(vector<int>& nums) {
        vector<double> tmp { nums.begin(), nums.end() };
        return f(tmp);
    }
};

int main()
{
    vector<int> nums { 4, 1, 8, 7 };
    cout << (Solution().judgePoint24(nums) ? "true" : "false") << endl; //=> true, (8 - 4) * (7 - 1) = 24

    return 0;
}
