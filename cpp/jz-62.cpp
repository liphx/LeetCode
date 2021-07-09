/*
 * 0,1,···,n-1这n个数字排成一个圆圈，从数字0开始，每次从这个圆圈里删除第m个数字（删除后从下一个数字开始计数）。
 * 求出这个圆圈里剩下的最后一个数字。
 * 例如，0、1、2、3、4这5个数字组成一个圆圈，从数字0开始每次删除第3个数字，则删除的前4个数字依次是2、0、4、1，因此最后剩下的数字是3。
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;

class Solution {
public:
    int lastRemaining(int n, int m) {
        vector<int> remains(n);
        generate(remains.begin(), remains.end(), [i = 0] () mutable { return i++; });
        int current = 0;
        while (n > 1) {
            current = (current + m - 1) % n;
            remains.erase(remains.begin() + current);
            n--;
        }
        return remains[0];
    }
};

class Solution2 {
public:
    int lastRemaining(int n, int m) {
        list<int> remains(n);
        generate(remains.begin(), remains.end(), [i = 0] () mutable { return i++; });
        auto iter = remains.begin();
        int current = 0;
        while (n > 1) {
            int next = (current + m - 1) % n;
            advance(iter, next - current);
            current = next;
            remains.erase(iter++);
            n--;
        }
        return remains.front();
    }
};

int main()
{
    cout << Solution().lastRemaining(71989, 111059) << endl;    // 34203
    cout << Solution2().lastRemaining(71989, 111059) << endl;   // 34203
}
