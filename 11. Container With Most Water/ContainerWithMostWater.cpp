#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1; // start point & end point of array
        int v1 = 0, v2; // volume
        while (i != j) {
            if (height[i] < height[j]) {
                v2 = height[i]*(j - i);
                i++;
            }
            else {
                v2 = height[j]*(j - i);
                j--;
            }

            if (v2 > v1) // store the max volume
                v1 = v2;
        }

        return v1;
    }
};

int main() {
    Solution s;
    vector<int> x = {4,3,2,1,4};
    cout << s.maxArea(x) << endl;
}
