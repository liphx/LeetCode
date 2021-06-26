/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.
Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
You may assume nums1 and nums2 cannot be both empty.
*/

#include <vector>
#include <cassert>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        assert(!nums1.empty() || !nums2.empty());
        vector<int> t;
        int i = 0, j = 0;
        for(; i < nums1.size() && j < nums2.size();) {
            if(nums1[i] < nums2[j])
                t.emplace_back(nums1[i++]);
            else
                t.emplace_back(nums2[j++]);
        }
        if(i < nums1.size()) {
            for(; i < nums1.size();)
                t.emplace_back(nums1[i++]);
        }
        if(j < nums2.size()) {
            for(; j < nums2.size();)
                t.emplace_back(nums2[j++]);
        }
        int n = t.size();
        if(n % 2 != 0)
            return t[n/2];
        else
            return (t[n/2-1] + t[n/2] + 0.0) / 2;
    }
};

int main()
{
    vector<int> nums1 { 1, 7, 11, 13, 29, 52 };
    vector<int> nums2 { 2, 7, 7, 12, 67, 102 };
    cout << Solution().findMedianSortedArrays(nums1, nums2) << endl;
    //=>11.5
    return 0;
}
