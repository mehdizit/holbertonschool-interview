#!/usr/bin/python3
"""
You have n number of locked boxes in front of you
Each box is numbered sequentially from 0 to n - 1
and each box may contain keys to the other boxes
"""


def canUnlockAll(boxes):
    """Write a method that determines if all the boxes can be opened"""
    pocket = [0]
    for key in pocket:
        for key_box in boxes[key]:
            if key_box not in pocket:
                if key_box < len(boxes):
                    pocket.append(key_box)
    if len(pocket) == len(boxes):
        return True
    return False
