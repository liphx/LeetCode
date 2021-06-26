/* 编写一个函数来查找字符串数组中的最长公共前缀。如果不存在公共前缀，返回空字符串 ""。 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())
            return "";
        string ret = strs[0];
        for(string str : strs){
            string s;
            int i = 0, j = 0, m = ret.length(), n = str.length();
            while(i  < m && j < n){
                if(ret[i] == str[j]){
                    s += ret[i];
                    ++i;
                    ++j;
                }
                else{
                    break;
                }
            }
            ret = s;
        }
        return ret;
    }
};

int main()
{
    vector<string> strs1 { "flower", "flow", "flight" }, strs2 { "dog", "racecar", "car" };
    cout << Solution().longestCommonPrefix(strs1) << endl; //=>"fl"
    cout << Solution().longestCommonPrefix(strs2) << endl; //=>""

    return 0;
}
