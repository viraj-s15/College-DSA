#include <iostream>
using namespace std;
class Node
{
	// The node class which represents one node in the linked list
	public:
		int value;
		Node *next;
		Node() {next = NULL;}
};

class LinkedList
{
	// the main linked list class 
	Node *head;
	int top;
	public:
		LinkedList()
		{
			head = NULL;
			this->top = -1; // setting top pointer as we have ti implement a stack
		}
		
		// function declarations
		void push(int value);
		void pop();
		void displayStack();
		int getTop() {return this->top;}
		void numberOfElements();
};		

void LinkedList::numberOfElements() 
{
	// this function gives the number of elements in the stack
	int count = 0;
	Node *temp = new Node();
	temp = head;
	while (temp != NULL)
	// running a loop which will loop through all the elements
	// till the value of the temp->next is null i.e. the end of the linked list
	{
		temp = temp->next;
		count++;
	}
	cout << "The number of elements in the stack are " << count << endl;
}

void LinkedList::push(int value)
{
	// using to push values into the stack
	Node *temp = new Node();
	temp->value = value;
	this->top++;
	// checking whether the linked list is empty
	if (head == NULL)
	{
		head = temp;
	}
	else
	{
		cout << "The element " << value << " has been pushed to the stack "<< endl;
		Node *temp2 = head;
		while (temp2->next != NULL){
			temp2 = temp2->next;
		}
		temp2->next = temp;
	}
}

void LinkedList::pop()
{
	if (head == NULL)
	{
		cout<<"Stack underflow!"<<endl;
	}
	else if (head->next == NULL)
	{
		this->top = -1;
		cout<<"The element "<<head->value<< " has been deleted"<<endl;
		delete(head);
		head = NULL;
	}
	else
	{
		this->top--;
		Node *temp = head;
		while (temp->next->next != NULL) 
		// same loop as above
		{
			temp = temp->next;
		}
		cout<<"The element "<<temp->next->value<< " has been deleted"<<endl;
		delete(temp->next);
		temp->next = NULL;
	}					
}

void LinkedList::displayStack()
{
	// displaying the stack 
	if (head == NULL)
	{
		cout<<"The the list is empty"<<endl;
	}
	else
	{
		Node *temp = head;
		cout<<"Stack: ";
		while (temp != NULL)
		{
			cout << temp->value <<" ";
			temp = temp->next;
		}
		cout << endl;
	}
}	

int main() 
{
	// driver code
	LinkedList Stack;
	int value,choice;
	cout << "Select an operation" << endl;
	cout << "1) Push Value into the stack" << endl;
	cout << "2) Pop values from the stack" << endl;
	cout << "3) Get the value of top pointer" << endl;
	cout << "4) Get the number of elements in the stack" << endl;
	cout << "5) Display the stack" << endl;
	cout << "-1) Exit the program" << endl;
	while(true)
	{
		cout << "Enter a number to perform the corresponding operation" << endl;
		cin >> choice;
		switch (choice)
		{
			case 1:
			cout << "Enter a value to be pushed to the stack" << endl;
			cin >> value;
			Stack.push(value);
			continue;
			case 2:
			Stack.pop();
			continue;
			case 3:
			cout << "The value of top of the stack is " << Stack.getTop() << endl;
			continue;
			case 4:
			Stack.numberOfElements();
			continue;
			case 5: 
			Stack.displayStack();
			continue;
			case -1:
			cout << "Exiting..." << endl;
			break;
		}
		break;
	}
	return 0;
}

