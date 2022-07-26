def takeInput(array):
    nums = int(input("Enter the number of elements in the array: "))
    for i in range(nums):
        elements = int(input())
        array.append(elements)
    return array

def printArray(array):
    print(array)

def findElement(array, toBeFound):
    notPresent = True
    for i in range(len(array)):
        if (array[i] == toBeFound):
            notPresent = False
            break

    print("The element has been found at index:" , i) if notPresent == False else print("The element is not present in the array")


array1 = []
takeInput(array1)
printArray(array1)
findElement(array1, 40)

