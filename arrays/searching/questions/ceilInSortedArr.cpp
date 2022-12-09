/*
Given a sorted array and a value x, the ceiling of x is the smallest element in 
an array greater than or equal to x. Assume that the array is sorted in non-decreasing
order. Write an efficient function to find the ceiling of x.
*/

#include <iostream>

int findCeil(int* arr, int size, int value)
{
    int lb = 0;
    int ub = size - 1;

    if (value > arr[ub])
    {
        return -1;
    }

    int mid; 
    while (lb <= ub)
    {
        mid = lb + ((ub - lb) / 2); 
        if (arr[mid] == value)
        {
            return arr[mid];
        }
        else if (arr[mid] > value)
        {
            ub = mid - 1;
        }
        else
        {
            lb = mid + 1;
        }
    }

    if (arr[mid] < value)
    {
        return arr[mid + 1];
    }
    else
    {
        return arr[mid];
    }
}

int main()
{
    int totalElements{}, ceilVal{};

    std::cout << "Please enter the number of elements in your array" << std::endl;
    std::cin >> totalElements;
    
    int userArr[totalElements];

    std::cout << "Enter your array please" << std::endl;

    for (int i{0}; i < totalElements; i++)
    {
        std::cin >> userArr[i];
    }

    std::cout << 
    "Please enter the number whose ceil we can find in the array entered by you"
    << std::endl;

    std::cin >> ceilVal;

    int finalVal = findCeil(userArr, totalElements, ceilVal); 
    if (finalVal == -1)
    {
        std::cout << "There is no ceil for this value" << std::endl;
    }
    else
    {
        std::cout << "The ceil for this value is: " << finalVal << std::endl;
    }
    
    return 0;
}