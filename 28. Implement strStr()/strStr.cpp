#include <iostream>
#include <string>
#include <vector>
// #include <iterator>
#include "../include/Print.h"
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle);
    }
};

template <typename T>
void Print(T vec) { 
    cout << "vec : ";
    for (const auto i : vec)
        cout << i << " ";
    cout << "\n\n";
}

int main() {
    Solution sol;
    vector<int> int_vec = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    vector<char> vec = { 'g', 'i' };
    char a[] = {'1', '2'};
    int b[] = {1, 3, 5};
    print(b);
    print(vec);
    // copy(int_vec.begin(), int_vec.end(), ostream_iterator<int>(cout, " "));
}