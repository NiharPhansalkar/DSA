#include <iostream>

void modifiedBinSearch(int* arr, int lb, int ub)
{
    while (lb <= ub)
    {
        int mid = lb + (ub - lb) / 2;

        if (arr[mid-1] > arr[mid] && arr[mid+1] > arr[mid])
        {
            std::cout << "Smallest elements is: " << arr[mid] << std::endl; 
            break;
        }
        else if (arr[mid] > arr[ub])
        {
            lb = mid+1;
        }
        else
        {
            ub = mid-1;
        }
    }
}

int main()
{
    int numElements;
    std::cout << "How many elements would you like?" << std::endl;
    std::cin >> numElements;

    int inputArr[numElements];

    std::cout << "Please input your elements" << std::endl;

    for (int i = 0; i < numElements; i++)
    {
        std::cin >> inputArr[i];
    }

    modifiedBinSearch(inputArr, 0, numElements-1);
    
    return 0;
}