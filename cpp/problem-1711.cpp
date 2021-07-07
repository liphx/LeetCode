/*
 * 大餐 是指 恰好包含两道不同餐品 的一餐，其美味程度之和等于 2 的幂。
 * 你可以搭配 任意 两道餐品做一顿大餐。
 * 给你一个整数数组 deliciousness ，其中 deliciousness[i] 第 i 道餐品的美味程度，返回你可以用数组中的餐品做出的不同 大餐 的数量。结果需要对 109 + 7 取余。
 * 注意，只要餐品下标不同，就可以认为是不同的餐品，即便它们的美味程度相同。
 * 1 <= deliciousness.length <= 10^5
 * 0 <= deliciousness[i] <= 2^20
 */

#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        unordered_map<int, long long> hash_table;
        for (int x: deliciousness) {
            hash_table[x]++;
        }

        long long ans = 0;
        for (auto p: hash_table) {
            for (int i = 0; i < 22; i++) {
                int exp = 1 << i;
                auto iter = hash_table.find(exp - p.first);
                if (iter != hash_table.end()) {
                    if (iter->first > p.first)
                        ans += p.second * iter->second;
                    else if (iter->first == p.first)
                        ans += p.second * (p.second - 1) / 2;
                    ans %= 1000000007;
                }
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> deliciousness { 1, 3, 5, 7, 9 };
    cout << Solution().countPairs(deliciousness) << endl; // 4

    vector<int> deliciousness2 { 1, 1, 1, 3, 3, 3, 7 };
    cout << Solution().countPairs(deliciousness2) << endl; // 15
}
