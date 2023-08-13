#include <iostream>

class Node {
public:
    int data;
    Node* next;
    int flag = 0;
};
Node* head;

void insert(int key) {
    Node* iterator = new Node();

    if (head == nullptr)
    {
        iterator->data = key;
        iterator->next = nullptr;
        head = iterator;
        return;
    }

    iterator = head;

    while (iterator->next != nullptr)
    {
        iterator = iterator->next;
    }
    Node* newNode = new Node();
    newNode->data = key;
    
    iterator->next = newNode;
    newNode->next = nullptr;
}

void checkLoop() {
    Node* iterator = new Node();

    iterator = head;

    while (iterator->next != nullptr)
    {
        if (iterator->flag == 1)
        {
            std::cout << "There is a loop in this linked list" << std::endl;
            return;
        }
        iterator->flag = 1;
        iterator = iterator->next;
    }

    std::cout << "There is no loop in this linked list" << std::endl;
}

void printList() {
    Node* iterator = head;
    while (iterator != nullptr)
    {
        std::cout << iterator->data << " ";
        iterator = iterator->next;
    }
    std::cout << std::endl;
}

int main()
{
    head = nullptr;
    
    insert(20);
    insert(4);
    insert(15);
    insert(10);
    printList();

    head->next->next->next->next = head;

    checkLoop();
    
    return 0;
}