/*
A linked list is represented by a pointer to the first node of the linked list.
The first node is called the head. If the linked list is empty, then the value 
of the head points to NULL. 

Each node in a list consists of at least two parts: 

1) A Data Item (we can store integer, strings or any type of data).
2) Pointer (Or Reference) to the next node (connects one node to another) or
an address of another node
*/

#include <iostream>

class Node {
public:
    int data;
    Node* next;
};

int main()
{
    Node* head = new Node;
    Node* second = new Node;
    Node* third = new Node;

    head->data = 1;
    head->next = second; // Links first node with second node
    
    second->data = 2;
    head->next = third; // Links second node with third node

    head->data = 3;
    head->next = NULL; // Shows third node is the end

    /*
    Note that only the head is sufficient to represent 
    the whole list. We can traverse the complete 
    list by following the next pointers.
    */
    
    return 0;
}