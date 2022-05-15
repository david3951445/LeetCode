#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN & divisor == -1)
            return INT_MAX;

        int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;
        unsigned long dividend_ = labs(dividend), divisor_ = labs(divisor), ans = 0;
        while (dividend_ >= divisor_) {
            long a = divisor_, i = 1;
            while (a << 1 <= dividend_) {
                a <<= 1;
                i <<= 1;
            }
            dividend_ -= a;
            ans += i;
        }
        return sign*ans;
    }
};

int main() {
    Solution sol;
    int dividend = -2147483648, divisor = -1;
    cout << sol.divide(dividend, divisor) << endl;
}