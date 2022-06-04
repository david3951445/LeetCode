#include <iostream>
#include <vector>
#include <string>
#include "../include/Print.h"
using namespace std;

class Solution {
public:
    // method 1
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l < r) { // r - l > 0
            int m = (l + r)/2;
            // cout << "l,m,r: " << l << "," << m << "," << r << endl; 
            if (nums[l] < nums[m]) {
                if (target >= nums[l] && target < nums[m]) // here
                    r = m - 1;
                else // another side
                    l = m;
            }
            else if (nums[m] < nums[r]) {
                if (target > nums[m] && target <= nums[r]) // here
                    l = m + 1;
                else // another side
                    r = m;
            }
            else { // remain 2 elements (r - l == 1)
                if (target == nums[l])
                    return l;
                if (target == nums[r])
                    return r;
                return -1;
            }           
        }

        // r - l == 0
        if (target == nums[l])
            return l;

        return -1;
    }

    // method 2
    //     int search(vector<int>& nums, int target) {
    //     int l = 0, r = nums.size() - 1;
    //     while (l < r) {
    //         int m = (l + r)/2;
    //         if (target == nums[m])
    //             return m;
                    
    //         if (nums[l] <= nums[m]) {
    //             if (target >= nums[l] && target <= nums[m]) // here
    //                 r = m - 1;
    //             else // another side
    //                 l = m + 1;
    //         }
    //         else if (nums[m] <= nums[r]) {
    //             if (target >= nums[m] && target <= nums[r]) // here
    //                 l = m + 1;
    //             else // another side
    //                 r = m - 1;
    //         }     
    //     }

    //     if (target == nums[l])
    //         return l;

    //     return -1;
    // }
};

int main() {
    Solution sol;
    // vector<int> nums = {0,1,2,4,5,6,7};
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 3;
    cout << sol.search(nums, target) << endl;
}