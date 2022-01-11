/* Singly LinkedList libirary for leetcode problem.
 *
 * - it contains two class :
 *      - ListNode
 *      corresponding to ListNode Struct given by leetcode problem
 * 
 *      - LinkedList
 *      extension class for debugging
 *          - LinkedList() : initialize a linkedlist
 *          - print()      : print linkedlist
 * 
 * - example (19. Remove Nth Node From End of List):
 *      // example.cpp
 *      # include "LinkedList.h"
 *      
 *      class Solution {
 *      public:
 *          ListNode* removeNthFromEnd(ListNode* head, int n) {
 *          
 *          }
 *      }
 * 
 *      int main () { // debugging
 *          LinkedList list({2, 3, 4}); // init a linkedlist
 *          list.print(); // print it
 *          s.removeNthFromEnd(list.head, n) // put it into leetcode problem
 *          list.print(); // print it to check if the algorithm is correct
 *      }
 */
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <vector>
using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class LinkedList {
public:
    ListNode *head;
    // LinkedList() : head(0) {}
    LinkedList(ListNode* _head) : head(_head) {} // Use an existed head to initialize linkedlist;
    LinkedList(vector<int>); // Use vector to initialize linkedlist
    void print(); // Print linkedlist from head to end
};

LinkedList::LinkedList(vector<int> a) { 
    head = nullptr;
    for (int i = a.size() - 1; i >= 0; i--) {
        ListNode *new_node = new ListNode(a[i], head);
        head = new_node;
    }
}

void LinkedList::print() { 
    ListNode *node = head;
    cout << "linkedlist : ";
    for (; node != nullptr; node = node->next) {
        cout << node->val << " ";     
    }
    cout << endl;
}

#endif