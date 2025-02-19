"""
Write a Python program to store first year percentage of students in array. Write function for sorting array of
floating point numbers in ascending order using
a) Selection Sort
b) Bubble sort and display top five scores.
"""


class Sort:
    def selection_sort(_marks):
        for i in range(len(_marks)):
            min_id = i
            for j in range(i + 1, len(_marks)):
                if _marks[min_id] > _marks[j]:
                    min_id = j
            _marks[i], _marks[min_id] = _marks[min_id], _marks[i]
        print("Sorted Scorers: ")
        for i in range(len(marks)):
            print(marks[i])

    def bubble_sort(_marks):
        no = len(_marks)
        for i in range(no - 1):
            for j in range(0, no - i - 1):
                if _marks[j] > _marks[j + 1]:
                    _marks[j], _marks[j + 1] = _marks[j + 1], _marks[j]
        print("Sorted Scorers: ")
        for i in range(len(marks)):
            print(marks[i])

    def top_scorers(_marks):
        for i in range(len(_marks) - 1):
            for j in range(0, len(_marks) - i - 1):
                if _marks[j] > _marks[j + 1]:
                    _marks[j], _marks[j + 1] = _marks[j + 1], _marks[j]
        print("Top five scorers: ")
        print(*marks[4::-1], sep="\n")


if __name__ == '__main__':
    marks = []
    n = int(input("No. of students: "))
    print("Enter Marks: ")
    for i in range(0, n):
        ele = float(input())
        marks.append(ele)  # adding the element
    print("Marks: ")
    print(marks)
    print(
        "\n---------------MENU---------------\n1. Selection Sort of Marks\n2. Bubble Sort of Marks\n3. Fetch top five scorers\n4. Exit")
    while True:
        ch = int(input("\nChoice: "))
        if ch == 1:
            Sort.selection_sort(marks)
        elif ch == 2:
            Sort.bubble_sort(marks)
        elif ch == 3:
            Sort.top_scorers(marks)
        elif ch == 4:
            print("Exiting...")
            break
        else:
            print("NOT VALID!!!")


