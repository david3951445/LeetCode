#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> Stack;

        for (const char c : s) {
            /* ASCII code
             * "(" : 40
             * ")" : 41
             * "[" : 91
             * "]" : 93
             * "{" : 123
             * "}" : 125
             */
            if (!Stack.empty() && c - Stack.top() > 0 && c - Stack.top() <= 2) {
                Stack.pop();
            }
            else {
                Stack.push(c);
            }
        }

        return Stack.empty();
    }

    void print(vector<char> vec) {
        cout << "vec : ";
        for (const auto i : vec)
            cout << i << " ";
        cout << "\n\n";
    }
};

int main() {
    Solution sol;
    string s = "{[()]}";
    cout << sol.isValid(s) << endl;
}