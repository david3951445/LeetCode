#include <iostream>
#include <vector>
#include <string>
#include "LinkedList.h"
using namespace std;

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;

        ListNode *small;
        ListNode *big, *ans;
        if (list1->val < list2->val) {
            small = list1;
            big = list2;
        }
        else {
            small = list2;
            big = list1;
        }
        ans = small;

        while (small->next != nullptr) {
            if (small->next->val < big->val) {
                small = small->next;
            }
            else {
                ListNode *temp = small->next;
                // merge big to small
                small->next = big; 
                // switch small & big
                small = big;
                big = temp;
            }
        }
             
        small->next = big; // merge remain

        return ans;
    }
};

int main() {
    Solution sol;
    LinkedList list1({1, 2, 4});
    LinkedList list2({1, 3, 4});

    printListNode(sol.mergeTwoLists(list1.head, list2.head));
}