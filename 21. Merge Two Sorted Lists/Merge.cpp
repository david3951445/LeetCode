#include <iostream>
#include <vector>
#include <string>
#include "LinkedList.h"
using namespace std;

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
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

        int i = 0;
        while (small->next != nullptr && i < 8) {
            cout << "small : " << small->val << endl;
            cout << "big : " << big->val << endl;

            i++;
            if (small->next->val < big->val) {
                small = small->next;
            }
            else {
                ListNode *temp = small->next;
                // merge
                small->next = big; 
                // switch
                small = big;
                big = temp;
            }
        }
        
        // merge remain
        small->next = big;

        return ans;
    }
};

int main() {
    Solution sol;
    LinkedList list1({1, 2, 4});
    LinkedList list2({1, 3, 4});

    printListNode(sol.mergeTwoLists(list1.head, list2.head));
}