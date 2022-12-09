#include <iostream>

class Node {
public:
    int data;
    Node* next;
};

void printList(Node* n)
{
    // Why does n->data != NULL not print the last value, while n != NULL does?
    // The answer is simple, for n->next, the pointer third, has the address
    // NULL, so it terminates without printing it.
    // But for n != NULL, n is the address of current node. When we come to third,
    // n is address of third, not the address of it's next. 
    while (n != NULL)
    {
        std::cout << n->data << " ";
        n = n->next;
    }
}

int main()
{
    Node* head = new Node;
    Node* second = new Node;
    Node* third = new Node;

    head->data = 1;
    head->next = second; // Links first node with second node
    
    second->data = 2;
    second->next = third; // Links second node with third node

    third->data = 3;
    third->next = NULL; // Shows third node is the end

    printList(head);

    return 0;
}