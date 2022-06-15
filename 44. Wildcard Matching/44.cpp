#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int len_s = s.size(), len_p = p.size();
        int i_s = 0, i_p = 0;
        int i_s_pre, i_p_pre = -1;
        while (i_s < len_s) {
            if (i_p < len_p && p[i_p] == '*') { // Discover '*', guess '*' == 0 character long string string first.
                i_s_pre = i_s;
                i_p_pre = i_p++;
            }
            else if (i_p < len_p && s[i_s] == p[i_p] || p[i_p] == '?') { // if char is matched
                i_s++;
                i_p++;
            }
            else if (i_p_pre >= 0) { // p has '*', and '*' != ''. Guess '*' == N character long string, where N = 1,2,... .
                i_s = ++i_s_pre;
                i_p = i_p_pre + 1;
            } else { // p has no '*'. Since i_s < len_s, not match.
                return false;
            }
        }
        
        while (i_p < len_p && p[i_p] == '*') { // case of s = ""
            i_p++;
        }
        return i_p == len_p;
    }
};

int main() {
    Solution sol;
    string s = "aa",  p = "*";
    cout << sol.isMatch(s, p) << endl;
}