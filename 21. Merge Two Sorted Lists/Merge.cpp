#include <iostream>
#include <vector>
#include <string>
#include "../include/LinkedList.h"
#include "../include/Print.h"
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

    // method 2
    ListNode* mergeTwoLists1(ListNode* list1, ListNode* list2) {
        ListNode *head = new ListNode(), *cur;

        for (cur = head; list1 && list2; cur = cur->next) {
            if (list1->val < list2->val) {
                cur->next = list1;
                list1 = list1->next;
            }
            else {
                cur->next = list2;
                list2 = list2->next;
            }
        }

        cur->next = list1 ? list1 : list2; // merge remain
        return head->next;
    }

    // method 3 (recursive)
    ListNode* mergeTwoLists2(ListNode* list1, ListNode* list2) {
        if (!(list1 && list2)) {
            return list1 ? list1 : list2;
        }
        
        if (list1->val < list2->val) {
            list1->next = mergeTwoLists2(list1->next, list2);
            return list1;
        }
        else {
            list2->next = mergeTwoLists2(list1, list2->next);
            return list2;
        }
    }
};

int main() {
    Solution sol;
    LinkedList list1({1, 2, 4});
    LinkedList list2({1, 3, 4});

    print(sol.mergeTwoLists2(list1.head, list2.head));
}