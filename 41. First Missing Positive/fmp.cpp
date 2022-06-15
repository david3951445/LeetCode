#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int a : nums) {
            while (a > 0 && a <= nums.size() && a != nums[a-1]) {
                swap(a, nums[a-1]);           
            }
        }
        int i = 0;
        while (i < nums.size() && nums[i] == i+1) {
            i++;
        }
        return i+1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2,8,1,11,3,5,7};
    cout << sol.firstMissingPositive(nums) << endl;
}