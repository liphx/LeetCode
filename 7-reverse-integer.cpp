#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long t = x;
        int f = (t >= 0 ? 1 : -1);
        t = (t >= 0 ? t : -t);
        long long re = t % 10;
        t /= 10;
        while(t > 9){
            re *= 10;
            re += (t % 10);
            t /= 10;
        }
        if(t > 0)
            re = f * (re * 10 + t);
        if(re > INT_MAX || re < INT_MIN)
            return 0;
        return re;
    }
};

/* 给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。*/

int main()
{
    cout << Solution().reverse(123) << endl; //=>321
    cout << Solution().reverse(-123) << endl; //=>-321
    cout << Solution().reverse(120) << endl; //=>21

    return 0;
}
