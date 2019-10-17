#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int ret = 0;
        while(i < j){
            if(height[i] > height[j]){
                ret = max(ret, (j - i) * height[j]);
                j--;
            }
            else{
                ret = max(ret, (j - i) * height[i]);
                i++;
            }
        }
        return ret;
    }
};

/*

给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。
在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。
找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
说明：你不能倾斜容器，且 n 的值至少为 2。

*/

int main()
{
    vector<int> height { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
    cout << Solution().maxArea(height) << endl; //=>49

    return 0;
}
