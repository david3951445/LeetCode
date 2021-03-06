#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> ans;

    /* Basic concept
     * Consider we have l left parentheses and r right parentheses in our hand. We are going to put they into a container.
     *      - l = r = n at the begining
     *      - "(" can be put arbitrarily, hence if there still have "(" in our hand (l > 0), we put it into container.
     *      - ")" can only be put when there is enough "(" in container, i.e.,  number of ")" more than "(" in our hand (r > l)
     */
    void backtracking(string st, int l, int r) {
        if (l == 0 && r == 0) {
            ans.push_back(st);
            return;
        }
        if (l > 0) {
            backtracking(st + "(", l - 1, r);
        }
        if (r > l) {
            backtracking(st + ")", l, r - 1);
        }
        return;
    }

    vector<string> generateParenthesis(int n) {
        backtracking("", n, n);
        return ans;
    }
};

void print(vector<string> vec) {
    cout << "vec : ";
    for (const auto i : vec)
        cout << i.c_str() << " ";
    cout << "\n\n";
}

int main() {
    Solution sol;
    print(sol.generateParenthesis(3));
}