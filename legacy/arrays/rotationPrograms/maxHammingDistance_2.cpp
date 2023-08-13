#include <iostream>

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

int hammingDist(int* arr, int size)
{
    int maxHam = 0;
    for (int i = 1; i < size; i++)
    {
        int currHam = 0;
        for (int j = 0; j < size; j++)
        {
            if (arr[j] != arr[(i + j) % size])
            {
                currHam++;
            }
        }
        if(currHam == size) // Max possible value for currHam
            return size;
        else
        {
            maxHam = maxNum(maxHam, currHam);
        }
    }
    return maxHam;
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

    std::cout << "The max hamming distance is: " << hammingDist(userArr, sizeArr) << std::endl;
    
    return 0;
}