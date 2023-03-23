#include <bits/stdc++.h>
using namespace std;
/* Function to print an array */
void printArray(int arr[], int low, int size) {
  int i;
  for (i = low; i < size; i++)
    cout << arr[i] << " ";
  cout << endl;
}

// A utility function to swap two elements
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int arr[], int low, int high) {
  // cout<<"Before"<<endl;
  // printArray(arr,low, high);
  int pivot = arr[high]; // pivot
  int i = (low - 1);     // Index of smaller element and indicates
                         // the right position of pivot found so far
  for (int j = low; j <= high - 1;
       j++) { // If current element is smaller than the pivot
    if (arr[j] < pivot) {
      i++; // increment index of smaller element
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  cout << "Pivot " << arr[i + 1] << endl;
  return (i + 1);
}

void quickSort(int arr[], int low, int high) {
  if (low < high) { /* pi is partitioning index, arr[p] is now at right place */
    int pi = partition(arr, low, high);
    // Separately sort elements before
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  quickSort(arr, 0, n - 1);
  cout << "Sorted array: \n";
  printArray(arr, 0, n);
  return 0;
}
