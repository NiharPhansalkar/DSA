#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class Node
{
public:
    int data;
    Node* next;
};

Node* head;

void Insert(int insertData)
{
    Node* newNode = new Node();
    if (head == NULL)
    {
        newNode->data = insertData;
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
    newNode->data = insertData;
    newNode->next = NULL;
    iterator->next = newNode;
}

void printLL()
{
    Node* iterator = new Node();
    iterator = head;

    while (iterator != NULL)
    {
        cout << iterator->data << " ";
        iterator = iterator->next;
    }
}

void deleteByValue(int value)
{
    Node* iterator = new Node();
    Node* previousNode = new Node();
    iterator = head;
    while (iterator->data != value)
    {
        previousNode = iterator;
        iterator = iterator->next;
    }
    previousNode->next = iterator->next;
    delete(iterator);
}

int main()
{
    int nums, userData;
    head = NULL;
    cout << "How many numbers would you like to add?" << endl;
    cin >> nums;
    cout << "Enter your numbers" << endl;
    for (int i {0}; i < nums; i++)
    {
        cin >> userData;
        Insert(userData);
    }
    printLL();
    cout << endl;

    int deleteVal;
    cout << "Which value would you like to delete?" << endl;
    cin >> deleteVal;
    deleteByValue(deleteVal);
    printLL();
    cout << endl;

    return 0;
}