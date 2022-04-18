#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

void print_array(const int *array, size_t size);
void heap_sort(int *array, size_t size);
void heapify_array(int *arr, size_t size);
void shakedown(int *arr, size_t start, size_t end, size_t size);
void swap(int *a, int *b, size_t size, int *arr);

#endif /* SORT_H */
