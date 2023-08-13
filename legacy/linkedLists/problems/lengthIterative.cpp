#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class Node
{
public:
    int data;
    Node* next;
};
Node* head;

void insertEnd(int insertionData)
{
    Node* newNode = new Node();
    newNode->data = insertionData;
    if (head == NULL)
    {
        newNode->next = NULL;
        head = newNode;
        return;
    }
    
    Node* iterator = new Node();
    iterator = head;
    while (iterator->next != NULL)
    {
        iterator = iterator->next;
    }
    iterator->next = newNode;
    newNode->next = NULL;
}

void printList()
{
    Node* iterator = new Node();
    iterator = head;
    while (iterator != NULL)
    {
        cout << iterator->data << " ";
        iterator = iterator->next;
    }
}

int giveLength()
{
    int counter{0};
    Node* iterator = new Node();
    iterator = head;
    while (iterator != NULL)
    {
        counter++;
        iterator = iterator->next;
    }
    return counter;
}

int main()
{
    head = NULL;
    int howMany;
    cout << "How many elements would you like to add?" << endl;
    cin >> howMany;

    cout << "Enter the numbers you would like to add" << endl;
    for (int i{0}; i < howMany; i++)
    {
        int insertionValue;
        cin >> insertionValue;
        insertEnd(insertionValue);
    }
    printList();
    cout << endl;
    cout << "The length of your list is: " << giveLength() << endl;
        
    return 0;
}