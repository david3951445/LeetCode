#include "LinkedList.h"

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