#!/usr/bin/python3

"""puzzle is the challenge of placing N non-attacking
queens on an NN chessboard. Write a program that
solves the N queens problem
"""
import sys


def nqueens(q, row, queens):

    for col in range(q):
        flag = 0

        for queen in queens:

            if abs(col - queen[1]) == abs(row - queen[0]):
                flag = 1
                break

            if col == queen[1]:
                flag = 1
                break

        if flag == 0:
            queens.append([row, col])

            if row != q - 1:
                nqueens(q, row + 1, queens)

            else:
                print(queens)

            queens.pop()


if __name__ == "__main__":
    """call function and receive args"""

    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        exit(1)

    if sys.argv[1].isdigit() is False:
        print("N must be a number")
        exit(1)

    q = int(sys.argv[1])

    if q < 4:
        print("N must be at least 4")
        exit(1)

    queens = []
    row = 0
    nqueens(q, row, queens)
