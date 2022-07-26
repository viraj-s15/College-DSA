class Stack:

    def __init__(self, stack, size, top):
        self.stack = stack
        self.size = size
        self.top = top

    def pushElement(self, value):
        if len(self.stack) < self.size:
            self.stack.append(value)
            self.top+=1
        elif len(self.stack) >= self.size:
           print("Cannot add more elements to a full stack")

    def popElement(self):
        if (len(self.stack) <= self.size) and len(self.stack) > 0:    
            self.stack.pop()
            self.top-=1

        if len(self.stack) == 0:
            print("Cannot remove element from an empty stack")

    def printStack(self):
        print(self.stack)

    def getTop(self):
        print("The value of the top of the stack is", self.top)
    

if __name__ == "__main__":
    Stack1 = Stack([],4,-1)
    Stack1.pushElement(3)
    Stack1.pushElement(3)
    Stack1.pushElement(3)
    Stack1.pushElement(3)
    Stack1.popElement()
    Stack1.pushElement(3)
    Stack1.getTop()
    Stack1.printStack()



            