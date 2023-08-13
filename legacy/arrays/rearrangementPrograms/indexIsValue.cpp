/*
Arrange array so that a[i] = i
Any missing elements will be marked by -1
*/

#include <iostream>

void rearrangeArr(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        // If element is -1 or the same as the index then
        // ignore the particular index
        if (arr[i] != -1 && arr[i] != i)
        {
            // Copy incorrect (at wrong index) value into a variable
            int x = arr[i]; 

            // If value comes out to be -1, then we have no index like -1 to
            // house the value. So we will terminate the loop. Similarly, if
            // we have the correct value at the correct index, then why bother. 
            while (arr[x] != -1 && arr[x] != x)
            {
                // Copy whatever value is present at the correct index
                int y = arr[x];
    
                arr[x] = x; // Place value at correct index

                // Now y has a new value which needs to be placed at its 
                // corresponding index. So, we will give that to x, pull the
                // value from its index into y and keep the loop going
                x = y;  
            }

            // If we get the same element at the same index, then the while
            // loop will break. So to put that element into its position, we 
            // will use the below statement.
            arr[x] = x;

            // check if while loop hasn't
            // set the correct value at A[i]
            if (arr[i] != i)
            {
                arr[i] = -1;
            }
        }
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

    rearrangeArr(userArr, sizeArr);

    for (int i = 0; i < sizeArr; i++)
    {
        std::cout << userArr[i] << " ";
    }

    std::cout << std::endl;
    
    return 0;
}