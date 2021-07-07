/*
 * 输入一个字符串，打印出该字符串中字符的所有排列。
 * 你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。
 */

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> permutation(string s) {
        vector<string> ans;
        sort(s.begin(), s.end());
        do {
            ans.emplace_back(s);
        } while (std::next_permutation(s.begin(), s.end()));
        return ans;
    }
};

class Solution2 {
public:
    vector<string> permutation(string s) {
        vector<string> ans;
        permutation(ans, s, 0);
        return ans;
    }

    void permutation(vector<string>& ans, string& s, int idx) {
        if (idx == s.length())
            ans.emplace_back(s);
        bool chs[26] = { 0 }; // 去重
        for (int i = idx; i < s.length(); i++) {
            if (chs[s[i] - 'a'] == false) {
                chs[s[i] - 'a'] = true;
                swap(s[idx], s[i]);
                permutation(ans, s, idx + 1);
                swap(s[i], s[idx]);
            }
        }
    }
};

int main()
{
    auto ans = Solution2().permutation("abbc");
    for (auto s: ans)
        cout << s << endl;
}
