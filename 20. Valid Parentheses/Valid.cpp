#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        vector<char> vec;
        for (const char c : s) {
            if (vec.empty()) {
                vec.push_back(c);
                continue;
            }

            if (c - vec.back() > 0 && c - vec.back() <= 2) {
                vec.pop_back();
            }
            else {
                vec.push_back(c);
            }

            // print(vec);
        }

        if (vec.empty()) {
            return true;
        }
        else {
            return false;
        }
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