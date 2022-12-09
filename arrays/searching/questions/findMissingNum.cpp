/*
Given an array arr[] of size N-1 with integers in the range of [1, N], 
the task is to find the missing number from the first N integers.
*/


#include <iostream>

int sumOfnNos(int size)
{
    int sum{0};

    for (int i{0}; i <= size + 1; i++)
    {
        sum += i;
    }

    return sum;
}

int missingNum(int* arr, int size)
{
    int totSum = sumOfnNos(size);
    int currSum{};

    for (int i{0}; i < size; i++)
    {
        currSum += arr[i];
    }

    return (totSum - currSum);

}

int main()
{
    int totalElements{};

    std::cout << "Please enter the number of elements you would like" << std::endl;
    std::cin >> totalElements;

    int userArr[totalElements];
    std::cout << "Please enter your elements" << std::endl;

    for (int i {0}; i < totalElements; i++)
    {
        std::cin >> userArr[i];
    }

    std::cout << "The missing num is: " << missingNum(userArr, totalElements);
    std::cout << std::endl;
    
    return 0;
}