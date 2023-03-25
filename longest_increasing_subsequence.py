# Longest Increasing subsequence

from typing import List


def longest_increasing_subsequence(array: List[int]):
    table = [-1] * len(array)
    for i in range(1, len(table)):
        sub_array = [table[k] for k in range(i) if array[k] < array[i]]
        table[i] = 1 + max(sub_array, default=0)
    return max(table, default=0)


def main():
    array = []
    n = int(input("Enter the number of elements in the array: "))
    for i in range(n):
        element = int(input(f"Enter element number {i}: "))
        array.append(element)

    result = longest_increasing_subsequence(array)
    print(f"The length of the longest increasing subsequence is: {result}")


if __name__ == "__main__":
    main()
