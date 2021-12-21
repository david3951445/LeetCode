#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string str = "";
        int l1 = strs.size();
        string base = strs[0];
        int i = 0, sum = 0;
        while (1) {        
            
            for (int j = 0; j < l1; j++) {
                sum += strs[j][i];
            }

            double d = sum/l1 - base[i];
            if (d > 0 || i == base.length()) {
                break;
            }

            sum = 0;
            str += base[i++];
        }

        return str;
    }
};

int main() {
    Solution sol;
    // vector<string> strs = {"flower", "flow", "flight"};
    vector<string> strs = {"a", "b"};
    cout << sol.longestCommonPrefix(strs).c_str() << endl;
    // string str = "";
    // cout << +str[0] << endl;
}