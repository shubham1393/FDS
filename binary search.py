"""
a) Write a Python program to store names and mobile numbers of your friends in sorted order on names. Search your friend
from list using binary search (recursive and non-recursive). Insert friend if not present in phonebook
b) Write a Python program to store names and mobile numbers of your friends in sorted order on names. Search your friend
from list using Fibonacci search. Insert friend if not present in phonebook.
"""


class Search:
    A = []

    def accept_info(A):
        n = int(input("\nNo. of students: "))
        for i in range(n):
            print("\nContact No. ", i + 1, ": ")
            name = input("Name: ")
            mob = input("Mobile No.: ")
            x = [name, mob]
            A.append(x)
        print("Operation Successful\n")
        return n

    def fetch_info(A, n):
        if n == 0:
            print("No records in the database!!")
        else:
            print("\nPhonebook: ")
            for j in range(n):
                swapped = False
                i = 0
                while i < len(A) - 1:
                    if A[i][0] > A[i + 1][0]:
                        A[i], A[i + 1] = A[i + 1], A[i]
                        swapped = True
                    i = i + 1
                if not swapped:
                    break
            print("Contact No.\t\tName\tContact No.")
            for i in range(n):
                print("\t", i + 1, "\t\t\t", A[i][0], "\t\t", A[i][1])

    def binary_search_iterative(A, x):
        Low = 0
        High = n - 1
        while Low <= High:
            mid = (Low + High) // 2
            if A[mid][0] < x:
                Low = mid + 1
            if A[mid][0] > x:
                High = mid - 1
            if A[mid][0] == x:
                return mid
        return -1

    def binary_search_recursive(A, x, High, Low):
        if Low < High:
            mid = (High + Low) // 2
            if A[mid][0] > x:
                return Search.binary_search_recursive(A, x, mid, Low)
            if A[mid][0] < x:
                return Search.binary_search_recursive(A, x, High, mid)
            else:
                return mid
        return -1

    def fibonacci_search(A, n, x):
        f1 = 0
        f2 = 1
        f3 = f1 + f2
        offset = -1
        while f3 < n:
            f1 = f2
            f2 = f3
            f3 = f1 + f2
        while f3 > 1:
            i = min(offset + f1, n - 1)
            if A[i][0] == x:
                return i
            else:
                if x < A[i][0]:
                    f3 = f1
                    f2 = f2 - f1
                    f1 = f3 - f2
                else:
                    f3 = f2
                    f2 = f1
                    f1 = f3 - f2
                    offset = i
        if f2 == 1 and (offset + 1) < n and A[offset + 1][0] == x:
            return offset + 1
        return -1

    def insert_new(A, n, name):
        mob = input("Contact No.: ")
        x = [name, mob]
        A.append(x)
        j = n - 1
        while j >= 0:
            if A[j][0] <= name:
                break
            else:
                A[j + 1] = A[j]
            j = j - 1
        A[j + 1] = x
        print("Operation Successful!!!")
        Search.fetch_info(A, n + 1)


if __name__ == "__main__":
    A = []
    print("1. Create Database\n2. Binary Search (Non-Recursive)\n3. Binary Search (Recursive)\n4. Fibonacci "
          "Search\n5. Exit")
    while True:
        ch = int(input("\nChoice: "))
        if ch == 1:
            A = []
            n = Search.accept_info(A)
            Search.fetch_info(A, n)
        elif ch == 2:
            x = input("Enter Name: ")
            response = Search.binary_search_iterative(A, x)
            if response == -1:
                print("\033[91mNot Found!!!\033[0m")
                perm = input("Add to the phonebook (y/n) ?!")
                if perm.lower() == "y":
                    Search.insert_new(A, n, x)
                    n = n + 1
                else:
                    continue
            else:
                print("\033[32mAvailable!!!\033[0m\nName: ", x, "\nContact No.: ", A[response][1], "\nLocation: ",
                      response + 1)
        elif ch == 3:
            x = input("Enter Name: ")
            response = Search.binary_search_recursive(A, x, n, 0)
            if response == -1:
                print("\033[31mNot Found!!!\033[0m")
                perm = input("Add to the phonebook (y/n) ?!")
                if perm.lower() == "y":
                    Search.insert_new(A, n, x)
                    n = n + 1
                else:
                    continue
            else:
                print("\033[32mAvailable!!!\033[0m\nName: ", x, "\nContact No.: ", A[response][1], "\nLocation: ",
                      response + 1)
        elif ch == 4:
            x = input("Enter Name: ")
            response = Search.fibonacci_search(A, n, x)
            if response == -1:
                print("\033[31mNot Found!!!\033[0m")
                perm = input("Add to the phonebook (y/n) ?!")
                if perm.lower() == "y":
                    Search.insert_new(A, n, x)
                    n = n + 1
                else:
                    continue
            else:
                print("\033[32mAvailable!!!\033[0m\nName: ", x, "\nContact No.: ", A[response][1], "\nLocation: ",
                      response + 1)
        elif ch == 5:
            print("Exiting!!!")
            exit(0)
        else:
            print("\033[91mWrong Choice!!!\033[0m")


