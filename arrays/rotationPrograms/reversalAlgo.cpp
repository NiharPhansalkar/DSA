#include <iostream>

void swap(int* num1, int* num2)
{
    int temp;
    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void reversal(int* arr, int lowerB, int upperB)
{
    while (lowerB < upperB)
    {
        swap(&arr[lowerB], &arr[upperB]);
        lowerB++;
        upperB--;
    }
}

void rotateArr(int* arr ,int rotations, int size)
{
    reversal(arr, 0, rotations-1);
    reversal(arr, rotations, size-1);
    reversal(arr, 0, size-1);
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

    std::cout << "How many rotations would you like?" << std::endl;
    int rotations;
    std::cin >> rotations;

    rotateArr(inputArr, rotations, numElements);

    for (int i = 0; i < numElements; i++)
    {
        std::cout << inputArr[i] << " ";
    }

    std::cout << std::endl;

    return 0;
}