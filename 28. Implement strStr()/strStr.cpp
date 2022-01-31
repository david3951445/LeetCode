#include <iostream>
#include <string>
#include <vector>
// #include <iterator>
#include "../include/Print.h"
using namespace std;

class Solution {
public:
    // brust method
    int strStr1(string haystack, string needle) { 
        int m = haystack.length();
        int n = needle.length();
        for (int i = 0; i <= m - n; i++) {
            int j = 0;
            for (; j < n; j++) {           
                if (haystack[i + j] != needle[j]) {
                    break;
                }
            }
            if (j == n) {
                return i;
            }
        }

        return -1;
    }

    // KMP algorithm method
    int strStr(string haystack, string needle) {
        int n = needle.length();
        if (n == 0) {
            return 0;
        }

        int m = haystack.length();
        vector<int> table = KMP(needle);
        for (int i = 0, j = 0; i < m; ) {
            // cout << "i: " << i << ", j: " << j << endl;
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            }
            else {
                j == 0 ? i++ : j = table[j-1];
            }

            if (j == n) {
                return i - n;
            }
        }

        return -1;
    }

    vector<int> KMP(string needle) {
        int n = needle.length();
        vector<int> table(n, 0);
        for (int l = 0, r = 1; r < n; ) {
            if (needle[l] == needle[r]) {
                table[r++] = ++l;
            }
            else {
                table[r] = 0;
                l == 0 ? r++ : l = table[l-1];
            }
            // print(table);
            // cout << "l: " << l << ", r: " << r << endl;
        }
        return table;
    }
};

int main() {
    Solution sol;
    string haystack = "abxabcabcaby", needle = "abcaby";
    string test = "";
    print(sol.KMP(test));
    cout << sol.strStr(haystack, needle) << endl;;
    // copy(int_vec.begin(), int_vec.end(), ostream_iterator<int>(cout, " "));
}