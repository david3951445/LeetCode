/* Print libarary
 * one line print that cout can't print
 * - functions
 *      - print()
 *      print vector<int>, vector<char> or LinkedList
 *          
 */

#ifndef PRINT_H
#define PRINT_H

#include <iostream>
#include <vector>
using namespace std;

// Print vector
void print(vector<int>);
void print(vector<char>);

// Print linkedlist by it's head
void print(ListNode*); 

#endif