#!/usr/bin/python3
"""Pascal's Triangle"""


def pascal_triangle(n):
    """return a list of lists of integers representing
    the Pascal’s triangle of n"""

    data = []

    if n <= 0:
        return data
    else:
        for i in range(n):
            row = [1]
            for j in range(i):
                row.append(sum(data[-1][j:j+2]))
            data.append(row)
        return data
