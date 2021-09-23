#!/usr/bin/python3
""" Module validUTF8 """


def validUTF8(data):
    """determines if a given data set represents a valid UTF-8 encoding.
    Args:
        data (list): contain multiple characters
    """
    if len(data) > 32:
        return False

    for i in data:
        if i > 255:
            return False

    return True
