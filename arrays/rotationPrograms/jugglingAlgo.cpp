/*
->  How does GCD get us the number of times we need to rotate?
    It's actually simple to understand intuitively.

->  The way the juggling algorithm works, we need to break the
    array into equal sized sets so that we can juggle the 
    values. 
    Take an example where size of array is 13 and times to
    rotate is 4.

->  Now, if I were to make sets of 4 elements, the last element
    would remain. We would never be able to shuffle this last
    element.
    Okay, so let's divide it into sets of 3, will that work?
    Sure, sets of 3 divides the total size perfectly into
    4 sets, but now the problem is, we can only juggle 3
    elements, meaning we can rotate only 3 times.

->  This is the basic intuition behind this algorithm,
    And Mathematically what ends up happening is that the
    GCD is the thing that gives us how many proper sets
    we can divide the array into.
*/

#include <iostream>

int getGCD(int num1, int num2)
{
    if (num2 == 0)
    {
        return num1;
    }
    
    return getGCD(num2, num1 % num2);
}

void swap(int* num1, int* num2)
{
    int temp;
    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void rotateArr(int* userArr, int size, int timesToRotate)
{
    timesToRotate %= size; // To avoid timesToRotate being greater than size

    int setSize = getGCD(size, timesToRotate); // How many sets to divide into

    for (int i = 0; i < setSize; i++)
    {
        int j = i;

        while (true)
        {
            if (j >= size - setSize)
            {
                break;
            }

            swap(&userArr[j], &userArr[j + setSize]);
            j += setSize;
        }
    }
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

    rotateArr(inputArr, numElements, rotations);

    for (int i = 0; i < numElements; i++)
    {
        std::cout << inputArr[i] << " ";
    }

    std::cout << std::endl;
    
    return 0;
}