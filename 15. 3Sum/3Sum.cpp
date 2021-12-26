#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;

        for (int i = 0; i < nums.size(); i++) {
            vector<int> subvec(nums.begin() + i + 1, nums.end());
            vector<vector<int>> two = twoSum(subvec, -nums[i]);

            for (int j = 0; j < two.size(); j++) {              
                vector<int> three = {nums[i]};
                three.insert(three.end(), two[j].begin(), two[j].end());
                ans.push_back(three);
            }
        }

        return ans;
    }

    // twoSum() is changed from return index to return value
    vector<vector<int>> twoSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;    
        map<int, int> mp; 

        for (int i = 0; i < nums.size(); i++) {
            int k = target - nums[i];
            if (mp.find(k) != mp.end()) {
                vector<int> v;
                
                v.push_back(k);
                v.push_back(nums[i]);
                ans.push_back(v);
            }
            else
                mp[nums[i]] = i;
        }

        return ans;  
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-1,0,1,2,-1,-4};

    // vector<int> ans0 = sol.twoSum(nums, 1);
    // for (int i : ans0) {
    //     cout << i << " ";
    // }
    // cout << "\n\n";

    vector<vector<int>> ans = sol.threeSum(nums);
    // vector<vector<int>> ans = {{1, 2, 3}, {2, 3, 4}};
    for (vector<int> ans0 : ans) {
        for (int j : ans0) {
            cout << j << " ";
        }

        cout << endl;
    }
}
