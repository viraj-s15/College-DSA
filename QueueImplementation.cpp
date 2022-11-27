#include <iostream>
// All of the code below will be explained in the comments 
#include <vector>
// we are using vector as it can be expanded indefinitely and is more efficient than a pointer array
using namespace std;

class Queue
// creating a custom data type called queue, all the functions related to queue will be present here
{
	// giving the queue attributes
    int front;
    int rear;
    vector<int> queue;
    int size;

public:
	// this is a contructor that is used to initalise the value of front and rear
   Queue(int size)
   {
       this->size = size;
       this->queue = {};
       this->front = -1;
       this->rear = -1;
   }

	// all function declarations are present here
    void insert();
    void remove();
    void display();
    bool isEmpty();
    void getFront();
    void getRear();
};

void Queue::insert()
// this function is used to insert a value into the queue
{
	// checking whether the queue is full or not
    if ((this->rear == this->size - 1))
    {
        cout << "The queue is full" << endl;
    }
    else
    {
        int value;
        cout << "Enter a value to be inserted" << endl;
        cin >> value;
        this->queue.push_back(value);
		// front now becomes 0 as there is an element in the queue
        this->front = 0;
		// rear is incremented to match the last element of the queue
        this->rear++;
    }
}


void Queue::remove()
{
	// checking whether the queue is empty 
    if (this->front == -1 )
    {
        cout << "The queue is empty" << endl;
    }
    else
    {
		// removing the first element from the queue
        this->queue.erase(this->queue.begin());
        cout << "The first element has been removed" << endl;
		this->rear--;
		// if the first element of the queue is also removed, we reset front to -1
		if (this->queue.size() == 0)
		{
			this->front = -1;
		}
    }
}


void Queue::display()
{	
	// checking whether the queue is empty
    if (isEmpty())
	{
		cout << "The queue is empty" << endl;
	} 
	else
	{
		cout << "The elements in the queue: ";
		// using a range based loop
		for (auto &element : this->queue)
		{
			cout << element << " ";
		}
		cout << endl;
	} 
}

bool Queue::isEmpty()
{
	// helper function that checks if the queue is empty
    if (this->front < 0 || this->front == this->rear)
    {
        return true;
    }
    return false;
}


void Queue::getFront()
// gets the front of the queue
{
    cout << "The first element in the queue is: " << this->queue[this->front] << endl;
}

void Queue::getRear()
// gets the rear of the queue
{
    cout << "The last element in the queue is: " << this->queue[this->rear] << endl;
}

int main()
//driver code
{
	int size,choice;
	cout << "Enter the size of the queue: " << endl;
	cin >> size;
    Queue q1(size);
	cout << "1) Insert element / Enqueue " << endl;
	cout << "2) Delete element / Dequeue " << endl;
	cout << "3) Get first element " << endl;
	cout << "4) Get last element " << endl;
	cout << "5) Display the queue" << endl;
	cout << "6) Exit the program" << endl;
	while (true)
	{
		cout << "Enter your choice: " << endl;
		cin >> choice;
		switch(choice)
		{
			case 1:
    			q1.insert();
				continue;
			case 2:
    			q1.remove();
				continue;
			case 3:
    		    q1.getFront();
				continue;
			case 4:
    		    q1.getRear();
				continue;
			case 5:
	    		q1.display();
				continue;
			case 6:
	    		cout << "Exiting..." << endl;
				break;
		}
		break;
	}	
}
