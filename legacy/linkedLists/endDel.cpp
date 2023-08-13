#include <iostream>

class Node 
{
public:
    int data;
    Node* next;
};

Node* head;

void insert(int whatToInsert)
{
    Node* temp = new Node();
    temp = head;
    if (head == NULL)
    {
        Node* newNode = new Node();
        newNode->data = whatToInsert;
        newNode->next = NULL;
        head = newNode;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        Node* newNode = new Node();
        newNode->data = whatToInsert;
        newNode->next = NULL;
        temp->next = newNode;
    }
}

void print()
{
    Node* temp = head;
    while (temp != NULL)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    delete temp;
}

void endDelete()
{
    Node* iterator;
    Node* previous = nullptr;
    iterator = head;
    while (iterator->next != NULL)
    {
        previous = iterator;
        iterator = iterator->next;
    }
    if (iterator == head)
        head = NULL;
    else
        previous->next = NULL;
    delete iterator;
}

int main()
{
    head = NULL;
    int insertEnd{};
    int howMany{};
    std::cout << "How many numbers do you want to insert in the end?"
              << std::endl;
    std::cin >> howMany;
    for (int i{0}; i < howMany; i++)
    {
        std::cout << "Enter number to be inserted at the end" << std::endl;
        std::cin >> insertEnd;
        insert(insertEnd);
        print();
        std::cout << std::endl;
    }
    std::cout << std::endl;
    endDelete();
    print();
    std::cout << std::endl;
    delete head;
    return 0; 
}