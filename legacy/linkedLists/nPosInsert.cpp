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
    temp->data = whatToInsert;
    temp->next = head;
    head = temp;
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

void insertAtN(int whatToInsert, int pos)
{
    int counter{1};
    Node* temp = new Node();
    temp->next = head;
    while (counter != pos)
    {
        temp = temp->next;
        counter++;
    }
    Node* newNode = new Node();
    newNode->data = whatToInsert;
    newNode->next = temp->next;
    temp->next = newNode;
}

int main()
{
    head = NULL;
    int insertBeg{};
    int howMany{};
    std::cout << "How many numbers do you want to insert in the beginning?"
              << std::endl;
    std::cin >> howMany;
    for (int i{0}; i < howMany; i++)
    {
        std::cout << "Enter number to be inserted at the beginning" << std::endl;
        std::cin >> insertBeg;
        insert(insertBeg);
        print();
        std::cout << std::endl;
    }
    std::cout << std::endl;

    int posToInsert{};
    std::cout << "Enter number to be inserted" << std::endl;
    std::cin >> insertBeg;
    std::cout << "Enter what position to enter at" << std::endl;
    std::cin >> posToInsert;
    insertAtN(insertBeg, posToInsert);
    print();

    std::cout << std::endl;
    delete head;
    return 0; 
}