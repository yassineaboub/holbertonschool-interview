#!/usr/bin/python3
"""rain"""


def rain(walls):
    """
    Given a list of non-negative integers
    representing the heights of walls with unit width 1,
    as if viewing the cross-section of a relief map,
    calculate how many square units of water will be retained after it rains.
    """
    left = 0
    total_rain = 0
    while left < len(walls) - 1:

        tallest = right = left + 1
        while right < len(walls) and walls[right] < walls[left]:
            if walls[right] > walls[tallest]:
                tallest = right
            right += 1

        if right == len(walls):
            right = tallest

        inner_wall_heights = sum(walls[left + 1:right])
        base = right - left - 1
        height = min(walls[left], walls[right])
        total_rain += (base * height) - inner_wall_heights

        left = right

    return total_rain
