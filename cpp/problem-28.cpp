/*
实现 strStr() 函数。
给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

对于本题而言，当 needle 是空字符串时我们应当返回 0 。
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle);
    }
};

int main()
{
    string haystack = "hello";
    string needle = "ll";
    cout << Solution().strStr(haystack, needle) << endl; //=>2

    return 0;
}
