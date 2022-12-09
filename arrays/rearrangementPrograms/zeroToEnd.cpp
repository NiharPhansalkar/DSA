#include <iostream>

void pushToEnd(int* arr, int size)
{
    int count {0};
    for (int i{0}; i < size; i++)
    {
        if (arr[i] != 0)
        {
            // Push all non-zero elements to the start
            arr[count++] = arr[i];
        }
    }

    // Once all non-zero elements are fixed, place 0's in the rest of the
    // places.
    while (count < size)
    {
        arr[count++] = 0;
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

    pushToEnd(userArr, sizeArr);

    for (int i = 0; i < sizeArr; i++)
    {
        std::cout << userArr[i] << " ";
    }

    std::cout << std::endl;
    
    return 0;
}