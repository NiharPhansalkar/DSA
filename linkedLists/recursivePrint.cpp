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

void print(Node* iterator)
{
    if (iterator == NULL)
    {
        return;
    }
    std::cout << iterator->data << " ";
    print(iterator->next);
}

void printRev(Node* iterator)
{
    if (iterator == NULL)
    {
        return;
    }
    printRev(iterator->next);
    std::cout << iterator->data << " ";
}

int main()
{
    head = NULL;
    int insertEnd{};
    int howMany{};
    std::cout << "How many numbers do you want to insert in the end?"
              << std::endl;
    std::cin >> howMany;
    std::cout << "Enter numbers to be inserted at the end" << std::endl;
    for (int i{0}; i < howMany; i++)
    {
        std::cin >> insertEnd;
        insert(insertEnd);
    }
    print(head);
    std::cout << std::endl;
    printRev(head);
    std::cout << std::endl;
    delete head;
    return 0; 
}