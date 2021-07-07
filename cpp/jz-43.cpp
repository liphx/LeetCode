/*
 * 输入一个整数 n ，求1～n这n个整数的十进制表示中1出现的次数。
 * 例如，输入12，1～12这些整数中包含1 的数字有1、10、11和12，1一共出现了5次。
 * 1 <= n < 2^31
 */

#include <iostream>
#include <cmath>
#include <unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<int, int> cache;
    
    int countDigitOne(int n) {
        if (cache.find(n) != cache.end())
            return cache[n];
        if (n == 0)
            return cache[n] = 0;
        if (n < 10)
            return cache[n] = 1;
        if (isBase10(n)) { // a0...0
            return cache[n] = countOne(getBase10(n)) + countDigitOne(n - 1);
        }
        
        // abc..
        int x = getBase10(n);
        int y = n - x;
        return cache[n] = (y + 1) * countOne(x) + countDigitOne(y) + countDigitOne(x - 1);
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
        return true;
    }

    int getBase10(int n) {
        int i = 0;
        while (n >= 10) {
            n /= 10;
            i++;
        }
        return n * pow(10, i);
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
    cout << Solution().countDigitOne(12) << endl;           // 5
    cout << Solution().countDigitOne(13) << endl;           // 6
    cout << Solution().countDigitOne(3184191) << endl;      // 2978524
    cout << Solution().countDigitOne(824883294) << endl;    // 767944060
    cout << Solution().countDigitOne(999999999) << endl;    // 900000000
}
