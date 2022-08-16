#include <iostream>
#include <vector>
// we will be using vectors instead of regular arrays as they are resizable just as a stack should be
using namespace std;

class Stack 
// creating a data type called stack, this is the custom data type that will consist of all the
// required functions required for a stack to function 
// these functions are pop, push, getTop, getTopValue, all these functions are explained below   
{
    int top;
    // the stacks needs to deal with operands and operators hence we need a character vector 
	vector<char> stack;

public:

    Stack()
	// creating the constructor for the stack
    {
        this->top = -1;
        this->stack = {};
    }

	// all the function declarations are present in the class
    void push(char value);
    void pop();
    int getTop();
    bool isEmpty();
	char getTopValue();

};

void Stack::push(char value)
{
	// the push function adds a value to the stack 
	// since a stack is first in last out, this will add the valu to the end 
	// when the value needs to be removed from the stack, the very last value will be removed
	// the line below adds a value to the stack
    cout << "The value " << value << " has been pushed to the stack" << endl;
	this->stack.push_back(value);

	// incrementing the top after adding a value 
    this->top++;
}


void Stack::pop()
// this function is responsible for removing the last value from the stack
{
	// checking whether the stack is not empty
	if (!isEmpty())
	{
		// if it is not empty, we remove the last value from the stack
		cout << "The last element of the stack has been popped" << endl;
    	this->stack.erase(this->stack.end() - 1);
		// and decrement the value of top
		this->top--;
	}
}
char Stack::getTopValue()
// this is a helper function that returns the element at the top of the stack
{
	return this->stack.back();
}


int Stack::getTop()
{
	// this is a helper function that returns the value of top of the stack 
	// at any given time
    return this->top;
}

bool Stack::isEmpty()
// this is a helper function that tells if the stack is empty
{   
    if (getTop() == -1) return true;
    return false;
}


int getPrecendence(char value)
// this function puts all the operators in their order of precendence 
// this order decides what element gets popped from the stack at any given time
{
    if (value == '^') return 3;
    else if (value == '/' || value == '*') return 2;
    else if (value == '+' || value == '-') return 1;
    else return 0;
}

string infixToPostfix(Stack stack,string value)
// the function responsible for converting from infix to postfix
// we are using the custom data type stack with the  
{

	string output;
	// this is the output string and we will be adding the final answer to this string
	for (int i = 0; i < value.length(); i++) {
		// looping over the string to get each character
		char character = value[i];

		// if the character is a operand, we can add it to the output directly
		if ((character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z')
			|| (character >= '0' && character <= '9'))
			output += character;

		// If the scanned character is a‘(‘, we can push it to the stack directly 
		else if (character == '(')
			stack.push('(');

	// if the character is a ')' , we get the value of top
	// if the value of top is a ')' , we keep on popping elements till we reach the opening bracket
	//	once we reach the opening bracket, we see the character inside the brackets and we add it to the output
	else if (character == ')') {
			while (stack.getTopValue() != '(') {
				output += stack.getTopValue();
				stack.pop();
			}
			stack.pop();
		}

		// if an operator is found, we need to managhe it according to the order of precendence
		else {
			while (!stack.isEmpty() && getPrecendence(value[i]) <= getPrecendence(stack.getTopValue())) 
			{
				if (character == '^' && stack.getTopValue() != '^')
				// the '^' operator is right associative, when we encounter this, we exit this loop 
				// and push to the stack, in line 137 
					break;
				else 
				{
					// if it is left associative, we will nee to add it to the output according to the precendence
					output += stack.getTopValue();
					stack.pop();
				}
			}
			// finallyu pushing the ones in the stack 
			stack.push(character);
		}
	}

	// this part below is responsible for removing all of the remaining elements from the stack
	while (!stack.isEmpty()) 
	{
		// adding the remaining elements to the output
		output += stack.getTopValue();
		stack.pop();
	}

	// return the output
	return output;
}


int main()
{
	// driver code 
	cout << "All the functionality of all the functions can be seen in the output itself" << endl;
    string expression;
	cout << "Enter the expression: " << endl;
	cin >> expression;
    Stack Stack1;
    cout << infixToPostfix(Stack1,expression);
    return 0;

}