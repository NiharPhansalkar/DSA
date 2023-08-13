#include <iostream>

int checkTurnPoint(int *arr)
{
    int i = 0;

    while (arr[i] < arr[i+1])
    {
        i++;
    }
    return i;
}

int binSearch(int* arr, int lb, int ub, int search)
{
    while (lb <= ub)
    {
        int mid = (lb+ub)/2;

        if (arr[mid] == search)
        {
            return 1;
        }
        else if (arr[mid] < search)
        {
            lb = mid + 1;
        }
        else
        {
            ub = mid - 1;
        }
    }
    return -1;
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

    std::cout << "Which element would you like to find?" << std::endl;
    int find;
    std::cin >> find;

    int rotPoint = checkTurnPoint(inputArr);

    int sizeOfFirstArr = rotPoint + 1;
    int sizeOfSecondArr = numElements - rotPoint - 1;
    int firstArr[sizeOfFirstArr], secondArr[sizeOfSecondArr];

    for (int i = 0; i < sizeOfFirstArr; i++)
    {
        firstArr[i] = inputArr[i];
    }

    int j = 0;

    for (int i = sizeOfFirstArr; i < numElements; i++)
    {
        secondArr[j] = inputArr[i];
        j++;
    }

    if ((binSearch(firstArr, 0, sizeOfFirstArr, find)) == 1)    
    {
        std::cout << "Your element has been found!" << std::endl;
    }
    else if (binSearch(secondArr, 0, sizeOfSecondArr, find) == 1)
    {
        std::cout << "Your element has been found!" << std::endl;
    }
    else
    {
        std::cout << "Your element is not present in the list" << std::endl;
    }

    return 0;

}