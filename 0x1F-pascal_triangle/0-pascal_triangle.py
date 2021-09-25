#!/usr/bin/python3
"""
Pascal’s triangle of n
"""


def pascal_triangle(n):
    """
    the Pascal’s triangle of n
    """
    if n <= 0:
        return ([])

    t_pascal = []
    i = 1
    while i < n + 1:
        j = i
        k = 0
        level_p = [1]
        while j > 2:
            level_p.append(t_pascal[-1][k] + t_pascal[-1][k + 1])
            j -= 1
            k += 1
        if i > 1:
            level_p.append(1)
        t_pascal.append(level_p)
        i += 1
    return (t_pascal)
