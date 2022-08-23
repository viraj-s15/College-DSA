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

void bubbleSort(vector<int> array)
{
	
	for (int i = 1; i < array.size(); i++)
	{
		for (int j = 0 ;j < array.size() - 1 ; j++)
		{
			if (array[j] > array[j + 1])
			{
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}

	cout << "After sorting the array is: " << endl;
	displayArray(array);
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
	cout << "The array after being sorted looks like: " << endl;
	bubbleSort(array);
	return 0;
}
