// Binary Search on 1D array
#include <stdio.h>
int main()
{ int a[9], i, item, f;
//Enter an ascending ARRAY
printf("Enter Array (max 9 elements) \n"); for(i=0;i<9;i++)
scanf("%d", &a[i]);
//Enter the element to search
printf("Enter Element To search \n");
scanf("%d", &item);
//Searching the Element using binary search. int beg, last, mid, pos;
beg = 0;
last = 8;
while(beg<=last)
{ mid = (beg+last)/2;
if(item == a[mid])
{pos = mid;
break;
}
else
if(item > a[mid])
beg = mid + 1; // The beginning shifts else
last = mid - 1; // The end shifts }
printf("Element Found at %d position", pos+1);
return 0;
}
