#include <iostream>
#include <climits>

void mergeSort(int* arr, int lb, int ub, int mid)
{
    int lSize = mid - lb + 1;
    int rSize = ub - mid;

    int lArr[lSize + 1];
    int rArr[rSize + 1];

    lArr[lSize] = rArr[rSize] = INT_MAX;

    for (int i = 0; i < lSize; i++)
    {
        lArr[i] = arr[i + lb];
    }
    for (int i = 0; i < rSize; i++)
    {
        rArr[i] = arr[i + mid + 1];
    }

    int l_i = 0, r_i = 0;

    for (int i = lb; i < ub; i++)
    {
        if (lArr[l_i] >= rArr[r_i])
        {   
            arr[i] = rArr[r_i];
            r_i++;
        }
        else
        {
            arr[i] = lArr[l_i];
            l_i++;
        }
    }
}

void sortArr(int* arr, int lb, int ub)
{
    if (lb == ub)
    {
        return;
    }
    int mid = lb + (ub - lb) / 2;
    sortArr(arr, lb, mid);
    sortArr(arr, mid+1, ub);
    mergeSort(arr, lb, ub, mid);
}

void rearrange(int* arr, int size)
{
    int tempArr[size];
    for (int i = 0; i < size; i++)
    {
        tempArr[i] = arr[i];
    }

    sortArr(tempArr, 0, size-1);

    // Assuming array to be 1 indexed, number of even positions will always be 
    // size / 2 and rest wll be odd positions.
    int evenPos = size / 2;
    int oddPos = size - evenPos;

    int j = 0;
    for (int i = oddPos-1; i >= 0; i--)
    {
        arr[j] = tempArr[i];
        j += 2;
    }

    j = 1;
    for (int i = evenPos; i < size; i++)
    {
        arr[j] = tempArr[i];
        j += 2;
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