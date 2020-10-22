/* 
给你一个字符串 s ，请你去除字符串中重复的字母，使得每个字母只出现一次。需保证 返回结果的字典序最小（要求不能打乱其他字符的相对位置）。

1 <= s.length <= 10^4
s 由小写英文字母组成
*/

#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int count[26] = { 0 };
        int len = s.length();
        for (int i = 0; i < len; i++) {
            count[s[i] - 'a']++;
        }

        string ret;

        int tmp_min = 'z';
        int tmp = 0;
        for (int j = 0; j < s.length(); j++) {
            if (s[j] < tmp_min) {
                tmp_min = s[j];
                tmp = j;
            }
            count[s[j] - 'a']--;
            if (count[s[j] - 'a'] == 0) { // 遇到第一个唯一字符
                ret += tmp_min;
                if (s[j] == tmp_min)
                    s = s[j] + string(s, tmp);
                else 
                    s = string(s, tmp);
                s.erase(remove(s.begin(), s.end(), tmp_min), s.end());
                return ret + removeDuplicateLetters(s);
            }
        }
        
        return s; //不用去重
    }
};

int main()
{
    cout << Solution().removeDuplicateLetters("bbaa") << endl; //=> ba

    return 0;
}