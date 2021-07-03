/*
 * 请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
 * 数值（按顺序）可以分成以下几个部分：
 *   1. 若干空格
 *   2. 一个 小数 或者 整数
 *   3. （可选）一个 'e' 或 'E' ，后面跟着一个 整数
 *   4. 若干空格
 * 小数（按顺序）可以分成以下几个部分：
 *   1. （可选）一个符号字符（'+' 或 '-'）
 *   2. 下述格式之一：
 *     1. 至少一位数字，后面跟着一个点 '.'
 *     2. 至少一位数字，后面跟着一个点 '.' ，后面再跟着至少一位数字
 *     3. 一个点 '.' ，后面跟着至少一位数字
 * 整数（按顺序）可以分成以下几个部分：
 *   1. （可选）一个符号字符（'+' 或 '-'）
 *   2. 至少一位数字
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        int i = 0;
        while (i < s.length() && s[i] == ' ')
            i++;
        
        int ii = i;
        if (isFloat(s, ii)) {
            i = ii;
            if (i <s.length() && (s[i] == 'e' || s[i] == 'E')) {
                i++;
                if (!isInt(s, i))
                    return false;
            }
        } else {
            if (!isInt(s, i))
                return false;
            if (i <s.length() && (s[i] == 'e' || s[i] == 'E')) {
                i++;
                if (!isInt(s, i))
                    return false;
            }
        }

        while (i < s.length() && s[i] == ' ')
            i++;
        return i == s.length();
    }

private:
    bool isInt(const string& s, int& i) {
        if (i < s.length() && (s[i] == '-' || s[i] == '+'))
            i++;
        int j = i;
        while (i < s.length() && s[i] >= '0' && s[i] <= '9')
            i++;
        if (j == i)
            return false;
        return true;
    }

    bool isFloat(const string& s, int& i) {
        if (i < s.length() && (s[i] == '-' || s[i] == '+'))
            i++;
        if (i < s.length() && s[i] == '.') {
            i++;
            int j = i;
            while (i < s.length() && s[i] >= '0' && s[i] <= '9')
                i++;
            if (j == i)
                return false;
            return true;
        }
        int j = i;
        while (i < s.length() && s[i] >= '0' && s[i] <= '9')
            i++;
        if (j == i)
            return false;
        if (i >= s.length() || s[i] != '.')
            return false;
        i++;
        while (i < s.length() && s[i] >= '0' && s[i] <= '9')
            i++;
        return true;
    }
};

int main()
{
    cout << Solution().isNumber("0") << endl;           // 1
    cout << Solution().isNumber("e") << endl;           // 0
    cout << Solution().isNumber(".") << endl;           // 0
    cout << Solution().isNumber("    .1  ") << endl;    // 1
}
