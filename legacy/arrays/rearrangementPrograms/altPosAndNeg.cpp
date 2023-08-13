/*
eg. [-1, -2, 3, 4, 5, 6] will give [3, -2, 4, -1, 5, 6]. Rearrangement
is random.

We will be using a sort of quick sort type approach. We will be setting up a
swapper element, and then we will be putting -ve numbers onto one side and
positive on the other. (is GFG's claim)
I personally think of this more as a two pointer approach, where we find -ve
elements and just place them in the starting positions. Then alternate between
positive and negative terms to find a alternating array.
*/

#include <iostream>

void swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

int sortLogic(int *arr, int size)
{
    // We will start by initializing the swapper to -1, so when we increment
    // it, we will start from the 0th index.
    int swapper = -1;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] < 0)
        {
            swapper++;
            swap(&arr[swapper], &arr[i]);
        }
    }
    return swapper + 1;
}

void placeAlt(int *arr, int size, int swapper)
{
    int i = 0;
    int j = swapper;
    while (i < j && j < size && arr[i] < 0)
    {
        swap(&arr[i], &arr[j]);
        i += 2;
        j++;
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

    int piv = sortLogic(userArr, sizeArr);
    placeAlt(userArr, sizeArr, piv);

    for (int i = 0; i < sizeArr; i++)
    {
        std::cout << userArr[i] << " ";
    }

    std::cout << std::endl;

    return 0;
}