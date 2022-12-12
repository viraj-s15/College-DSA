#include <iostream>
// we will be using vectors for this because vectors can dynamically
// allocate memory and can improve the overrall performance of the code
#include <vector>
using namespace std;


class Stack 
// creating a custom stack data type to add functionality 
{
    vector<int> array;
    // using a dynamic array to use as a stack
    int top;
    int size;

public:

    Stack(int size)
    // this is a constructor for the stack object
    {
        this->size = size;
        this->top = -1;
        this->array = {};
    }

    void push(int value); // this pushes value to the stack
    void pop(); // pops the last element from the stack
    void displayStack(); // displays the stack
    int getTop(); // helper function that returns the top of the stack
};

// function declarations are outside the class
void Stack :: push(int value)
{

    if (this->size != this->array.size())
    // checking if the stack is full or not 
    // .size() returns the size of the stack currently 
    {
        // .push_back() adds a value to the vector array
        this->array.push_back(value); 
        cout << "The value " << value << " has been pushed to the stack" << endl;
        this->top++;
        cout << "The value of top is " << getTop() << endl;
    } 
    else 
    {
        cout << "The stack is full" << endl;
    }
} 

int Stack :: getTop()
{
    // helper function
    return this->top;
}

void Stack :: pop()
{       
    if (this->size > this->array.size())
    // checking whether the stack is empty
    {
        cout << "The last element of the stack has been removed" << endl;
        this->array.erase(this->array.end() - 1); 
        // this line removes the last element of the vector
        // .erase() removes any element of a particular index
        // .end() - 1 gives the index of the last element of the stack
        this->top--;
        cout << "The value of top is " << getTop() << endl;
    } 
    else 
    {
        cout << "The stack is empty" << endl;
    }
}

void Stack :: displayStack()
{
    if (this->top != -1)
    // checking whether the stack is empty
    {
        cout << "The stack is: ";
        for (auto &element : this->array)
        {
            cout << element << " ";
        }
        cout << endl;
    }
    else 
    {
        cout << "The stack is empty." << endl;
    }
}



int main()
{
    // the driver code for the program
    int numOfElements;
    cout << "Enter the number of elements in the stack" << endl;
    cin >> numOfElements;
    Stack s1(numOfElements);
    // creating a stack object and dynamically giving it a size
    int choice;
    while (true)    
    //  entering a for loop
    {
        cout << "Enter a number from 0 to 4" << endl;
        cout << "0 : To exit program" << endl;
        cout << "1 : To push value" << endl;
        cout << "2 : To pop value" << endl;
        cout << "3 : To print the value of top" << endl;
        cout << "4 : To print the stack" << endl;
        cout << "Enter your choice" << endl;
        cin >> choice;
        switch (choice) 
        {
            case 1:
                int value;
                cout << "Enter a value to be pushed to the stack" << endl;
                cin >> value;
                s1.push(value);
                continue;
            case 2:
                s1.pop();
                continue;
            case 3:
                cout << "The value of top is: " << s1.getTop() << endl;
                continue;
            case 4:
                s1.displayStack();
                continue;
            case 0:
                cout << "Ending program" << endl;
                break;
            default:
                cout << "Enter a valid value" << endl;
                continue;
        }
        break;  
    }
    return 0;
}