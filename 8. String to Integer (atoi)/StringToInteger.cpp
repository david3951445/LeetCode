#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        const char Len = 10;
        // const double Max = INT_MAX/10;

        bool first = true, read = true, positive = true;
        vector<int> temp;
        char state = 0;

        int len = 0;
        // use finite-state machine to judge
        for (int i = 0; i < s.size() && read; i++) {
            switch (state) {
                case 0 : // case of ' ', '-', '+'        
                    switch (s[i]) {
                        case ' ' :
                            break;
                        case '+' :
                            state = 1;
                            break;
                        case '-' :
                            positive = false;
                            state = 1;
                            break;
                        case '0' :
                            state = 1;
                            break;
                        case '1' ... '9' :
                            temp.push_back(s[i] - '0');
                            len++;
                            state = 2;
                            break;
                        default :
                            read = false;
                            break;
                    }
                    break;

                case 1 : // deal the case of 00000123
                    switch (s[i]) {
                        case '0' :
                            break;
                        case '1' ... '9' :
                            temp.push_back(s[i] - '0');
                            len++;
                            state = 2;
                            break;
                        default :
                            read = false;
                            break;
                    }
                    break;

                case 2 : // number part
                    switch (s[i]) {
                        case '0' ... '9' :
                            temp.push_back(s[i] - '0');

                            len++;
                            break;
                        default :
                            read = false;
                            break;
                    }
                    break;
            }
        }

        // 11 digits number
        if (len > Len) {
            if (positive)
                return INT_MAX;
            else
                return INT_MIN;
        }

        // vector<int> to int
        int ans = 0;
        int max_dig = INT_MAX % 10, max = INT_MAX / 10;
        int min_dig = INT_MIN % 10, min = INT_MIN / 10;
        for (int i = 0; i < len; i++) {
            int dig = temp[i];
            if (! positive)
                dig = -dig;

            if (ans > max || (ans == max && dig > max_dig))
                    return INT_MAX;
            if (ans < min || (ans == min && dig < min_dig))
                    return INT_MIN;

            ans = ans*10 + dig;
        }

        return ans;
    }
};

int main() {
    Solution s;
    string str = "-42";
    cout << s.myAtoi(str) << endl;
}
