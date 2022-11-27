def take_input(array):
	#this function takes input from the user and stores it in the array
    nums = int(input("Enter the number of elements in the array: "))
    for i in range(nums):
        element = int(input())
        array.append(element)


def display(array):
	#this function is responsible for printing the array
    print(array)


def search_element(array):
	#this function is responsible for the linear sort mechanism
    to_be_searched = int(input("Enter the element to be found: "))
    index_of_element = 0
    isFound = False
    for i in range(len(array)):
        if to_be_searched == array[i]:
            index_of_element = i
            isFound = True
            break

    if isFound:
        print("The element has been found at index", index_of_element)
    else:
        print("The element is not present in the array")


if __name__ == "__main__":
    array = []
    take_input(array)
    display(array)
    search_element(array)
