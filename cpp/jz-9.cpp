/*
 * 用两个栈实现一个队列。
 * 队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。
 * 若队列中没有元素，deleteHead 操作返回 -1 。
 * 1 <= values <= 10000
 * 最多会对 appendTail、deleteHead 进行 10000 次调用
 */

#include <bits/stdc++.h>
using namespace std;

class CQueue {
public:
    stack<int> s1, s2;

    CQueue() {}
    
    void appendTail(int value) {
        s1.push(value);
    }
    
    int deleteHead() {
        int ret;
        if (!s2.empty()) {
            ret = s2.top();
            s2.pop();
        } else {
            if (s1.empty())
                return -1;
            while (s1.size() > 1) {
                s2.push(s1.top());
                s1.pop();
            }
            ret = s1.top();
            s1.pop();
        }
        return ret;
    }
};

int main()
{
    CQueue* obj = new CQueue();
    obj->appendTail(3);
    cout << obj->deleteHead() << endl; // 3
    cout << obj->deleteHead() << endl; // -1
}
