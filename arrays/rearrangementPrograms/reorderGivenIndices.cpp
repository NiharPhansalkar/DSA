/*
Input:  arr[]   = [50, 40, 70, 60, 90]
        index[] = [3,  0,  4,  1,  2]
Output: arr[]   = [40, 60, 90, 50, 70]
        index[] = [0,  1,  2,  3, 4]
*/

#include <iostream>

void swap (int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void rearrange(int givenArr[], int* indices, int size)
{
    int start = 0;

    for (int i = 0; i < size; i++)
    {
        if (start < indices[i])
        {
            start++;
            continue;
        }

        swap(&givenArr[start], &givenArr[indices[i]]);
        start++;
    }
}

int main()
{
    // int arr[] = {50, 40, 70, 60, 90};
    int arr[] = {10, 11 , 12};
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    int userIndices[arrSize];

    std::cout << "The following is your array" << std::endl;
    for (int i = 0; i < arrSize; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Enter your arrangement order as indices" << std::endl;

    for (int i = 0; i < arrSize; i++)
    {
        std::cin >> userIndices[i];
    }
    std::cout << std::endl;

    rearrange(arr, userIndices, arrSize);

    std::cout << "The following is your array after rearrangement" << std::endl;

    for (int i = 0; i < arrSize; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}