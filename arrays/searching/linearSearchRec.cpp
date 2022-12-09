/*
There are three ways for us to perform linear search. All implementations
are below.
*/


// Method 1: Normal approach of comparing all elements in array with the element
// to be found
#include <iostream>

int search(int* arr, int size, int elementToFind)
{
    if (size == 0)
    {
        return -1;
    }

    if (arr[size] == elementToFind)
    {
        return size + 1;
    }
    else
    {
        return search(arr, size - 1, elementToFind);
    }
}

int main()
{
    int numOfElements{};
    std::cout << "How many elements would you like to have?" << std::endl;
    std::cin >> numOfElements;
    int userArr[numOfElements];

    std::cout << "Please enter your elements" << std::endl;

    for (int i{0}; i < numOfElements; i++)    
    {
        std::cin >> userArr[i]; 
    }

    std::cout << "Please enter the element to search for" << std::endl;
    int findThis;
    std::cin >> findThis;
    std::cout << search(userArr, numOfElements, findThis) << std::endl;
}