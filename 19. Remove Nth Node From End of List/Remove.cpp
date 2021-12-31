#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // method 1
        ListNode *target_pre = head;

        int len = 0;
        for (ListNode *node = head; node != nullptr; node = node->next, len++) {    
            if (len > n) {
                target_pre = target_pre->next;
            }
        }

        if (n == len) {
            return head->next;
        }

        target_pre->next = target_pre->next->next;
        
        return head;

        // method 2
        // ListNode *ans = new ListNode(0, head);
        // ListNode *node = ans;
        // ListNode *target_pre = ans;

        // for (int len = 0; len <= n; node = node->next, len++) {          
        // }

        // for (; node != nullptr; node = node->next, target_pre = target_pre->next) {      
        // }

        // target_pre->next = target_pre->next->next;

        // return ans->next;
    }
};

void print(ListNode* node) {
    cout << "linkedlist : ";
    for (; node != nullptr; node = node->next) {
        cout << node->val << " ";     
    }
    cout << endl;
}

int main() {
    Solution sol;
    int n = 1;

    // init
    ListNode *head = nullptr;
    for (int i = 1; i <= 1; i++) {
        ListNode *new_node = new ListNode(i, head);
        head = new_node;
    } 

    print(head);
    print(sol.removeNthFromEnd(head, n));
}