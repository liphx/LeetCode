/*
 * 在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int merge(vector<int>& nums, int left, int mid, int right, vector<int>& tmp) {
        int ans = 0;
        int i = left, j = mid, index = 0;
        while (i < mid && j < right) {
            if (nums[i] <= nums[j]) {
                tmp[index++] = nums[i++];
            } else {
                tmp[index++] = nums[j++];
                ans += mid - i;
            }
        }
        while (i < mid)
            tmp[index++] = nums[i++];
        while (j < right)
            tmp[index++] = nums[j++];
        copy(tmp.begin(), tmp.begin() + right - left, nums.begin() + left);
        return ans;
    }

    int merge_sort(vector<int>& nums, int left, int right, vector<int>& tmp) {
        int ans = 0;
        if (right - left <= 1)
            return ans;
        int mid = left + (right - left) / 2;
        ans += merge_sort(nums, left, mid, tmp);
        ans += merge_sort(nums, mid, right, tmp);
        ans += merge(nums, left, mid, right, tmp);
        return ans;
    }

    /* 归并排序求逆序数 */
    int reversePairs(vector<int>& nums) {
        vector<int> tmp(nums.size());
        return merge_sort(nums, 0, nums.size(), tmp);
    }
};

int main() {}
