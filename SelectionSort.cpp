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
   
void selectionSort(vector<int>& array)
{
	int i, j, min;
 
    for (i = 0; i < array.size()-1; i++)
    {
       
        min = i;
        for (j = i+1; j < array.size(); j++)
        if (array[j] < array[min])
            min = j;
 
        if(min!=i)
            swap(&array[min], &array[i]);
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
	selectionSort(array);
	cout << "After sorting.... ";
	displayArray(array);
	return 0;
}
