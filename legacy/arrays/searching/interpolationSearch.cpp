/*

https://www.geeksforgeeks.org/interpolation-search/
Go through the above link to get a good understanding of this search

*/

#include <iostream>

int interSearch(int* arr, int arrSize, int elementToSearch)
{
    int lb = 0;
    int ub = arrSize - 1;
    
    while (lb <= ub)
    {
        int pos = lb + ((ub - lb)/(arr[ub] - arr[lb]) * (elementToSearch - arr[lb]));

        if (arr[pos] == elementToSearch)
        {
            return pos + 1;
        }
        else if (arr[pos] > elementToSearch)
        {
            ub = pos - 1;
        }
        else
        {
            lb = pos + 1;
        }
    }
    return -1;
}

int main()
{
    int numOfElements{};
    std::cout << "How many elements would you like to have?" << std::endl;
    std::cin >> numOfElements;
    int userArr[numOfElements];

    std::cout << "Please enter your elements" << std::endl;

    for (int i{0}; i < numOfElements; i++)    
    {
        std::cin >> userArr[i]; 
    }

    std::cout << "Please enter the element to search for" << std::endl;
    int findThis;
    std::cin >> findThis;
    std::cout << interSearch(userArr, numOfElements, findThis) << std::endl;

    return 0;
}