def takeInput(array):
	#this function takes input from the user and stores it in the array
    nums = int(input("Enter the number of elements in the array: "))
    for i in range(nums):
        element = int(input())
        array.append(element)


def display(array):
	#this function is responsible for printing the array
    print(array)


def searchElement(array):
	#this function is responsible for the linear sort mechanism
    toBeSearched = int(input("Enter the element to be found: "))
    indexOfElement = 0
    isFound = False
    for i in range(len(array)):
        if toBeSearched == array[i]:
            indexOfElement = i
            isFound = True
            break

    if isFound:
        print("The element has been found at index", indexOfElement)
    else:
        print("The element is not present in the array")


if __name__ == "__main__":
    array = []
    takeInput(array)
    display(array)
    searchElement(array)
