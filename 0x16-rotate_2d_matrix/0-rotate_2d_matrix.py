#!/usr/bin/python3
"""Rotate 2D Matrix."""


def rotate_2d_matrix(matrix):
    result = []
    lenArr = len(matrix)
    idx = 0
    for val in matrix:
        idx = 0
        for val2 in val:
            if len(result) < lenArr:
                result.append([])

            result[idx].insert(0, val2)
            idx += 1
    for idx in range(lenArr):
        matrix[idx] = result[idx]
