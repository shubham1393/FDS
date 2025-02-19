
# Function to delete duplicate entries from a list
def delete_duplicates(books):
    unique_books = []
    for book in books:
        if book not in unique_books:
            unique_books.append(book)
    return unique_books

# Function to sort books in ascending order based on cost
def sort_books_by_cost(books):
    sorted_books = books[:]  # Create a copy of the original list
    for i in range(len(sorted_books)):
        for j in range(i + 1, len(sorted_books)):
            if sorted_books[i][2] > sorted_books[j][2]:
                sorted_books[i], sorted_books[j] = sorted_books[j], sorted_books[i]
    return sorted_books

# Function to count books with cost more than 500
def count_expensive_books(books):
    count = 0
    for book in books:
        if book[2] > 500:
            count += 1
    return count

# Function to copy books with cost less than 500 to a new list
def copy_cheap_books(books):
    cheap_books = []
    for book in books:
        if book[2] < 500:
            cheap_books.append(book)
    return cheap_books

# Sample data: Each book is represented as a tuple (title, author, cost)
N = int(input("Enter the number of books: "))
library = []
for i in range(N):
    title = input(f"Enter the title of book {i+1}: ")
    author = input(f"Enter the author of book {i+1}: ")
    cost = float(input(f"Enter the cost of book {i+1}: "))
    library.append((title, author, cost))

# Deleting duplicate entries
library = delete_duplicates(library)

# Sorting books by cost in ascending order
sorted_library = sort_books_by_cost(library)

# Counting books with cost more than 500
expensive_count = count_expensive_books(sorted_library)

# Copying books with cost less than 500 to a new list
cheap_library = copy_cheap_books(sorted_library)

# Displaying results
print("\nUnique Books:")
for book in library:
    print(book)

print("\nBooks Sorted by Cost:")
for book in sorted_library:
    print(book)

print("\nNumber of Books with Cost > 500:", expensive_count)

print("\nBooks with Cost < 500:")
for book in cheap_library:
    print(book)

