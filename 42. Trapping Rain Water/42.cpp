#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int l = 1, r = height.size()-2; // since both sides can never be filled with water
        int l_pre = height[0], r_pre = height[r+1]; // store "wall" on both sides
        int res = 0; // total restore

        while (l <= r) {
            if (l_pre < r_pre) { // gaurantee from low wall to high wall
                while (l <= r && height[l] <= l_pre) { // if the wall is lower than reference wall, water can be filled
                    res += (l_pre - height[l++]); // calculate capacity
                    // cout << "l:" << res << endl;
                }
                l_pre = height[l++]; // find higher wall -> set as new reference wall
                // cout << "l_pre:" << l_pre << endl;
                // cout << "l-1:" << l-1 << endl;
            }
            else { // right process is the same
                while (l <= r && height[r] <= r_pre) {
                    res += (r_pre - height[r--]);
                    // cout << "r:" << res << endl;;
                }
                r_pre = height[r--];
                // cout << "r_pre:" << r_pre << endl; 
                // cout << "r+1:" << r+1 << endl;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    // vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> height = {2,0,2};
    cout << sol.trap(height) << endl;
}