#!/usr/bin/python3
"""
UTF-8 Validation
"""


def validUTF8(data):
    """
    method that determines if a given data
    set represents a valid UTF-8 encoding
    """

    count = 0
    n = 1 << 7
    i = 1 << 6
    for num in data:
        n = 1 << 7
        if count == 0:
            while n & num:
                count += 1
                n = n >> 1
            if count == 0:
                continue
            if count == 1 or count > 4:
                return False
        else:
            if not (num & n and not (num & i)):
                return False
        count -= 1
    return count == 0
