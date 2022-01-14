/* Singly LinkedList libirary for leetcode problem.
 * - Struct
 *      - ListNode
 *      ListNode Struct given by leetcode problem
 * 
 * - Class
 *      - LinkedList
 *      extension class for debugging
 *          - LinkedList() : initialize a linkedlist
 *          - print()      : print linkedlist
 * 
 * - Function
 *      - printListNode()
 *      
 * 
 * - an example (19. Remove Nth Node From End of List)
 *      // example.cpp
 *      # include "LinkedList.h"
 *      ...
 *      class Solution {
 *      public:
 *          ListNode* removeNthFromEnd(ListNode* head, int n) {
 *          ...
 *          }
 *      }
 * 
 *      int main () { // debugging
 *          LinkedList list({2, 3, 4}); // init a linkedlist
 *          list.print(); // print it
 * 
 *          ListNode* head = s.removeNthFromEnd(list.head, n) // put it into leetcode problem
 * 
 *          LinkedList ANS(head);
 *          ANS.print(); // print it to check if the algorithm is correct
 *          printListNode(head); // print it to check if the algorithm is correct
 *      }
 */
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
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

void printListNode(ListNode*);

#endif