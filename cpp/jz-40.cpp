/*
 * 输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。
 * 0 <= k <= arr.length <= 10000
 * 0 <= arr[i] <= 10000
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& data, int k) {
        vector<int> ans;
        if (k <= 0)
            return ans;
        priority_queue<int, vector<int>> q(data.begin(), data.begin() + k);
        for (size_t i = k; i < data.size(); i++) {
            if (data[i] < q.top()) {
                q.pop();
                q.push(data[i]);
            }
        }
        for (size_t i = 0; i < k; i++) {
            ans.emplace_back(q.top());
            q.pop();
        }
        return ans;
    }
};

int main() {}
