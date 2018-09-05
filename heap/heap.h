#ifndef _HEAP_H_
#define _HEAP_H_

#define MAX_HEAP_SIZE 100 

typedef struct _heap
{
    int element[MAX_HEAP_SIZE];
    int size;
}Heap;

typedef Heap* heap_ptr;

void max_heapify(heap_ptr heap, int index);
void heapify_up(heap_ptr heap, int index);
Heap build_max_heap(int *arr, int size);
int* heap_sort(int* arr, int size);
void insert(heap_ptr heap, int val);
int extract_max(heap_ptr heap);
void print(int* arr, int size);

#endif