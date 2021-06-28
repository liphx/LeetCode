/*
 * 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
 * 输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。
 * 例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1。  
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minArray(vector<int>& numbers) {
        int i = 0, j = numbers.size() - 1;
        int ans = numbers[0];
        while (i < j) {
            int mid = i + (j - i) / 2;
            if (numbers[mid] > numbers[i])
                i = mid;
            else if (numbers[mid] == numbers[i])
                ans = min(ans, numbers[++i]);
            else
                j = mid;
        }
        return min(ans, numbers[i]);
    }
};

int main()
{
    vector<int> nums { 3, 4, 5, 1, 2 };
    cout << Solution().minArray(nums) << endl;  // 1

    vector<int> nums2 { 2, 2, 2, 0, 1 };
    cout << Solution().minArray(nums2) << endl; // 0

    vector<int> nums3 { 1, 2, 3 };
    cout << Solution().minArray(nums3) << endl; // 1

    vector<int> nums4 { 10, 1, 10, 10, 10 };
    cout << Solution().minArray(nums4) << endl; // 1
}
