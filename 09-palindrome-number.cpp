#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        //to_string() c++11
        string s = to_string(x);
        int n = s.size();
        int i = 0, j = n - 1;
        while(i < j){
            if(s[i++] != s[j--])
                return false;
        }
        return true;
    }
};

/* 判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。 */

int main()
{
    cout << Solution().isPalindrome(121) << endl; //=>1
    cout << Solution().isPalindrome(-121) << endl; //=>0
    cout << Solution().isPalindrome(10) << endl; //=>0
    return 0;
}
