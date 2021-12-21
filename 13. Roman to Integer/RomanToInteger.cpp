#include <iostream>
#include <map>
using namespace std;

// class Solution {
// public:
    // // method 1
    // int romanToInt(string s) {
    //     int ans = 0, state = 0;
    //     char c1[] = {'I', 'X', 'C', 'M', '0'    };
    //     char c5[] = {'V', 'L', 'D', '0', '0'};

    //     for (int i = 0, i1 = 3; i1 != -1; i++) {
    //         char c = s[i];

    //         switch (state) {
    //             case 0:
    //                 ans *= 10;

    //                 if (c == c1[i1]) { // I
    //                     ans++;
    //                     state = 1;
    //                 }
    //                 else if (c == c5[i1]) { // V
    //                     ans += 5;
    //                     state = 2;
    //                 }
    //                 else {
    //                     i--;
    //                     state = 3;
    //                 }
    //                 break;

    //             case 1:
    //                 if (c == c1[i1]) { // I
    //                     ans++;
    //                 }
    //                 else if (c == c5[i1]) { // V
    //                     ans += 3;
    //                     state = 3;
    //                 }
    //                 else if (c == c1[i1 + 1]) { // X
    //                     ans += 8;
    //                     state = 3;
    //                 }
    //                 else {
    //                     i--;
    //                     state = 3;
    //                 }
    //                 break;

    //             case 2:
    //                 if (c == c1[i1]) {
    //                     ans++;
    //                 }
    //                 else {
    //                     i--;
    //                     state = 3;
    //                 }
    //                 break;

    //             case 3:
    //                 i--;
    //                 i1--;                 
    //                 state = 0;
    //                 break;                 
    //         }
    //         // cout << "i1 = " << i1 << ", "
    //             //  << "i = " << i << endl;
    //     }

    //     return ans;
    // }
// };

class Solution {
public:
    // method 2
    int romanToInt(string s) {
        int ans = 0;
        map<char, int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;

        for (int i = 0; i < s.length(); i++) {
            if (m[s[i]] < m[s[i+1]])
                ans -= m[s[i]];
            else
                ans += m[s[i]];
        }

        return ans;
    }
};

int main() {
    Solution sol;
    string s = "MCMXCIV";
    cout << sol.romanToInt(s) << endl;

    // cout << m['C'] << endl;

}