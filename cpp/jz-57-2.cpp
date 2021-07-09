/*
 * 输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。
 * 序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。
 */

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> ans;
        target *= 2;
        for (int n = sqrt(target); n >= 2; n--) {
            int start = (target / n + 1 - n);
            if (target % n == 0 && start % 2 == 0) {
                start /= 2;
                vector<int> vc;
                for (int i = 0; i < n; i++) {
                    vc.emplace_back(i + start);
                }
                ans.emplace_back(vc);
            }
        }
        return ans;
    }
};

int main()
{
    auto ans = Solution().findContinuousSequence(10);
    for (auto& i: ans) {
        for (int j: i) {
            cout << j << " ";
        }
        cout << endl;
    }
}
