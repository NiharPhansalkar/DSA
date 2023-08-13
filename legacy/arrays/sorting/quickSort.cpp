#include <iostream>

void swap (int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int* arr, int lb, int ub)
{
    int pivot = arr[lb];

    int start = lb;
    int end = ub;

    while (start <= end)
    {
        if (arr[start] <= pivot)
        {
            start++;
            continue;
        }
        if (arr[end] > pivot)
        {
            end--;
            continue;
        }
        swap(&arr[start], &arr[end]);
    }
    swap(&arr[end], &arr[lb]);

    return end;
}

void quickSort(int* arr, int lb, int ub)
{
    if (lb < ub)
    {
        int loc = partition(arr, lb, ub);
        quickSort(arr, lb, loc - 1);
        quickSort(arr, loc + 1, ub);
    }
}

int main()
{
    int arrSize;
    std::cout << "How many elements?\n";
    std::cin >> arrSize;

    int userArr[arrSize];
    std::cout << "Enter your elements?\n";
    
    for (int i = 0; i < arrSize; i++)
    {
        std::cin >> userArr[i];
    }

    quickSort(userArr, 0, arrSize-1);

    std::cout << std::endl;
    for (int i = 0; i < arrSize; i++)
    {
        std::cout << userArr[i] << std::endl;
    }
    
    return 0;
}