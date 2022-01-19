#include <iostream>
#include <vector>
// #include "../include/Print.h"

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int j = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[j] != nums[i]) {
                nums[++j] = nums[i];
            }
        }

        return j + 1; 
    }
};

int main() {
    Solution sol;
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};

    int k = sol.removeDuplicates(nums);
    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }
    
    cout << endl;
}