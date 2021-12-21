#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        const int max = 2147483646;
        const int min = -2147483647;
        const double Max = max/10;
        int sign = 1, ans = 0, i;
        vector<int> temp;
        
        if (x == 0 || x > max || x < min)
            return 0;
            
        // x is negative
        if (x < 0) {
            x = -x;
            sign = -1;
        }

        // convert int to vector
        for(i = 0; x != 0; i++, x /= 10)
            temp.push_back(x % 10);

        // calculate inverse from vector
        for(int j = 0; j < i; j++) {
            if (ans > Max) {
                cout << "ger" << endl;
                return 0;
            }
                
            ans = ans*10 + temp[j];
        }

        return sign*ans;
    }
};

int main() {
    Solution s;
    // int x = 2147483647;
    int x = 2163847412;
    cout << s.reverse(x) << endl;
}
