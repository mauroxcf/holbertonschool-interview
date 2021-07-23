#!/usr/bin/python3
""" This module contain the canUnlockAll method """


def canUnlockAll(boxes):
    """ determines if all the boxes can be opened. """
    unlockeds = [0]
    bx_len = len(boxes)

    if bx_len > 1:
        for j in boxes[0]:
            if j not in unlockeds and j < bx_len and j > 0:
                unlockeds.append(j)
    else:
        return True

    i = 1
    while i < len(unlockeds):
        for j in boxes[unlockeds[i]]:
            if j not in unlockeds and j < bx_len and j > 0:
                unlockeds.append(j)
        i += 1

    if len(unlockeds) == bx_len:
        return True

    return False
