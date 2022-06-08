#include <iostream>
#include <vector>
#include <string>
#include "../include/Print.h"
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // block
        for (int i1 = 0; i1 < 3; i1++) {
            for (int i2 = 0; i2 < 3; i2++) {
                vector<int> count(9, 0);
                for (int i3 = 0; i3 < 3; i3++) {
                    for (int i4 = 0; i4 < 3; i4++) {
                        if (!valid(count, board[3*i1 + i3][3*i2 + i4]))
                            return false;
                    }
                }
            }
        }
        // dim1
        for (int i1 = 0; i1 < 9; i1++) {
            vector<int> count(9, 0);
            for (int i2 = 0; i2 < 9; i2++) {
                if (!valid(count, board[i2][i1]))
                    return false;
            }
        }
        // dim2
        for (int i1 = 0; i1 < 9; i1++) {
            vector<int> count(9, 0);
            for (int i2 = 0; i2 < 9; i2++) {
                if (!valid(count, board[i1][i2]))
                    return false;
            }
        }

        return true;
    }
private:
    bool valid(vector<int>& count, int num) {
        if (num != '.') {
            count[num - '0' - 1]++;
            if (count[num - '0' - 1] > 1)
                return false;
        }
        return true;
    }
};

int main() {
    Solution sol;
    vector<vector<char>> board {
        {'5','3','.','.','1','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    // print(board);
    cout << sol.isValidSudoku(board) << endl;
}