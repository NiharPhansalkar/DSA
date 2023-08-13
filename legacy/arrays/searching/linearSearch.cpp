/*
There are three ways for us to perform linear search. All implementations
are below.
*/


// Method 1: Normal approach of comparing all elements in array with the element
// to be found
#include <iostream>

int search(int* arr, int size, int elementToFind)
{
    for (int i{0}; i < size; i++)
    {
        if (arr[i] == elementToFind)
        {
            return i+1;
        }
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
    std::cout << search(userArr, numOfElements, findThis) << std::endl;
}

/* Method 2: A method that reduces the worst case time complexity by a bit.
#include <iostream>

int search(int* arr, int size, int elementToFind)
{
    int left = 0;
    int right = size - 1;

    while (left <= right)
    {
        if (arr[left] == elementToFind)
        {
            return left + 1;
        }

        if (arr[right] == elementToFind)
        {
            return right + 1;
        }

        left++;
        right--;
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
    std::cout << search(userArr, numOfElements, findThis) << std::endl;
}
*/

/* Method 3: The recursive approach
#include <iostream>

int search(int* arr, int size, int elementToFind)
{
    if (size == 0)
    {
        return -1;
    }
    else if (size > 0 && (arr[size] == elementToFind))
    {
        return size + 1;
    }
    else
    {
        int ans = search(arr, size - 1, elementToFind);
        return ans;
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
    std::cout << search(userArr, numOfElements - 1, findThis) << std::endl;
}
*/