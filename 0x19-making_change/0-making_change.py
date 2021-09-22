#!/usr/bin/python3
"""making change."""


def makeChange(coins, total):
    """Given a pile of coins of different values, determine the fewest number
            of coins needed to meet a given amount total
    """

    if total <= 0:
        return 0

    # verify coins is a valid
    if (coins is None or len(coins) == 0):
        return -1

    x = 0
    mc = sorted(coins, reverse=True)
    ml = total

    for coin in mc:
        while (ml % coin >= 0 and ml >= coin):
            x += int(ml / coin)
            ml = ml % coin

    x = x if ml == 0 else -1

    return x
