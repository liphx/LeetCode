/*
 * 在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 s 只包含小写字母。
 */

#include <iostream>
using namespace std;

class Solution {
public:
    char firstUniqChar(string s) {
        int count[26] { 0 };
        for (char ch: s)
            count[ch - 'a']++;

        for (char ch: s)
            if (count[ch - 'a'] == 1)
                return ch;

        return ' ';
    }
};

int main()
{
    cout << Solution().firstUniqChar("abaccdeff") << endl;  // 'b'
    cout << Solution().firstUniqChar("") << endl;           // ' '
    cout << Solution().firstUniqChar("leetcode") << endl;   // 'l'
}
