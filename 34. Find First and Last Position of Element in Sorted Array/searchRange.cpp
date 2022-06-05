#include <iostream>
#include <vector>
#include <string>
#include "../include/Print.h"

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, m = (l + r)/2;

        // nums.size() >= 0
        if (r == -1) { // []
            return {-1,-1};
        }
        if (r == 0) { // [a]
            if (target == nums[m]) // [a], a
                return {0,0};
            else // [a], b
                return {-1,-1}; 
        }

        // nums.size() >= 2
        while (target != nums[m]) {
            if (l >= r) {
                return {-1,-1}; 
            }   

            if (target < nums[m]) {
                r = m - 1;
            }
            else { // target < nums[m]
                l = m + 1;
            }
            m = (l + r)/2;
        }

        int r_ = m, l_ = m; // nums is seperated to two part

        while (l <= r_) {
            m = (l + r_)/2; // left part
            if (target == nums[m]) {
                r_ = m - 1;
            }
            else { // target > nums[m]
                l = m + 1;
            }
        }

        while (l_ <= r) {
            m = (l_ + r)/2; // right part
            if (target == nums[m]) {
                l_ = m + 1;
            }
            else { // target < nums[m]
                r = m - 1;
            }
        }

        return {l,r};
    }
};

int main() {
    Solution sol;
    // vector<int> nums = {0,1,2,4,5,5,6,7};
    vector<int> nums = {1};
    int target = 1;
    print(sol.searchRange(nums, target));
}