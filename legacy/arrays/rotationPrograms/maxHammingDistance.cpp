#include <iostream>

int maxNum(int &a, int &b);
bool compareTwoNos(int &a, int &b);
void swap(int* num1, int* num2);
void rotateArr(int* arr, int size);
int hammingDist(int* arr, int size);

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

    std::cout << "The max hamming distance is: " << hammingDist(userArr, sizeArr) << std::endl;

    return 0;
}

int hammingDist(int* arr, int size)
{
    int secondArr[2*size];
    
    // Copy the given array twice into one array
    for (int i = 0; i < size; i++)
    {
        secondArr[i] = arr[i];
        secondArr[i+size] = arr[i];
    }

    int maxHum = 0; // For 1 element, max will be 0

    for (int i = 0; i < size; i++)
    {
        int currentHum = 0;
        rotateArr(secondArr, size-1);
        int k = 0;
        for (int j = size; j < 2 * size; j++)
        {
            if (compareTwoNos(secondArr[j], secondArr[k]) == true)
            {
                k++;
                currentHum++;
            }
            else
            {
                k++;
                continue;
            }
        }
        maxHum = maxNum(maxHum, currentHum);
    }

    return maxHum;
}

void rotateArr(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        swap(&arr[i], &arr[i+1]);
    }
}

bool compareTwoNos(int &a, int &b)
{
    if (a != b)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int maxNum(int &a, int &b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

void swap(int* num1, int* num2)
{
    int temp;
    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}