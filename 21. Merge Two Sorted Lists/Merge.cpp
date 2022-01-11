#include <iostream>
#include <vector>
#include <string>
#include "LinkedList.h"
using namespace std;

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        return list1;
    }
};

int main() {
    Solution sol;
    LinkedList list1({1, 2, 4});
    LinkedList list2({1, 3, 4});

    LinkedList listAns(sol.mergeTwoLists(list1.head, list1.head));
    listAns.print();
}