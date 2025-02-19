"""
Write a Python program to store second year percentage of students in array. Write function for sorting array of
floating point numbers in ascending order using
a) Insertion sort
b) Shell Sort and display top five scores
"""


class Sort:
    def insertion_sort(arr, n):
        for i in range(1,len(arr)):
            temp = arr[i]
            j = i - 1
            while (j >= 0) & (arr[j] > temp):
                arr[j + 1] = arr[j]
                j = j - 1
            arr[j + 1] = temp
        print(arr)
        scrs = arr[-5:]
        print("\nTop Five Scores")
        for i in range(len(scrs) - 1, -1, -1):
            print(scrs[i])

    def shell_sort(arr, n):
        d = n // 2
        while d > 0:
            for i in range(d, n):
                temp = arr[i]
                j = i
                while j >= d and arr[j - d] > temp:
                    arr[j] = arr[j - d]
                    j -= d
                arr[j] = temp
            d = d // 2
        print(arr)
        scrs = arr[-5:]
        print("Top Five Scores")
        for i in range(len(scrs) - 1, -1, -1):
            print(scrs[i])


if __name__ == "__main__":
    n = int(input("No. of students: "))
    array = []
    print("Enter Percentage: ")
    for i in range(n):
        item = float(input())
        array.append(item)

    print("Score Preview:")
    print(array)
    print("\nMain Menu\n1. Insertion Sort\n2. Shell Sort\n3. Exit")
    while True:
        ch = int(input("Choice: "))
        if ch == 1:
            print("Sorted Scores: ")
            Sort.insertion_sort(array, n)
        elif ch == 2:
            print("Sorted Scores: ")
            Sort.shell_sort(array, n)
        else:
            print("Exiting...")
            break


