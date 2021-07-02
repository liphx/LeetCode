/*
 * 请实现一个函数用来匹配包含'. '和'*'的正则表达式。
 * 模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（含0次）。
 * 在本题中，匹配是指字符串的所有字符匹配整个模式。
 * 例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但与"aa.a"和"ab*a"均不匹配。
 * s 可能为空，且只包含从 a-z 的小写字母。
 * p 可能为空，且只包含从 a-z 的小写字母以及字符 . 和 *，无连续的 '*'。 
 */

#include <bits/stdc++.h>
using namespace std;

// problem-10.cpp
class Solution {
public:
    bool isMatch(string s, string p) {
        return isMatch(s, 0, p, 0);
    }

private:
    bool isMatch(const string& s, int i, const string& p, int j) {
        if (j == p.length())
            return i == s.length();
        if (j + 1 < p.length() && p[j + 1] == '*' && isMatch(s, i, p, j + 2))
            return true;
        if (j + 1 < p.length() && p[j + 1] == '*') {
            for (int idx = i; idx < s.length() && (p[j] == '.' || p[j] == s[idx]); idx++) {
                if (isMatch(s, idx + 1, p, j + 2))
                    return true;
            }
            return false;
        }
        if (i == s.length())
            return false;
        if (p[j] == '.' || p[j] == s[i])
            return isMatch(s, i + 1, p, j + 1);
        return false;
    }
};

int main()
{
    cout << Solution().isMatch("aa", "a") << endl;                      // 0
    cout << Solution().isMatch("aa", "a*") << endl;                     // 1
    cout << Solution().isMatch("ab", ".*") << endl;                     // 1
    cout << Solution().isMatch("aab", "c*a*b") << endl;                 // 1
    cout << Solution().isMatch("mississippi", "mis*is*p*.") << endl;    // 0
    cout << Solution().isMatch("aaa", "a*a") << endl;                   // 1
    cout << Solution().isMatch("aaa", "ab*a*c*a") << endl;              // 1
    cout << Solution().isMatch("a", "ab*") << endl;                     // 1
    cout << Solution().isMatch("a", ".*..a*") << endl;                  // 0
}
