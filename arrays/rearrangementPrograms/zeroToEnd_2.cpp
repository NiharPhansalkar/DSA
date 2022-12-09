/*
Partition the array with a pivot.
*/

#include <iostream>

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void pushToEnd(int* arr, int size)
{
    int pivot = 0;

    for (int i{0}; i < size; i++)
    {
        if (arr[i] != 0)
        {
            swap(&arr[pivot++], &arr[i]);
        }
    }
}

int main()
{
    int sizeArr;
    std::cout << "How many elements would you like?" << std::endl;
    std::cin >> sizeArr;
    int userArr[sizeArr];

    std::cout << "Please enter your elements" << std::endl;

    for (int i = 0; i < sizeArr; i++)
    {
        std::cin >> userArr[i];
    }

    pushToEnd(userArr, sizeArr);

    for (int i = 0; i < sizeArr; i++)
    {
        std::cout << userArr[i] << " ";
    }

    std::cout << std::endl;
    
    return 0;
}