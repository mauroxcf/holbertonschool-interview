#!/usr/bin/python3
""" This module contain the canUnlockAll method """


def canUnlockAll(boxes):
    """ determines if all the boxes can be opened. """
    all_keys = boxes[0]
    open_boxes = [0]
    i = 1

    while i < len(boxes):
        if i in all_keys:
            if i not in open_boxes:
                for key in boxes[i]:
                    all_keys.append(key)
                open_boxes.append(i)
                i = 0
        i += 1

    if len(open_boxes) == len(boxes):
        return True
    else:
        return False
