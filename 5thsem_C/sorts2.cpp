#include <iostream>
using namespace std;
void heapify(int arr[], int n, int i)
{
  int largest = i;   // largest -> root
  int r = 2 * i + 2; // right child= 2*i + 2
  int l = 2 * i + 1; // left child= 2*i + 1
  // If left child > root
  if (l < n && arr[l] > arr[largest])
    largest = l;
  // If right child > largest so far
  if (r < n && arr[r] > arr[largest])
    largest = r;
  // If largest is not root
  if (largest != i)
  {
    swap(arr[i], arr[largest]);
    heapify(arr, n, largest);
  }
}
void heapSort(int arr[], int n)
{
  // rearrange array
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(arr, n, i);
  // One by one extract an element from heap
  for (int i = n - 1; i > 0; i--)
  {
    swap(arr[0], arr[i]);
    heapify(arr, i, 0);
  }
}

int main()
{
  int arr[] = {77, 12, 32, 87, 4, 1, 9};
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << "Unsorted array is \n";
  for (int i = 0; i < n; ++i)
    cout << arr[i] << " ";
  heapSort(arr, n);
  cout << "\nSorted array is \n";
  for (int i = 0; i < n; ++i)
    cout << arr[i] << " ";
  cout << "\n";
}
