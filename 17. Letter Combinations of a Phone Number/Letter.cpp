#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> mapping = {"","","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    void backtracking(vector<string> &ans, string cur, string digits, int index) {
        // changes of ans :
        // {""} -> {"ad"} -> {"ad", "ae"} -> {"ad", "ae", "af"} -> {"ad", "ae", "af", "bd"} -> ...
        if (index == digits.length()) { // index reach the end of digits
            ans.push_back(cur); // "ad", "ae", "af", ...
            return;
        }

        string letterOfdigits = mapping[digits[index] - '0']; // "abc" (begin = 0) or "def" (begin = 1)
        for (const auto i : letterOfdigits) { // "a", "b", "c" or "d", "e", "f"
            backtracking(ans, cur + i, digits, index + 1);
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.empty()) {
            return {};
        }
        
        backtracking(ans, "", digits, 0);
        
        return ans;
    }
};

int main() {
    string digits = "23";

    Solution sol;
    vector<string> vec = sol.letterCombinations(digits);

    // print result
    cout << "vec : ";
    for (const auto i : vec)
        cout << i << " ";
    cout << "\n\n";
}