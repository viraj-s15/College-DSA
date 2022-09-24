#include <iostream>
#include <vector>
using namespace std;
// we will use vectors over array as it is more efficient whike providing the exact same functionality

// function for displaying the array
void displayArray(vector<int>& array)
{
	cout << "The elements of the array are: "<< endl;
	for (auto &element: array)
	{
		cout << element << " ";
	}
	cout << endl;
}

// helper function used for swapping elements to reduce code duplication
void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
   
	// the function that is responsible for divinding the main array into smaller arrays
void merge(vector<int>& array, int const left, int const mid,
           int const right)
{
    int subArrayOne = mid - left + 1;
    int subArrayTwo = right - mid;
 
	// creating the two arrays
    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];
	
	// this is where the divison is taking place
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
 
    auto index1 = 0, index2 = 0; 
    int mergedIndex = left; 
 
	// combining the array again once it is sorted
	// adding the right and left elements
    while (index1 < subArrayOne
           && index2 < subArrayTwo) {
        if (leftArray[index1]
            <= rightArray[index2]) {
            array[mergedIndex]
                = leftArray[index1];
            index1++;
        }
        else {
            array[mergedIndex]
                = rightArray[index2];
            index2++;
        }
        mergedIndex++;
    }
  
//   adding any remaining elements present on the left
    while (index1 < subArrayOne) {
        array[mergedIndex]
            = leftArray[index1];
        index1++;
        mergedIndex++;
    }
    
//   adding any remaining elements present on the right
    while (index2 < subArrayTwo) {
        array[mergedIndex]
            = rightArray[index2];
        index2++;
        mergedIndex++;
    }

	// freeing the memory of the two array
    delete(leftArray);
    delete(rightArray);
}
 


// the main function that is called recursively
void mergeSort(vector<int>& array, int const begin, int const end)
{
    if (begin >= end)
	//recursive return statement
        return; 
 
    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}
 

// function to take input of the array
void takeInput(vector<int>& array, int elements)
{
	cout << "Enter the elements of the array: "<< endl;
	int num;
	for (int i = 0; i < elements; i++)
	{
		cin >> num;
		array.push_back(num);
	}
}

// driver code
//  left = index 0
// right = last index of array
int main() 
{
	int elements = 0;
	cout << "Enter the number of elements in the array: " << endl;
	cin >> elements;
	vector<int> array;
	takeInput(array,elements);
	displayArray(array);
	int left= 0;
	int right = array.size() - 1;
	mergeSort(array,left,right);
	cout << "After sorting.... ";
	displayArray(array);
	return 0;
}
