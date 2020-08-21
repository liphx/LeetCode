/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。
*/

#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char ch : s) {
            switch (ch)
            {
                case '(':
                case '[':
                case '{':
                    st.push(ch);
                    break;
                case ')':
                    if (st.empty() || st.top() != '(')
                        return false;
                    st.pop();
                    break;
                case ']':
                    if (st.empty() || st.top() != '[')
                        return false;
                    st.pop();
                    break;
                case '}':
                    if (st.empty() || st.top() != '{')
                        return false;
                    st.pop();
                    break;
            }
        }
        if (st.empty())
            return true;
        return false;
    }
};

int main()
{
    cout << (Solution().isValid("") ? "true" : "false") << endl;        //=> true
    cout << (Solution().isValid("()") ? "true" : "false") << endl;      //=> true
    cout << (Solution().isValid("()[]{}") ? "true" : "false") << endl;  //=> true
    cout << (Solution().isValid("(]") ? "true" : "false") << endl;      //=> false
    cout << (Solution().isValid("([)]") ? "true" : "false") << endl;    //=> false
    cout << (Solution().isValid("{[]}") ? "true" : "false") << endl;    //=> true

    return 0;
}

