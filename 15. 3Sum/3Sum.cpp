#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;

        if (nums.empty() || nums.size() < 3)
            return ans;

        sort(nums.begin(), nums.end(), less<int>()); // sort (increasing)

        for (int i = 0; i < nums.size() - 2; i++) {
            if (i == 0 || nums[i] != nums[i-1]) { // duplicated sol. judgement
                vector<int> subvec(nums.begin() + i + 1, nums.end());
                vector<vector<int>> two;

                // two sum
                int l = i + 1, r = nums.size() - 1;
                while (l < r) {
                    int sum = nums[i] + nums[l] + nums[r];
                    if (sum < 0 || (l > i + 1 && nums[l] == nums[l-1])) { // not solution || duplicated sol. judgement
                        l++;
                    }
                    else if (sum > 0 || (r < nums.size() - 1 && nums[r] == nums[r+1])) { // not solution || duplicated sol. judgement
                        r--;
                    }
                    else { // sum == 0
                        ans.push_back({nums[i], nums[l], nums[r]});
                        l++;
                        r--;
                    }                   
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    // vector<int> nums = {-1,0,1,2,-1,-4};
    // vector<int> nums = {0, 0, 0, 0};
    vector<int> nums = {-2,0,0,2,2};

    vector<vector<int>> ans = sol.threeSum(nums);
    for (vector<int> ans0 : ans) {
        for (int j : ans0) {
            cout << j << " ";
        }

        cout << endl;
    }
}
