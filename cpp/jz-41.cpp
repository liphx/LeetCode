/*
 * 如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
 * 如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
 * 设计一个支持以下两种操作的数据结构：
 *   void addNum(int num) - 从数据流中添加一个整数到数据结构中。
 *   double findMedian() - 返回目前所有元素的中位数。
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;

class MedianFinder {
public:
    priority_queue<int> q1;
    priority_queue<int, vector<int>, greater<int>> q2;

    MedianFinder() {}
    
    void addNum(int num) {
        if (q1.size() <= q2.size())
            q1.push(num);
        else
            q2.push(num);

        if (!q1.empty() && !q2.empty() && q1.top() > q2.top()) {
            int x = q1.top();
            int y = q2.top();
            q1.pop();
            q2.pop();
            q1.push(y);
            q2.push(x);
        }
    }
    
    double findMedian() {
        if (q1.size() == q2.size())
            return (0.0 + q1.top() + q2.top()) / 2;
        return q1.top();
    }
};

int main()
{
    MedianFinder obj;
    obj.addNum(-1);
    cout << obj.findMedian() << endl; // -1
    obj.addNum(-2);
    cout << obj.findMedian() << endl; // -1.5
    obj.addNum(-3);
    cout << obj.findMedian() << endl; // -2
    obj.addNum(-4);
    cout << obj.findMedian() << endl; // -2.5
    obj.addNum(-5);
    cout << obj.findMedian() << endl; // -3
}
