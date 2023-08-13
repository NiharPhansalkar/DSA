/*
https://www.geeksforgeeks.org/jump-search/
*/

#include <iostream>
#include <cmath>

int jumpSearch (int* arr, int size, int elementToFind)
{
    int prev = 0;
    int jumpBlock = sqrt(size);

    while (arr[jumpBlock] < elementToFind)
    {
        prev = jumpBlock;
        jumpBlock += sqrt(size);

        if (prev >= size)
        {
            return -1;
        }
    }

    while (arr[prev] < elementToFind)
    {
        prev++;

        if (prev == jumpBlock)
        {
            return -1;
        }
    }

    if (arr[prev] == elementToFind)
    {
        return prev;
    }

    return -1;
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
    std::cout << jumpSearch(userArr, numOfElements, findThis) << std::endl;
    
    return 0;
}