/*
 * 输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。
 * 为简单起见，标点符号和普通字母一样处理。例如输入字符串"I am a student. "，则输出"student. a am I"。
 * 无空格字符构成一个单词。
 * 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
 * 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        strip(s);
        string str;
        str.resize(s.length());
        int i = 0, j = s.length() - 1;
        while (j >= 0) {
            while (j >= 0 && s[j] != ' ')
                j--;
            int n = j == 0 ? 0 : j + 1;
            while (n < s.length() && s[n] != ' ')
                str[i++] = s[n++];
            if (i < str.length())
                str[i++] = ' ';
            j--;
        }
        return str;
    }

private:
    void strip(string& s) {
        int i = 0, j = 0, n = s.length();
        while (j < n) {
            if (i != 0)
                s[i++] = ' ';
            while (j < n && s[j] == ' ')
                j++;
            while (j < n && s[j] != ' ') {
                if (i != j)
                    s[i] = s[j];
                i++;
                j++;
            }
            while (j < n && s[j] == ' ')
                j++;
        }
        s.resize(i);
    }
};

int main()
{
    cout << Solution().reverseWords("  the sky is   blue  ") << endl;
    // blue is sky the
}
