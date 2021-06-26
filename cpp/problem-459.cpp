/* 给定一个非空的字符串，判断它是否可以由它的一个子串重复多次构成。给定的字符串只含有小写英文字母，并且长度不超过10000。 */

#include <iostream>
using namespace std;

class Solution {
public:
    string f(string s, int c) {
        string ret;
        for (int i = 0; i < c; i++)
            ret += s;
        return ret;
    }

    bool repeatedSubstringPattern(string s) {
        int len = s.length();
        for (int i = 1; i < len; i++) {
            if (len % i == 0 && f(string(s, 0, i), len / i) == s)
                return true;
        }
        return false;
    }
};

int main()
{
    cout << (Solution().repeatedSubstringPattern("abab") ? "true" : "false") << endl;           //=> true
    cout << (Solution().repeatedSubstringPattern("aba") ? "true" : "false") << endl;            //=> false
    cout << (Solution().repeatedSubstringPattern("abcabcabcabc") ? "true" : "false") << endl;   //=> true

    return 0;
}
