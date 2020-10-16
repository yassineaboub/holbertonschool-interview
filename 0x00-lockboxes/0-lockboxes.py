#!/usr/bin/python3
def canUnlockAll(boxes):
    k = [0]
    for i in k:
        for n in boxes[i]:
            if n not in k and n > 0:
                k.append(n)
    if len(k) == len(boxes):
        return True
    else:
        return False
