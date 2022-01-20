// Binary Search on 1D array
#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
    int a[9], i, item, f, mid, pos=-1;
    //Enter an ascending ARRAY
    cout << "Enter Array (max 9 elements) \n";
    for (i = 0; i < 9; i++)
        cin >> a[i];
    //Enter the element to search
    cout << "Enter Element To search \n";
    cin >> item;
    //Searching the Element using binary search.
    int beg = 0;
    int last = 8;
    while (beg <= last)
    {
        mid = (beg + last) / 2;
        if (item == a[mid])
        {
            pos = mid;
            break;
        }
        if (item > a[mid])
            beg = mid + 1; // The beginning shifts else
        else
        last = mid - 1;    // The end shifts
    }
    if (pos==-1)
    cout << "Element Not Found" ;
    else
    cout << "Element Found at " << pos + 1 << " position";
    return 0;
}