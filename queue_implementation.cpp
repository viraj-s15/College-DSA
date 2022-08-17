#include <iostream>
#include <vector>
using namespace std;

class Queue
{
    int front;
    int rear;
    vector<int> queue;
    int size;

public:

   Queue(int size)
   {
       this->size = size;
       this->queue = {};
       this->front = -1;
       this->rear = -1;
   }

    void insert();
    void remove();
    void display();
    bool isEmpty();
    void getFront();
    void getRear();
};

void Queue::insert()
{
	
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
        this->front = 0;
        this->rear++;
    }
}


void Queue::remove()
{
    if (this->front == -1 )
    {
        cout << "The queue is empty" << endl;
    }
    else
    {
        this->queue.erase(this->queue.begin());
        cout << "The first element has been removed" << endl;
		this->rear--;
		if (this->queue.size() == 0)
		{
			this->front = -1;
		}
    }
}


void Queue::display()
{
    if (isEmpty())
	{
		cout << "The queue is empty" << endl;
	} 
	else
	{
		cout << "The elements in the queue: ";
		for (auto &element : this->queue)
		{
			cout << element << " ";
		}
		cout << endl;
	} 
}

bool Queue::isEmpty()
{
    if (this->front < 0 || this->front == this->rear)
    {
        return true;
    }
    return false;
}


void Queue::getFront()
{
    cout << "The first element in the queue is: " << this->queue[this->front] << endl;
}

void Queue::getRear()
{
    cout << "The last element in the queue is: " << this->queue[this->rear] << endl;
}

int main()
{
	int size,choice;
	cout << "This program is written by Viraj Shah 21BCE0577" << endl;
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
