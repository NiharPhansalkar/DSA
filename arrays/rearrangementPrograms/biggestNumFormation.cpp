/*
Given an array of numbers, arrange them in a way that yields the largest value. 
For example, if the given numbers are {54, 546, 548, 60}, the arrangement 
6054854654 gives the largest value. And if the given numbers are 
{1, 34, 3, 98, 9, 76, 45, 4}, then the arrangement 998764543431 gives the 
largest value.
*/

#include <iostream>

long long powerOfTen(int power)
{
    int finalResult{1};

    while (power-- != 0)
    {
        finalResult = finalResult * 10;
    }
    
    return finalResult;
}

int returnNumOfZeroes(int number)
{
    int counter{};
    while (number != 0)
    {
        counter++;
        number /= 10;
    }
    return counter;
}

long long rearrangeToLargest(int* arr, int size)
{
    int num1{arr[0]}, num2{arr[1]};
    int numOfZeroes;
    long long int merger1;
    long long int merger2;

    int i = 2;
    while (i != size+1)
    {
        if (num1 < num2)
        {
            numOfZeroes = returnNumOfZeroes(num2);
            merger1 = (num1 * powerOfTen(numOfZeroes)) + num2;
        }
        else
        {
            numOfZeroes = returnNumOfZeroes(num1);
            merger1 = (num2 * powerOfTen(numOfZeroes)) + num1;
        }


        if (num1 < num2)
        {
            numOfZeroes = returnNumOfZeroes(num1);
            merger2 = (num2 * powerOfTen(numOfZeroes)) + num1;
        }
        else
        {
            numOfZeroes = returnNumOfZeroes(num2);
            merger2 = (num1 * powerOfTen(numOfZeroes)) + num2;
        }

        if (merger1 > merger2)
        {
            num1 = merger1;
            num2 = arr[i];
        }
        else
        {
            num1 = merger2;
            num2 = arr[i];
        }

        i++;
    }

    return num1;
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

    long long int result = rearrangeToLargest(arr, numOfElements);

    std::cout << std::endl;
    std::cout << "The largest possible number here is " << result << std::endl;
    
    return 0;
}