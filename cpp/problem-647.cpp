/*
给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。

具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool f(string s) {
        int i = 0, j = s.length() - 1;
        while (i < j) {
            if (s[i++] != s[j--])
                return false;
        }
        return true;
    }

    int countSubstrings(string s) {
        int ans = 0;
        int len = s.length();
        for (int i = 0; i < len; i++) {
            for (int j = 1; j <= len - i; j++) {
                if (f(string(s, i, j)))
                    ans++;
            }
        }
        return ans;
    }
};

int main()
{
    cout << Solution().countSubstrings("abc") << endl;
    cout << Solution().countSubstrings("aaa") << endl;

    return 0;
}
