/*
验证给定的字符串是否可以解释为十进制数字。
*/

#include <iostream>
using namespace std;

class Solution {
public:
    // 需要考虑 0-9 e + - .
    bool isNumber(string s) {
        // 去掉首尾空格
        int i = -1, j = s.length();
        while (++i < j && s[i] == ' ');
        while (--j >= 0 && s[j] == ' ');
        s = string(s, i, j - i + 1);
        if (s.length() == 0)
            return false;
        
        // 符号位
        if (s[0] == '-' || s[0] == '+') 
            s = string(s, 1);
        if (s.length() == 0)
            return false;

        // 整数部分
        i = 0;
        while (i < s.length() && s[i] >= '0' && s[i] <= '9') {
            i++;
        }
        int flag_point = 0; // 小数点
        if (string(s, 0, i) == "") { // 整数部分为空
            if (i >= s.length() || s[i] != '.') 
                return false;
            if (i + 1 >= s.length() || (s[i + 1] < '0' || s[i+1] > '9'))
                return false;
        }

        if (i < s.length() && s[i] == '.') {
            flag_point = 1;
            i++;
        }
        if (flag_point) {
            while (i < s.length() && s[i] >= '0' && s[i] <= '9') 
                i++;
        }

        // 指数
        int flag_exp = 0;
        if (i < s.length() && s[i] == 'e') {
            flag_exp = 1;
            i++;
        }
        if (flag_exp) {
            if (i == s.length())
                return false;
            // e后面可以跟符号
            if (s[i] == '-' || s[i] == '+') 
                i++;
            if (i == s.length())
                return false;
            if (s[i] < '0' || s[i] > '9')
                return false;
            i++;
            while (i < s.length() && s[i] >= '0' && s[i] <= '9') 
                i++;
        }
        
        if (i != s.length())
            return false;

        return true;
    }
};

int main()
{
    cout << (Solution().isNumber("") ? "true" : "false") << endl;           //=>false
    cout << (Solution().isNumber("0") ? "true" : "false") << endl;          //=>true
    cout << (Solution().isNumber(" 0.1 ") ? "true" : "false") << endl;      //=>true
    cout << (Solution().isNumber("1 a") ? "true" : "false") << endl;        //=>false
    cout << (Solution().isNumber("2e10") ? "true" : "false") << endl;       //=>true
    cout << (Solution().isNumber(" -90e3   ") ? "true" : "false") << endl;  //=>true
    cout << (Solution().isNumber(" 1e") ? "true" : "false") << endl;        //=>false
    cout << (Solution().isNumber("e3") ? "true" : "false") << endl;         //=>false
    cout << (Solution().isNumber(" 6e-1") ? "true" : "false") << endl;      //=>true
    cout << (Solution().isNumber(" 99e2.5 ") ? "true" : "false") << endl;   //=>false
    cout << (Solution().isNumber("53.5e93") ? "true" : "false") << endl;    //=>true
    cout << (Solution().isNumber(" --6 ") ? "true" : "false") << endl;      //=>false
    cout << (Solution().isNumber("-+3") ? "true" : "false") << endl;        //=>false
    cout << (Solution().isNumber(".1") ? "true" : "false") << endl;         //=>true
    cout << (Solution().isNumber("01") ? "true" : "false") << endl;         //=>true
    cout << (Solution().isNumber("3.") ? "true" : "false") << endl;         //=>true
    cout << (Solution().isNumber(".") ? "true" : "false") << endl;          //=>false

    return 0;
}
