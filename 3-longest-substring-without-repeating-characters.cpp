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
/*
Given a string, find the length of the longest substring without repeating characters.
*/
int main()
{
    string str("abcabcbb");
    int ans = Solution().lengthOfLongestSubstring(str);
    cout << ans << endl;
    //3
    return 0;
}