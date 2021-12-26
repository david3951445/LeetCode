#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        string base = strs[0]; // chose first string as base (any is fine)

        for (int i = 0; i < base.length(); i++) {        
            for (int j = 0; j < strs.size(); j++) {
                if (base[i] != strs[j][i]) { 
                    return ans;
                }
            }

            ans += base[i];
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<string> strs = {"flower", "flow", "flight"};
    cout << sol.longestCommonPrefix(strs).c_str() << endl;
}