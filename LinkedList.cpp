#include <iostream>
// The entire code is explained in the comments below
using namespace std;

class Node
// creating a node 
// a node is a part of a linked list that consists of data and memory of the next node 
{
	public:
		int value;
		Node *next;
		// default constructor making next = null as the default
		// whenever a new node is created
		Node() {next = NULL;}
};

class LinkedList
// creating a custom data structure and naming it linked list
{
	// the head is the first node in the linked list
	Node *head;
	public:
		// the default constructor making head = null as the default
		// this is done because whenever a new linked list is created
		// the head is the onlu node and it points to null
		LinkedList()
		{
			head = NULL;
		}
		
		// all function declarations
		void insertAtBeginning(int value);
		void insertAt(int value, int position);
		void insertAtEnd(int value);
		void deleteAtBeginning();
		void deleteAt(int position);
		void deleteAtEnd();
		void displayList();
		void searchElement();
};		

		
		
		
void LinkedList::insertAtBeginning(int value)
// this function is responsiblee for inserting a value at the beginning of the linked list
{
	// we create a temporary node and name it temp
	Node *temp = new Node();
	// we give it whatever value is taken as input from the user
	temp->value = value;
	// we set the memory of the temporary node to point to the head and then make
	// the temp node the new head i.e the first node of the linked list that contains
	// a value
	temp->next = head;
	head = temp;
}

void LinkedList::insertAtEnd(int value)
{
	// we create a temporary node and name it temp
	Node *temp = new Node();
	// we give it whatever value is taken as input from the user
	temp->value = value;
	if (head == NULL)
	{
		// if linked the list is empty we make temp the new head i.e the first node of the linked list
		head = temp;
	}
	else
	{
		// if the linked list is not empty we create another temporary node 
		// we create a loop such that the node points to the last node of the linked list
		// once it points to the last node, we make it point to the first temp node 
		// where we stored the value taken as input from the user
		Node *temp2 = head;
		while (temp2->next != NULL){
			temp2 = temp2->next;
		}
		temp2->next = temp;
	}
}

void LinkedList::insertAt(int value, int position)
// this function is responsible for inserting a node at any given position in the linked list
{
	Node *temp = new Node();
	// we create a temporary node and set it's value as the user input 
	temp->value = value;
	if (position == 0)
	// if the first element needs to be removed, temp as the new head
	{
		temp->next = head;
		head = temp;
	}
	else
		// if the value neess to be added after the first element of the linked list
	{
		// we create a temporary looping node and use it to reach the (n-1)th node
		Node *temp2 = head;
		while(position>1) {
			temp2 = temp2->next;
			--position;
		}
		// we then insert the first temp node between the nth and the (n-1)th node
		temp->next = temp2->next;
		temp2->next = temp;
	}
}

void LinkedList::deleteAtBeginning()
	// this function is responsible for deleting the first element of the linked list
{
	if (head == NULL)
	// checking whether the list is empty
	{
		cout<<"the list is empty"<<endl;
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

void LinkedList::deleteAtEnd()
{
	if (head == NULL)
	// checking whether the the list is empty
	{
		cout<<"the list is empty"<<endl;
	}
	else if (head->next == NULL)
	// if linked list has only two element, we can directly delete it 
	// once the element is deleted, we can set head to null
	{
		cout<<"The element "<<head->value<< " has been deleted"<<endl;
		delete(head);
		head = NULL;
	}
	else
	{
		// creating a temporary node
		Node *temp = head;
		// running a loop that gets temp to the second last element of the linked list
		while (temp->next->next != NULL) 
		{
			temp = temp->next;
		}
		// once we reach the second last value, we delete the next value of that node 
		// and set it to null 
		cout<<"The element "<<temp->next->value<< " has been deleted"<<endl;
		delete(temp->next);
		temp->next = NULL;
	}					

}

void LinkedList::deleteAt(int position)
	// checking whether the the list is empty
{
	if (head == NULL)
	{
		cout<<"the list is empty"<<endl;
	}
	else {
	Node *temp, *temp2;
		if (position == 0) 
		// if the first element is to be removed
		// we create a temporary variable that points to head 
		// we then move head ahead by one node and delete the temporary node
		{
			cout<<"The element "<<head->value<< " has been deleted"<<endl;
			temp2 = head;
			head = head->next;
			delete(temp2);
		}
		else
		{

			temp = temp2 = head;
			while(position>0){
				--position;
				// we set temp to the (n-1)th element and temp2 to nth element 
				temp = temp2;
				temp2 = temp2->next;
			}
			cout<<"The element "<<temp2->value<< " has been deleted"<<endl;
			// we then set temp to point at the next element of temp2
			temp->next = temp2->next;
			// we clear the temp2 memory and thats how the element is deleted
			free(temp2);
		}
	}

}

void LinkedList::displayList()
// this function is responsible for displaying the linked list
{
	if (head == NULL)
	// checking whether the linked the list is empty 
	{
		cout<<"The the list is empty"<<endl;
	}
	else
	// if it is not empty 
	// we create a looping node and loop through the linked list while we print the value
	{
		Node *temp = head;
		cout<<"Linked List: ";
		while (temp != NULL)
		{
			cout<<temp->value<<"->";
			temp = temp->next;
		}
		cout<<"NULL"<<endl;
	}
}	

void LinkedList::searchElement()
// this function responsible for searching elements in the linked list
{
	int index;
	int toBeFound,count = 0;
	// decalaring the index, toBeFound and count as temporary variables
	cout << "Enter the value to be searched for: " << endl;
	cin >> toBeFound;
	bool isFound = false;	
	Node *temp = head;
	while(temp != NULL)
	// while the value of the node is not null i.e. the list has not ended
	{
		if (head->value == toBeFound)
		// if the first value is null, we directly return the first index 
		{
			isFound = true;
			count = 0;
			break;
		}
		if (temp->value != toBeFound)
		// increment count till we dont reach the element
			{
				count++;
				temp = temp->next;
			}

		if (temp->value == toBeFound)
		// once we do reach the element, we can then stop the code and set count as index
		// we can then print the appropriate statement
		{
			isFound = true;
			index = count;
			break;
		}
	}
	isFound ? cout << "The element has been found at index " << count << endl : cout << "The element has not been found" << endl;

}
int main() 
{
	
	cout << "1) Insert at the beginning of the linked list" << endl;
	cout << "2) Insert at the end of the linked list" << endl;
	cout << "3) Insert at any index of the linked list" << endl;
	cout << "4) Delete at the beginning of the linked list" << endl;
	cout << "5) Delete at the end of the linked list" << endl;
	cout << "6) Delete at any index of the linked list" << endl;
	cout << "7) Display the list" << endl;
	cout << "8) Search for element in the linked list" << endl;
	cout << "0) Exit the program" << endl;
	
	LinkedList l1;
	
	int choice,value,position;
	while (true)
	{
		cout<<"\nEnter Your Choice: ";
		cin>>choice;
		switch (choice)
		{
			case 0:
				cout << "Exiting..." << endl;
				break;
			case 1:
				cout<<"Enter Element: ";
				cin>>value;
				l1.insertAtBeginning(value);
				continue;
			case 2:
				cout<<"Enter Element: ";
				cin>>value;
				l1.insertAtEnd(value);
				continue;
			case 3:
				cout<<"Enter Element: ";
				cin>>value;
				cout<<"Enter Position: ";
				cin>>position;
				l1.insertAt(value,position);
				continue;
			case 4:
				l1.deleteAtBeginning();
				continue;
			case 5:
				l1.deleteAtEnd();
				continue;
			case 6:
				cout<<"Enter Position ( zero-indexed ): ";
				cin>>position;
				l1.deleteAt(position);
				continue;
			case 7:
				l1.displayList();
				continue;
			case 8:
				l1.searchElement();
				continue;
		}
		break;
	}
}

