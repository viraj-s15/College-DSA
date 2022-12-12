class Stack:
    # creating a new data type of class
    
    def __init__(self, size):
    # the constructor
        self.size = size
        # only the size will change here, the rest will remain the same
        # hence we only set size dynamically
        self.array = []
        self.top = -1

    def display(self):
        # this function prints the stack
        print(self.array[::-1])

    def get_top(self):
        # this gives the value to top at any given point in the program
        print("The value of top is",self.top)

    def push(self, value):
        # this function is used to add values to the stack
        if self.top < self.size - 1:
            self.array.append(value)
            self.top += 1
        else:
            print("The stack is full hence more elements cannot be added")

    def pop(self):
        # this function is responsible for removing values from the stack
        if self.top != -1:
            self.array.remove(self.array[-1])
            self.top -= 1
        else:
            print("The stack is empty hence no elements to remove")

if __name__ == "__main__":
    # making sure the code that runs below only runs in this file
    # in case the file wants to be used as a module
    # this makes it so that one can import the class and use it anywhere 
    Stack1 = Stack(5)
    # creating a stack object
    while(True):
        # Instructions on how to use the program
        checker = int(input("Type 1 to pop an element \nType 2 to push an element \nType 3 to display the array \nType 4 to display the value of top\nType 0 to stop the code\n"))
        if checker == 1:
            Stack1.pop()
        elif checker == 2:
            val = input("Enter the value to be pushed: ")
            Stack1.push(val)
        elif checker == 3:
            Stack1.display()
        elif checker == 4:
            Stack1.get_top()
        elif checker == 0:
            break