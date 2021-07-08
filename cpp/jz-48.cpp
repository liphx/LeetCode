/*
 * 请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。
 */

#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool repeat[256] = { 0 };
        int i = 0, j = 0;
        int ans = 0;
        while (j < s.length()) {
            int idx = s[j];
            if (!repeat[idx]) {
                repeat[idx] = true;
            } else {
                ans = max(ans, j - i);
                while (s[i] != s[j]) {
                    idx = s[i++];
                    repeat[idx] = false;
                }
                i++;
            }
            j++;
        }
        ans = max(ans, j - i);
        return ans;
    }
};

int main()
{
    cout << Solution().lengthOfLongestSubstring("abcabcbb") << endl;    // 3
    cout << Solution().lengthOfLongestSubstring("bbbbb") << endl;       // 1
    cout << Solution().lengthOfLongestSubstring("pwwkew") << endl;      // 3
    cout << Solution().lengthOfLongestSubstring("tmmzuxt") << endl;     // 5
}
