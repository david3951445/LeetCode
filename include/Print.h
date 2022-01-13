/* Print libarary
 * one line print that cout can't print
 * - functions
 *      - print()
 *      print vector<int>, vector<char> or LinkedList
 *          
 */
#include <iostream>
#include "LinkedList.h"
using namespace std;

// Print vector
void print(vector<int>);
void print(vector<char>);

// Print linkedlist by it's head
void print(ListNode*); 


void print(vector<int> vec) { 
    cout << "vec : ";
    for (const auto i : vec)
        cout << i << " ";
    cout << "\n\n";
}

void print(vector<char> vec) { 
    cout << "vec : ";
    for (const auto i : vec)
        cout << i << " ";
    cout << "\n\n";
}

void print(ListNode *node) { // Print linkedlist by a head
    cout << "linkedlist : ";
    for (; node != nullptr; node = node->next) {
        cout << node->val << " ";     
    }
    cout << endl;
}