#include <iostream>
// we will be using vectors for this because vectors can dynamically
// allocate memory and can improve the overrall performance of the code
#include <vector>
using namespace std;

void takeInput(vector<int> &v)
// this function is responsible for taking input of the array
{
    // we allow the user to add as many elements as they wish to
    cout << "Keep typing elements till you want" << endl;
    cout << "Type 0 to stop adding elements to the array" << endl;
    int input;
    // whenever they type the number 0, the array will stop taking input 
    while(cin >> input && input != 0)
    {
        // adding elements to the array
        v.push_back(input);
    }
}

void printArray(vector<int> &v)
// this is responsible for printing the array
{

    for (auto &element : v)
    // this is a range based loop
    {
        cout << element << " ";
    }
    cout << endl;    
}


void linearSearch(vector<int> &v)
// this is the function that is responsible for the linear srearch funcitonality
{
    int toBeFound, indexFound;
    bool found = false;
    cout << "Enter the element to be searhed for in the array: " << endl;
    cin >> toBeFound;
    // linear search functionality
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == toBeFound)
        {
            indexFound = i;
            found = true;
            break;
        }
    }

    if (found)
    {
        cout << "The element has been found at index position: " << indexFound;
        cout << endl;
    } 
    else 
    {
        cout << "The element is not present in the array" << endl;
    }
}


int main()
{
    // the driver code for the program
    vector<int> numbers;
    takeInput(numbers);
    printArray(numbers);
    linearSearch(numbers);
    return 0;
}