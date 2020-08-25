/*
给你一个数组 arr ，该数组表示一个从 1 到 n 的数字排列。有一个长度为 n 的二进制字符串，该字符串上的所有位最初都设置为 0 。
在从 1 到 n 的每个步骤 i 中（假设二进制字符串和 arr 都是从 1 开始索引的情况下），二进制字符串上位于位置 arr[i] 的位将会设为 1 。
给你一个整数 m ，请你找出二进制字符串上存在长度为 m 的一组 1 的最后步骤。一组 1 是一个连续的、由 1 组成的子串，且左右两边不再有可以延伸的 1 。
返回存在长度 恰好 为 m 的 一组 1  的最后步骤。如果不存在这样的步骤，请返回 -1 。

示例：

输入：arr = [3,5,1,2,4], m = 1
输出：4
解释：
步骤 1："00100"，由 1 构成的组：["1"]
步骤 2："00101"，由 1 构成的组：["1", "1"]
步骤 3："10101"，由 1 构成的组：["1", "1", "1"]
步骤 4："11101"，由 1 构成的组：["111", "1"]
步骤 5："11111"，由 1 构成的组：["11111"]
存在长度为 1 的一组 1 的最后步骤是步骤 4 。

提示：

n == arr.length
1 <= n <= 10^5
1 <= arr[i] <= n
arr 中的所有整数 互不相同
1 <= m <= arr.length
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        int ret = -1;
        int size = arr.size();
        set<pair<int, int>> str;
        str.insert(make_pair(0, size));
        for (int i = size - 1; i >= 0; i--) {
            if (str.empty())
                break;
            // 每次拆成两个字符串
            for (auto x : str) {
                if (x.second - x.first == m) 
                    return i + 1; // 下标从1开始
            }
            auto iter = str.lower_bound(make_pair(arr[i], arr[i]));
            auto tmp = *--iter;
            if (arr[i] > tmp.second)
                continue;
            if (arr[i] - 1 - tmp.first >= m) // 如果其中一个子串长度小于m，不用插入
                str.insert(make_pair(tmp.first, arr[i] - 1));
            if (tmp.second - arr[i] >= m)
                str.insert(make_pair(arr[i], tmp.second));
            str.erase(tmp);
        }

        return ret;
    }
};

int main()
{
    vector<int> arr { 3, 5, 1, 2, 4 };
    int m = 1;
    cout << Solution().findLatestStep(arr, m) << endl; //=> 4

    return 0;
}
