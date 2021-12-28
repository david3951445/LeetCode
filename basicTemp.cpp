#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int function() {
        
        return 0;
    }

    // print a vector
    void print() {
        vector<int> vec;
        cout << "vec : ";
        for (const auto i : vec)
            cout << i << " ";
        cout << "\n\n";
    }
};

int main() {
    Solution sol;
    cout << sol.function() << endl;
}