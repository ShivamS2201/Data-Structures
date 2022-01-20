#include<stdio.h>
// Utility function.
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
//Last element is used as Pivot point. 
int partition (int arr[], int L, int H)
{
    int pivot = arr[H]; // pivot
    int i = (L - 1); // Index of smaller element

    for (int j = L; j <= H- 1; j++)
    {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot)
        {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);//Call by reference.
        }
    }
    swap(&arr[i + 1], &arr[H]);
    return (i + 1);
}
/* arr[] --> Array to be sorted,
L --> Starting index,
H --> Ending index */
void quickSort(int arr[], int L, int H)
{    if (L < H)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, L, H);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, L, pi - 1);
        quickSort(arr, pi + 1, H);
    }
}
int main()
{    int arr[] = {32,43,123,59,28,13,91};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Original Array: \n");
    for (int i=0; i < n; i++)
        printf("%d ", arr[i]);
    quickSort(arr, 0, n-1);
    printf("\nSorted Array: \n");
    for (int i=0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}

