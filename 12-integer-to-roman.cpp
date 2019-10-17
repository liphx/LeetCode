#include <iostream>
#include <string>
#include <utility>
#include <cassert>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        assert(num > 0 && num < 4000);
        string ret;
        pair<int, string> p[] { 
            {1, "I"},
            {4, "IV"},
            {5, "V"},
            {9, "IX"},
            {10, "X"},
            {40, "XL"},
            {50, "L"},
            {90, "XC"},
            {100, "C"},
            {400, "CD"},
            {500, "D"},
            {900, "CM"},
            {1000, "M"}
        };
        int n = sizeof(p) / sizeof(p[0]);
        while(n > 0){
            while(num >= p[n - 1].first){
                ret += p[n - 1].second;
                num -= p[n - 1].first;
            }
            --n;
        }
        
        return ret;
    }
};

/*

罗马数字包含以下七种字符： I， V， X， L，C，D 和 M。
字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。
通常情况下，罗马数字中小的数字在大的数字的右边。
但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。
同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：
I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
给定一个整数，将其转为罗马数字。输入确保在 1 到 3999 的范围内。

*/

int main()
{   
    cout << string(3, 'I') << endl;
    cout << Solution().intToRoman(3) << endl; //=>III
    cout << Solution().intToRoman(4) << endl; //=>IV
    cout << Solution().intToRoman(9) << endl; //=>IX
    cout << Solution().intToRoman(58) << endl; //=>LVIII
    cout << Solution().intToRoman(1994) << endl; //=>MCMXCIV

    return 0;
}
