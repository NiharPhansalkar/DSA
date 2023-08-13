#include <iostream>

int checkTurnPoint(int *arr)
{
    int i = 0;

    while (arr[i] < arr[i+1])
    {
        i++;
    }
    return i+1;
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

    int rotPoint = checkTurnPoint(inputArr);

    std::cout << numElements - rotPoint << std::endl; // For right rotation
    // std::cout << rotPoint << std::endl; // For left rotation

    return 0;

}