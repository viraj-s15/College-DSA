#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int low, int size) {
  int i;
  for (i = low; i < size; i++)
    cout << arr[i] << " ";
  cout << endl;
}

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int arr[], int low, int high) {
  int pivot = arr[low];
  int k = high;
  cout << "Pivot " << pivot << endl;
  for (int i = high; i > low; i--) {
    if (arr[i] > pivot)
      swap(arr[i], arr[k--]);
  }
  swap(arr[low], arr[k]);
  return k;
}

void quickSort(int arr[], int low, int high) {
  if (low < high) {
    int p = partition(arr, low, high);
    quickSort(arr, low, p - 1);
    quickSort(arr, p + 1, high);
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
