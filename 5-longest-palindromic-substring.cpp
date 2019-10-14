#include <iostream>
#include <cassert>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        // Manacher算法，时间空间复杂度均为O(n)
        if(s.length() <= 1)
            return s;
        string ret;
        // 预处理，假设原字符串中无'#'
        assert(s.find('#') == string::npos);
        string str = "#";
        for(int i = 0; i < s.length(); ++i)
            str = str + s[i] + '#';
        // 计算p数组
        int n = str.length();
        int p[n];
        int m = -1, mi = -1;
        for(int i = 0; i < n; ++i) {
            int r = 0;
            int j = i - 1, k = i + 1;
            while(j >= 0 && k < n) {
                if(str[j--] == str[k++])
                    r++;
                else
                    break;
                
            }
            p[i] = r;
            if(r > m){
                m = r;
                mi = i;
            }
        }
        // 无论m奇偶都适用
        for(int i = mi - (m - 1); i <= mi + (m - 1); i += 2)
            ret += str[i];
    
        return ret;
    }
};

/* 题目描述：给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。*/

int main()
{
    cout << Solution().longestPalindrome("babad") << endl; //=>bab
    cout << Solution().longestPalindrome("cbbd") << endl; //=>bb

    return 0;
}
