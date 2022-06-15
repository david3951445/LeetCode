#include <iostream>
#include <vector>
#include <string>
#include "../include/Print.h"
using namespace std;

class Solution {
public:
    /* Using recurssive since this problem can be split to subproblem.
     *
     * Let nums = {1,2,...,N}, N arrays "NUMS_i" is obtain by swap(nums[0], nums[i]), where i = 0,2,..,N-1.
     * NUMS_i[2~N] are the subproblems.
     * Let nums = NUMS_i[2~N] do again and again until nums = {}.
     */

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans {};
        vector<int> cur {};
        backtrack(ans, cur, nums);
        return ans;
    }

private:
    void backtrack(vector<vector<int>>& ans, vector<int>& cur, vector<int>& nums) {
        if (nums.empty()) {
            ans.push_back(cur);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            cur.push_back(nums[i]);
            swap(nums[i], nums[0]);
            vector<int> sub_nums(nums.begin()+1, nums.end());
            backtrack(ans, cur, sub_nums);
            cur.pop_back();
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums {1,2,3};
    print(sol.permute(nums));
}