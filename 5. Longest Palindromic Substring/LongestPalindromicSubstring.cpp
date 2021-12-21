#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) { // simple version
        // case of s.size() <= 1
        int len = s.size();
        if (len <= 1)
            return s;
        
        int left = 0, right = 0; // left, right of max palindromic substring
        for (int i = 1; i < len; i++) {          
            search(s, left, right, i, i); // case of "abcba"
            search(s, left, right, i, i - 1); // case of "abba"
        }   

        string ans = "";
        for (int i = left; i <= right; i++)
            ans += s[i];

        return ans;
    }

    string longestPalindrome1(string s) {
        // case of s.size() <= 1
        int len = s.size();
        if (len <= 1)
            return s;
        
        int max = 0; // length of max palindromic substring
        int left = 0, right = 0; // left, right of max palindromic substring
      
        for (int i = 1; i < len; i++) {
            // case of "abcba"
            int j1 = 1;
            while(j1 <= i && s[i - j1] == s[i + j1])
                j1++;

            // case of "abba"
            int j2 = 1;
            while (j2 <= i && s[i - j2] == s[i + j2 - 1])
                j2++;
            
            if (2*j1 - 1 > max && 2*j1 - 1 > 2*j2 - 2) {
                max = 2*j1 - 1;
                left = i - (j1 - 1);
                right = i + (j1 - 1);
            }
            
            if (2*j2 - 2 > max) {
                max = 2*j2 - 2;
                left = i - (j2 - 1);
                right = i + (j2 - 2);    
            }
        }   

        string ans = "";
        for (int i = left; i <= right; i++) {
            ans += s[i];
        }

        return ans;
    }

private :
    void search(string s, int &left, int &right, int l, int r) {
        for(; l > 0 && s[l - 1] == s[r + 1]; l--, r++) {}

        if (r - l > right - left) {
            left = l;
            right = r;
        }
    }
};

int main () {
    string s = "aaaa";
    Solution solution;
    cout << solution.longestPalindrome(s) << endl;
}
