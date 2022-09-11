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
	int front;
	int rear;
	public:
		LinkedList()
		{
			head = NULL;
			this->front = -1; // setting front pointer as we have to implement a queue
			this->rear = -1; // setting rear pointer as we have to implement a queue
		}
		
		// function declarations
		void insert(int value);
		void deletion();
		void displayQueue();
		int getFront() {return this->front;}
		int getRear() {return this->rear;}
		void numberOfElements();
};		

void LinkedList::numberOfElements() 
{
	// this function gives the number of elements in the queue
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
	cout << "The number of elements in the queue are " << count << endl;
}

void LinkedList::insert(int value)
{
	// using to inset values into the queue
	Node *temp = new Node();
	temp->value = value;
	this->front = 0;
	this->rear++;
	// checking whether the linked list is empty
	if (head == NULL)
	{
		head = temp;
	}
	else
	{
		cout << "The element " << value << " has been inserted to the queue "<< endl;
		Node *temp2 = head;
		while (temp2->next != NULL){
			temp2 = temp2->next;
		}
		temp2->next = temp;
	}
}
void LinkedList::deletion()
	// this function is responsible for deleting the first element of the linked list
{
	if (head == NULL)
	// checking whether the list is empty
	{
		cout<<"The queue is empty"<<endl;
	}
	else
	{
		// we set the address of the head to a temporary node
		cout<<"The element "<<head->value<< " has been deleted"<<endl;
		Node *temp = head;
		// we then set th head as the next element
		// we then delete the temp to delete the first element of the linked list
		head = head->next;
		delete(temp);
	}
}

void LinkedList::displayQueue()
{
	// displaying the queue 
	if (head == NULL)
	{
		cout<<"The queue is empty"<<endl;
	}
	else
	{
		Node *temp = head;
		cout<<"Queue: ";
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
	LinkedList Queue;
	int value,choice;
	cout << "Select an operation" << endl;
	cout << "1) Insert Value into the queue" << endl;
	cout << "2) Delete Value from the queue" << endl;
	cout << "3) Get the value of front pointer" << endl;
	cout << "4) Get the value of rear pointer" << endl;
	cout << "5) Get the number of elements in the queue" << endl;
	cout << "6) Display the queue" << endl;
	cout << "-1) Exit the program" << endl;
	while(true)
	{
		cout << "Enter a number to perform the corresponding operation" << endl;
		cin >> choice;
		switch (choice)
		{
			case 1:
			cout << "Enter a value to be inserted into the queue" << endl;
			cin >> value;
			Queue.insert(value);
			continue;
			case 2:
			Queue.deletion();
			continue;
			case 3:
			cout << "The value of front of the queue is " << Queue.getFront() << endl;
			continue;
			case 4:
			cout << "The value of rear of the queue is " << Queue.getRear() << endl;
			continue;
			case 5:
			Queue.numberOfElements();
			continue;
			case 6: 
			Queue.displayQueue();
			continue;
			case -1:
			cout << "Exiting..." << endl;
			break;
		}
		break;
	}
	return 0;
}

