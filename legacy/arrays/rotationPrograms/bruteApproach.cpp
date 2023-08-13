#include <iostream>

// n is the size of the array
// d is the number of elements to rotate by
void arrRotation(int a[], int d, int n) 
{
    int temp{}, counter{};

    while (counter != d)
    {
        for (int i = 0; i < n-1; i++)
        {
            temp = a[i];
            a[i] = a[i+1];
            a[i+1] = temp;
        }
        counter++;
    }
}

int main()
{
    int numOfElements{}, elementsToRot{};
    std::cout << "How many number of elements would you like?\n";
    std::cin >> numOfElements;
    int arr[numOfElements] {};
    std::cout << "Please enter your elements" << std::endl;

    for (int i = 0; i < numOfElements; i++)
    {
        std::cin >> arr[i];
    }

    std::cout << "How many elements would you like to rotate?" << std::endl;
    std::cin >> elementsToRot;

    std::cout << "Your array before rotation" << std::endl;

    for (int i = 0; i < numOfElements; i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Your array after rotation" << std::endl;
    arrRotation(arr, elementsToRot, numOfElements);

    for (int i = 0; i < numOfElements; i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
        
    return 0;
}