// Not a good approach since in it cannot handle repetition of values

#include <iostream>

void swap (int* a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void rearrangeArr(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > 0 && arr[i] != i)
        {
            int x = arr[i];

            // Swap the value at index i with whatever value might be at the
            // index = value
            // Eg. If my array is [-1,-1,6,4,2,3,5] then we will get to 6 and
            // swap 6 with arr[6] which is arr[i] with arr[arr[i]]
            swap(&arr[i], &arr[x]);
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

    rearrangeArr(userArr, sizeArr);

    for (int i = 0; i < sizeArr; i++)
    {
        std::cout << userArr[i] << " ";
    }

    std::cout << std::endl;
    
    return 0;
}