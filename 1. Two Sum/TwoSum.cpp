#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    /* brust force
    vector<int> v;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i+1; j < nums.size(); j++) {
            if (nums[i] + nums[j] == target) {
                v.push_back(i);
                v.push_back(j);
                return v;
            }
        }
    }
    return v;/
    */
    
    // map
    vector<int> v;
    map<int, int> mp;    
    for (int i = 0; i < nums.size(); i++) {
        int k = target - nums[i];
        if (mp.find(k) != mp.end()) {
            v.push_back(mp[k]);
            v.push_back(i);
                return v;
        }
        else
            mp[nums[i]] = i;
    }
    return v;  
}

int main () {
	cout << "d" << endl; 
}
