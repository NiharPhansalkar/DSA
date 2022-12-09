#include <iostream>

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int sortingAlgo (int* arr, int lb, int ub)
{
    int pivot = lb;
    int i = lb;
    int j = ub;

    while (i <= j) 
    {
        if (arr[i] <= arr[pivot])
        {
            i++;
            continue;
        }
        else if (arr[j] > arr[pivot])
        {
            j--;
            continue;
        }
        swap(&arr[i], &arr[j]);
    }
    swap(&arr[j], &arr[pivot]);

    return j;
}

void quickSort(int* arr, int lb, int ub)
{
    if (lb < ub)
    {
        int piv = sortingAlgo(arr, lb, ub);
        quickSort(arr, lb, piv - 1);
        quickSort(arr, piv + 1, ub);
    }
}

void rearrange(int* arr, int size)
{
    int initPtr = 0;
    int finalPtr = size - 1;

    while (initPtr <= finalPtr)
    {
        if (initPtr == finalPtr)
        {
            std::cout << arr[finalPtr] << " ";
        }
        else
        {
            std::cout << arr[finalPtr] << " " << arr[initPtr] << " ";
        }
        initPtr++;
        finalPtr--;
    }

    std::cout << std::endl;
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

    quickSort(userArr, 0, numOfElements - 1);

    rearrange(userArr, numOfElements);

    return 0;
}