
class Stack:
# making the stack class in which the operation takes place
    def __init__(self, size: int):
        # giving it attributes including the typing
        self.size = size
        self.top = -1
        self.array = []
        self.result = []
        self.order = {'+':1, '-':1, '*':2, '/':2, '^': 3}
    
    def pop(self) -> str: 
        # the function responsible for removing the last element from the stack 
        if self.top == -1:
            return "The stack is empty hence nothing to pop"
        else:
            self.top -= 1
            return self.array.pop()

    def push(self, value: chr) -> str:
        # the function responsible for adding an element from the stack 
        if len(self.array) < self.size:
            self.top += 1
            self.array.append(value)
            print("The value that is pushed is:" , value)
        else:
            return "The array cannot exceed its size, hence element cannot be added"

    def is_empty(self) -> bool:
        # the function responsible for checking whether the stack is empty  
        return True if self.top == -1 else False

    def get_last_element(self) -> str:
        # the function responsible for getting the last element  
        return self.array[-1] if self.top != -1 else "There are no elements in the stack"

    def get_top(self) -> str:
        # the function responsible for getting the value of top at any given time  
        return self.top
    
    def display(self):
        # the function responsible for displaying the stack at any given time  
        return self.array[::-1] if self.is_empty() else "There are no elements in the stack"

    def is_greater(self, value: chr) -> bool:
        # the function responsible for comparing the priorities of the operators in the expression  
        try:
            char1 = self.order[value]
            char2 = self.order[self.get_last_element()]
            return True if char1 >= char2 else False
        except KeyError:
            return None
        
    def infix_to_postfix(self,expression: str) -> str:
        for i in expression:
            # looping through the expression
            if i.isalpha():
                # to check whether the character is an operand or not
                self.result.append(i)

            elif i == "(":
                # to check whether the character is an opening bracket
                self.push(i)
            
            elif i == ')':
                # to check whether the character is an closing bracket
                while(not self.is_empty() and self.get_last_element() != '('):
                    # we need to remove all elements in the bracket i.e. remove the elements till u reach the
                    # opening bracket
                    popped_element = self.pop()
                    print("The popped element is: " , popped_element)
                    self.result.append(popped_element)

            else: 
                self.pop() # removing the opening bracket
                while(not self.is_empty() and not self.is_greater(i)):
                    if i == "^" and self.get_last_element() == i:
                        # dealing with right associative operators
                        break
                    self.result.append(self.pop())
                self.push(i)
        
        while not self.is_empty():
            # appending whatever is left in the stack to the final result
            self.result.append(self.pop())    

        return "".join(self.result)
                    
                    
if __name__ == "__main__":                   
    expression = str(input("Enter the expression to be converted from infix to postfix: \n"))
    Stack1 = Stack(len(expression))
    print(Stack1.infix_to_postfix(expression))
                
                
                
            
                
            
            
        
    
    
    

