/* For using template, code in Print.cpp is moved to Print.h
 */


// #include "LinkedList.h"
// #include "Print.h"

// template<typename T> void print(T vec) { 
//     cout << "vec : ";
//     for (const auto i : vec)
//         cout << i << " ";
//     cout << "\n\n";
// }

// template<> void print<ListNode>(ListNode *node) { // Print linkedlist by a head
//     cout << "linkedlist : ";
//     for (; node != nullptr; node = node->next) {
//         cout << node->val << " ";     
//     }
//     cout << endl;
// }

// void print(vector<char> vec) { 
//     cout << "vec : ";
//     for (const auto i : vec)
//         cout << i << " ";
//     cout << "\n\n";
// }

// void print(ListNode *node) { // Print linkedlist by a head
//     cout << "linkedlist : ";
//     for (; node != nullptr; node = node->next) {
//         cout << node->val << " ";     
//     }
//     cout << endl;
// }