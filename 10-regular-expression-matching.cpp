#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();
        bool first_match = (!s.empty() && (p[0] == s[0] || p[0] == '.'));
        if(p.length() >= 2 && p[1] == '*')
            return (isMatch(s, p.substr(2)) || (first_match && isMatch(s.substr(1), p)));
        else
            return first_match && isMatch(s.substr(1), p.substr(1));
    }
};

/*

给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。
'.' 匹配任意单个字符
'*' 匹配零个或多个前面的那一个元素
所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。
说明:
s 可能为空，且只包含从 a-z 的小写字母。
p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。

*/

int main()
{
    cout << Solution().isMatch("aa", "a") << endl; //=>0
    cout << Solution().isMatch("aa", "a*") << endl; //=>1
    cout << Solution().isMatch("ab", ".*") << endl; //=>1
    cout << Solution().isMatch("aab", "c*a*b") << endl; //=>1
    cout << Solution().isMatch("mississippi", "mis*is*p*.") << endl; //=>0

    return 0;
}
