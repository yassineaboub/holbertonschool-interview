#!/usr/bin/python3
"""Minimum Operations"""

def minOperations(n):
    """ 
    Function that returns the minimum number of operations to be performed
    """
    if n <= 1:
        return 0
    count = 0
    j = 2
    while (n > 1):
        if (n % j == 0):
            n //= j
            count += j
            j = 1
        j += 1
    return count
