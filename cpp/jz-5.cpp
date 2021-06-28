/*
 * 请实现一个函数，把字符串 s 中的每个空格替换成"%20"。
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        string ans;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ')
                ans += "%20";
            else
                ans += s[i];
        }
        return ans;
    }
};

class Solution2 {
public:
    string replaceSpace(string s) {
        auto pos = s.find(' ');
        while (pos != string::npos) {
            s.replace(pos, 1, "%20");
            pos = s.find(" ", pos);
        }
        return s;
    }
};

int main()
{
    cout << Solution().replaceSpace("We are happy.") << endl;
    cout << Solution2().replaceSpace("We are happy.") << endl;
    // We%20are%20happy.
}
