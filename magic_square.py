#Write a Python Program for magic square. A magic square is an n * n matrix of the integers 1 to n2 #such that the sum of each row, column, and diagonal is the same. The figure given below is an #example of magic square for case n=5. In this example, the common sum is 65. (in Python without #using built-in methods for major functionality of assignment)

class MagicSquare:
    def generateSquare(self, n):
        magicSquare = [[0 for x in range(n)]
                       for y in range(n)]

        i = n // 2
        j = n - 1

        num = 1
        while num <= (n * n):
            if i == -1 and j == n:
                j = n - 2
                i = 0
            else:
                if j == n:
                    j = 0
                if i < 0:
                    i = n - 1

            if magicSquare[i][j]:
                j = j - 2
                i = i + 1
                continue
            else:
                magicSquare[i][j] = num
                num = num + 1

            j = j + 1
            i = i - 1

        print("Magic Square for n =", n)
        print("Sum of each row or column",
              n * (n * n + 1) // 2, "\n")

        for i in range(0, n):
            for j in range(0, n):
                print('%2d ' % (magicSquare[i][j]), end='')

                if j == n - 1:
                    print()

    def get_odd_number(self):
        n = int(input("Enter any odd number: "))
        while n % 2 == 0:
            n = int(input("Entered number was even. Please enter an odd number: "))
        return n


if __name__ == "__main__":
    sq = MagicSquare()
    n = sq.get_odd_number()
    sq.generateSquare(n)
