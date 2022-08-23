#include <iostream>
#include <vector>
using namespace std;

void displayArray(vector<int>& array)
{
	cout << "The elements of the array are: "<< endl;
	for (auto &element: array)
	{
		cout << element << " ";
	}
	cout << endl;
}

void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
   
int partition (vector<int>& array, int left, int right) 
{ 
    int pivot = array[right];    
    int i = (left - 1);   
   
    for (int j = left; j <= right- 1; j++) 
    { 
        if (array[j] <= pivot) 
        { 
            i++;  
            swap(&array[i], &array[j]); 
        } 
    } 
    swap(&array[i + 1], &array[right]); 
    return (i + 1); 
} 
   
void insertionSort (vector<int>& array)
{
	for (int i = 1; i < array.size() ; i++) 
	{
		int current = array[i];
		int j = i - 1;
		while(j >= 0 && array[j] >= current)
		{
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = current;
	}
} 

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
	insertionSort(array);
	cout << "After sorting.... ";
	displayArray(array);
	return 0;
}
