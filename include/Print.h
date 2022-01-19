/* Print libarary
 * print vector, linkedlist, others (int, char, char[], string, ...)
 * - functions
 *      - print(T)
 *      Print T.
 */

#ifndef PRINT_H
#define PRINT_H

#include <iostream>
#include <vector>
#include "LinkedList.h"
// #include "Print.cpp"
using namespace std;

template<typename T> void print(T); // General print
template<typename T, size_t> void print(T*); // Print array
template<typename T> void print(vector<T>); // Print vector
template<> void print(ListNode*); // Print linkedlist by it's head

template<typename T> void print(T vec) {
    cout << vec << endl;
}

template<typename T, size_t N> void print(T (&arr)[N]) {
    cout << "array : ";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";  
    } 
    cout << endl;
}

template<typename T> void print(vector<T> vec) { 
    cout << "vector : ";
    for (const auto i : vec) {
        cout << i << " ";
    }
    cout << endl;
}

template<> void print(ListNode *node) { // Print linkedlist by a head
    cout << "linkedlist : ";
    for (; node != nullptr; node = node->next) {
        cout << node->val << " ";     
    }
    cout << endl;
}

#endif