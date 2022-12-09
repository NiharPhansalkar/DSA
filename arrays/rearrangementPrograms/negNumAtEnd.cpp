#include <iostream>

void rightShift(int* arr, int lb, int ub)
{
    int temp;
    for (int i = ub; i > lb; i--)
    {
        temp = arr[i];
        arr[i] = arr[i-1];
        arr[i-1] = temp;
    }
}

void rearrange(int* arr, int size)
{
    int lower{}, flag{};
    for (int i{0}; i < size; i++)
    {
        if ((arr[i] < 0) && flag == 0)
        {
            lower = i;
            flag = 1;
        }

        if (flag == 1 && (arr[i] > 0))
        {
            flag = 0;
            rightShift(arr, lower, i);
            i = lower;
        }
    }
}

int main()
{
    int numOfElements{};
    std::cout << "How many elements do you want?" << std::endl;
    std::cin >> numOfElements;
    int arr[numOfElements];

    for (int i{0}; i < numOfElements; i++)
    {
        std::cin >> arr[i];
    }

    rearrange(arr, numOfElements);

    for (int i{0}; i < numOfElements; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}