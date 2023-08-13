#include <iostream>

int binSearch(int* arr, int lb, int ub, int elementToFind)
{
    int mid = lb + ((ub - lb) / 2);
    if (lb > ub)
    {
        return -1;
    }
    else if (arr[mid] == elementToFind)
    {
        return mid + 1;
    }
    else if (arr[mid] > elementToFind)
    {
        return binSearch(arr, lb, mid - 1, elementToFind);
    }
    else
    {
        return binSearch(arr, mid + 1, ub, elementToFind);
    }
    return -1;

}

int expSearch(int* arr, int size, int numFind)
{
    int i {1};

    if (arr[0] == numFind)
    {
        return 0;
    }

    while (i < size && arr[i] <= numFind)
    {
        i *= 2;
    }

    return binSearch(arr, i/2, i, numFind);
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
    std::cout << expSearch(userArr, numOfElements, findThis) << std::endl;
    
    return 0;
}