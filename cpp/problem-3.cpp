/* 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。*/

#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=-1;
        int re=0;
        int ar[256]={0};
        int n=s.size();
        while(i<n){
            if(j+1<n && ar[s[j+1]]==0){
                j++;
                ar[s[j]]=1;
            }
            else{
                while(s[i]!=s[j+1]){
                    ar[s[i]]=0;
                    i++;
                }
                j++;
                i++;              
            }
            re=max(re,j-i+1);
        }
        return re;
        
    }
};

int main()
{
    string str("abcabcbb");
    int ans = Solution().lengthOfLongestSubstring(str);
    cout << ans << endl;
    //3
    return 0;
}
