#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int function() {
        
        return 0;
    }

    void print() {
        vector<int> vec;
        cout << "vec : ";
        for (int i : vec)
            cout << i << " ";
        cout << "\n\n";
    }
};

int main() {
    Solution sol;
    cout << sol.function() << endl;
}