#include <iostream>
#include <climits>

void findSmallestAndSecondSmallest(int* arr, int size)
{
    int first{}, second{}, temp;

    first = second = INT_MAX;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] < first)
        {
            temp = first;
            first = arr[i];
            second = temp;
        }
        else if (arr[i] > first && arr[i] < second)
        {
            second = arr[i];
        }
    }

    std::cout << first << " " << second << std::endl;
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

    findSmallestAndSecondSmallest(userArr, totalElements);
    
    return 0;
}