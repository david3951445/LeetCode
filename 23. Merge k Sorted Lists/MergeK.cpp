#include <iostream>
#include <vector>
#include <queue>
#include "../include/LinkedList.h"
#include "../include/Print.h"
using namespace std;

class Solution {
    struct compare {
        bool operator() (struct ListNode *l1, struct ListNode *l2) {
            return l1->val > l2->val;
        }
    };
public:
    // priority queue
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head = new ListNode(), *cur = head;
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        for (const auto l : lists) {
            if(l) {
                pq.push(l);
            }
        }

        while(!pq.empty()) {
            ListNode *temp = pq.top();
            pq.pop();
            cur->next = temp;
            cur = cur->next;
            if(temp->next) {
                pq.push(temp->next);
            }
        }

        return head->next;
    }

    // use mergeTwoLists(), it's very slow.
    ListNode* mergeKLists1(vector<ListNode*>& lists) {
        if(lists.empty()) {
            return nullptr;
        }

        for (int i = 1; i < lists.size(); i++) {
            lists[i] = mergeTwoLists(lists[i - 1], lists[i]);
        }
        return lists[lists.size() - 1];
    }
private:
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
    LinkedList list1({1, 4, 5});
    LinkedList list2({1, 3, 4});
    LinkedList list3({2, 6});
    vector v = {list1.head, list2.head, list3.head};
    print(sol.mergeKLists(v));
}