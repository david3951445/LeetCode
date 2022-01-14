#include "LinkedList.h"

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