/*
 * 输入一个整数 n ，求1～n这n个整数的十进制表示中1出现的次数。
 * 例如，输入12，1～12这些整数中包含1 的数字有1、10、11和12，1一共出现了5次。
 * 1 <= n < 2^31
 */

#include <iostream>
using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        if (n < 10)
            return 1;
        if (isBase10(n)) // 10...0
            return 1 + countDigitOne(n - 1);
        if (n % 10 == 0) { // abc..0
            return countOne(n) + countDigitOne(n - 1);
        }

        // abc..x 
        int x = n % 10;
        return (x + 1) * countOne(n / 10) + countDigitOne(x) + countDigitOne(n - x - 1);
    }

private:
    bool isBase10(int n) {
        if (n < 10)
            return false;
        while (n >= 10) {
            if (n % 10 != 0)
                return false;
            n /= 10;
        }
        return n == 1;
    }

    int countOne(int n) {
        int ans = 0;
        while (n > 0) {
            if (n % 10 == 1)
                ans++;
            n /= 10;
        }
        return ans;
    }
};

int main()
{
    cout << Solution().countDigitOne(12) << endl;       // 5
    cout << Solution().countDigitOne(13) << endl;       // 6
    cout << Solution().countDigitOne(3184191) << endl;  // 2978524
    cout << Solution().countDigitOne(824883294) << endl;// 767944060
}
