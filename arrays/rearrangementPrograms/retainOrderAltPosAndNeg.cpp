/*
For this program, we will retain the order in which the elements are present.
*/

#include <iostream>

void rightShift(int* arr, int lb, int ub)
{
    // (lb - ub + 1) is no. of elements you will have
    for (int i = ub; i > lb; i--)
    {
        int temp = arr[i];
        arr[i] = arr[i-1];
        arr[i-1] = temp;
    }
}

void rearrange(int* arr, int size)
{
    int outOfPlace = 0;
    int forLoopVar = 0;
    
    while (forLoopVar < size)
    {
        while (forLoopVar < size)
        {
            if ((forLoopVar % 2 == 0) && arr[forLoopVar] >= 0)
            {
                outOfPlace = forLoopVar;
                break;
            }
            else if ((forLoopVar % 2 != 0) && arr[forLoopVar] < 0)
            {
                outOfPlace = forLoopVar;
                break;
            }
            forLoopVar++;
        }

        if (arr[outOfPlace] >= 0)
        {
            int i = outOfPlace + 1;
            while (arr[i] >= 0)
            {
                i++;
                if (i >= size)
                {
                    return;
                }
            }
            rightShift(arr, outOfPlace, i);
            forLoopVar += 2;
        }
        else if (arr[outOfPlace] < 0)
        {
            int i = outOfPlace + 1;
            while (arr[i] < 0)
            {
                i++;
                if (i >= size)
                {
                    return;
                }
            }
            rightShift(arr, outOfPlace, i);
            forLoopVar += 2;
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

    rearrange(userArr, sizeArr);

    for (int i = 0; i < sizeArr; i++)
    {
        std::cout << userArr[i] << " ";
    }

    std::cout << std::endl;
    
    return 0;
}