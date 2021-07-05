/*
 * 定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。
 */

#include <iostream>
#include <stack>
using namespace std;

class MinStack {
public:
    stack<int> s1, s2;

    MinStack() {}
    
    void push(int x) {
        s1.push(x);
        if (s2.empty() || x <= s2.top())
            s2.push(x);
    }
    
    void pop() {
        int x = s1.top();
        s1.pop();
        if (s2.top() == x)
            s2.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int min() {
        return s2.top();
    }
};

int main()
{
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.min() << endl; // -3
    minStack.pop();
    cout << minStack.top() << endl; // 0
    cout << minStack.min() << endl; // -2
}
