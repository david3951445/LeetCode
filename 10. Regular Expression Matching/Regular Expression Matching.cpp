#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2] || (i && dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
                } else {
                    dp[i][j] = i && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                }
            }
        }
        return dp[m][n];
    }
};

int main() {
    Solution sol;
    string s = "", p = "";
    int n = 2, m = 3;
    vector<vector<int>> dp(n+1, vector<int>(m+1, 2));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }


    // cout << sol.isMatch(s, p) << endl;
}
