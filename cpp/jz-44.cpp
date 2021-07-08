/*
 * 数字以 0123456789101112131415... 的格式序列化到一个字符序列中。
 * 在这个序列中，第5位（从下标0开始计数）是5，第13位是1，第19位是4，等等。
 * 请写一个函数，求任意第n位对应的数字。
 * 0 <= n < 2^31
 */

#include <iostream>
using namespace std;

long long nums[10];

class Solution {
public:
    int findNthDigit(int n) {
        getNums();
        int i = 1;
        for (; i < 10; i++) {
            if (n <= nums[i]) {
                break;
            }
        }
        int num = n - nums[i - 1];
        int start = 1;
        for (int j = 1; j < i; j++)
            start *= 10;
        if (start == 1)
            start = 0;

        start += num / i;
        int end = num % i;

        return to_string(start)[end] - '0';
    }

private:
    void getNums() {
        nums[0] = 0;
        nums[1] = 10;
        nums[2] = 90;
        for (int i = 3; i < 10; i++)
            nums[i] = nums[i - 1] * 10;

        for (int i = 2; i < 10; i++)
            nums[i] = nums[i - 1] + i * nums[i];
    }
};

int main()
{
    cout << Solution().findNthDigit(3) << endl;     // 3
    cout << Solution().findNthDigit(11) << endl;    // 0
    cout << Solution().findNthDigit(1000) << endl;  // 3
}
