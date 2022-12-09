#include <bits/stdc++.h>

// Time complexity - https://youtu.be/cWvruDR-hJA?list=PLauivoElc3ggagradg8MfOZreCMmXMmJ-&t=1595 

const int N = 1e5+10;
int a[N]; // We are declaring this array as global so that
          // we do not need to pass it to the function

void merge(int l, int r, int mid)
{
    /*  
    Here we will assume we have two arrays,
    one from l to mid, the other from
    mid + 1 to r
    */

    // We will take starting index of main array to be 0
    // Consider that. 

    int l_size = mid - l + 1; // Take an array and try it out
    int r_size = r - mid; // r_size = r - (mid+1) + 1

    int L[l_size + 1]; // Our left array. Also, why +1? For line 37
    int R[r_size + 1]; // Our right array. Also, why +1? For line 37

    // Now we will put l to mid elements into L
    // and mid+1 to r elements into R
    for (int i = 0; i < l_size; i++)
    {
        L[i] = a[i + l]; // a[l] is first element in left array
                         // assign it to L[0] and so on.
    }
    for (int i = 0; i < r_size; i++)
    {
        R[i] = a[i + mid + 1]; // a[mid + 1] is first element in left array
                               // assign it to R[0] and so on.
    }

    L[l_size] = R[r_size] = INT_MAX; // https://youtu.be/cWvruDR-hJA?list=PLauivoElc3ggagradg8MfOZreCMmXMmJ-&t=1078

    int l_i = 0;
    int r_i = 0;

    for (int i = l; i <= r; i++)
    {
        if (L[l_i] <= R[r_i])
        {
            a[i] = L[l_i];
            l_i++;
        }
        else
        {
            a[i] = R[r_i];
            r_i++;
        }
    }
}

void mergeSort(int l, int r)
{
    if (l == r) 
        return;

    int mid = (l+r)/2;
    mergeSort(l, mid);
    mergeSort(mid+1, r);
    merge(l, r, mid);
}

int main()
{
    int n;
    std::cout << "How many elements?\n";
    std::cin >> n;

    std::cout << "Enter your elements?\n";
    
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }

    mergeSort(0, n-1);

    std::cout << std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cout << a[i] << std::endl;
    }
    
    return 0;
}